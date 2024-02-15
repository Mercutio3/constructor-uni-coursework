#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "player.h"

// Function to remove leading and trailing whitespaces
char* trim(char *str) {
    size_t prefix_len = strlen("R: ");
    if (strncmp(str, "R: ", prefix_len) == 0) {
        str += prefix_len;  // Skip the "R: " prefix
    }

    size_t len = strlen(str);

    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        len--;
    }

    if (len == 0) {
        return str;
    }

    str[len] = '\0';

    return str;
}

player_t* player_new(void){
    player_t *player = (player_t*)malloc(sizeof(player_t));
    if(player == NULL){
        perror("Error creating player.");
        exit(EXIT_FAILURE);
    }

    player->solved = 0;
    player->total = 0;
    player->finished = false;
    player->chlng = chlng_new();

    return player;
}

void player_reset(player_t* p){
    p->solved = 0;
    p->total = 0;
    p->finished = false;
    chlng_reset(p->chlng);
}

void player_del(player_t* p){
    chlng_del(p->chlng);
    free(p);
}

int player_fetch_chlng(player_t* p){
    if(chlng_fetch_text(p->chlng) == 0){
        p->total++;
        return chlng_hide_word(p->chlng);
    }
    return -1;
}

int player_get_greeting(player_t* p, char ** msg){
    *msg = strdup("M: Guess the missing ____!\nM: Send your guess in the form 'R: word\\r\\n'.\n");
    if(*msg == NULL){
        perror("Strdup error");
        return -1;
    }
    return EXIT_SUCCESS;
}

int player_get_challenge(player_t* p, char ** msg){
    if(p->finished){
        *msg = strdup("M: You mastered challenges. Good bye!\n");
        if(*msg == NULL){
            perror("Strdup error");
            return -1;
        }
        return EXIT_SUCCESS;
    }

    if(player_fetch_chlng(p) == 0){
        char buffer[256];
        snprintf(buffer, 256, "C: %s", p->chlng->text);
        *msg = strdup(buffer);
        if(*msg == NULL){
            perror("Strdup error");
            return -1;
        }
        return EXIT_SUCCESS;
    }

    return -1;
}

int player_post_challenge(player_t* p, char *response, char **msg){
    if(strncmp(response, "Q: ", 2) == 0){
        p->finished = true;
        //Determine message size, store it in *msg
        int msg_size = snprintf(NULL, 0, "M: You mastered %d/%d challenges. Goodbye!\n", p->solved, p->total);
        *msg = (char *)malloc(msg_size + 1);
        if (*msg == NULL) {
            perror("malloc");
            return -1;
        }
        snprintf(*msg, msg_size + 1, "M: You mastered %d/%d challenges. Goodbye!\n", p->solved, p->total);
        
        return EXIT_SUCCESS;
    }

    if (p->chlng == NULL || p->chlng->word == NULL) {
        fprintf(stderr, "Error: Invalid challenge or word.\n");
        return -1;
    }

    p->total++;

    if(strncmp(response, "R: ", 3) == 0){
        // Trim both the correct answer and the user's input
        char *trimmedResponse = trim(response);
        char *trimmedCorrectAnswer = trim(p->chlng->word);

        if(strcmp(trimmedResponse, trimmedCorrectAnswer) == 0){
            p->solved++;
            *msg = strdup("O: Congratulations - challenge passed!\n");
            if(*msg == NULL){
                perror("Strdup error.");
                return -1;
            }   
        } else {
            size_t message_len = strlen("F: Wrong guess - expected ''") + strlen(p->chlng->word) + 2;
            *msg = (char *)malloc(message_len);
            if(*msg == NULL){
                perror("malloc error.");
                return -1;
            }
            snprintf(*msg, message_len, "F: Wrong guess - expected '%s'\n", p->chlng->word);
        }
    } else {
        *msg = strdup("M: Invalid format. Send your guess in the form 'R: word\\r\\n'.\n");
        if(*msg == NULL){
            perror("strdup error.");
            return -1;
        }
    }
    
    return EXIT_SUCCESS;
}