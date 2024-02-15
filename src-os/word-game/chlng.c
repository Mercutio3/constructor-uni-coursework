#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "chlng.h"

int maxTextLength = 256;

chlng_t* chlng_new(void){
    chlng_t *challenge = (chlng_t*)malloc(sizeof(chlng_t));
    if(challenge == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    challenge->text = NULL;
    challenge->word = NULL;

    return challenge;
}

//Reset internal state of challenge
void chlng_reset(chlng_t *chal){
    free(chal->text);
    free(chal->word);
    chal->text = NULL;
    chal->word = NULL;
}

//Delete challenge and all its resources
void chlng_del(chlng_t *chal){
    free(chal->text);
    free(chal->word);
    free(chal);
}

//Fetch new text from an invocation of 'fortune'
int chlng_fetch_text(chlng_t *c){
    FILE *fp;
    char buffer[maxTextLength];
    
    //Open child process, read result of "fortune" with pipe
    fp = popen("fortune -s", "r");
    if(fp == NULL){
        perror("popen");
        return -1;
    }

    if(fgets(buffer, maxTextLength, fp) == NULL){
        perror("fgets");
        pclose(fp);
        return -1;
    }

    pclose(fp);

    c->text = strdup(buffer);
    if(c->text == NULL){
        perror("strdup");
        return -1;
    }

    return EXIT_SUCCESS;
}

//Select and hide a word in the text
int chlng_hide_word(chlng_t *c){
    //Initialize randon number
    srand((unsigned int)time(NULL));

    //Create temporary copy of text for manipulation
    char *tempText = strdup(c->text);
    if(tempText == NULL){
        perror("strdup");
        return -1;
    }

    char *word = strtok(tempText, " \t\n");
    char *words[maxTextLength];
    size_t wordCount = 0;
    while(word != NULL && wordCount < maxTextLength){
        words[wordCount++] = word;
        word = strtok(NULL, " \t\n");
    }

    //Return error code if text is empty
    if(wordCount == 0){
        fprintf(stderr, "Text is empty.");
        free(tempText);
        return -1;
    }

    //Chose a random word and determine its length
    size_t randomIndex = rand() % wordCount;
    char *chosenWord = words[randomIndex];
    size_t chosenWordLength = strlen(chosenWord);

    //Allocate memory for hidden word dynamically
    char *hiddenWord = (char *)malloc(chosenWordLength + 1);
    if (hiddenWord == NULL) {
        perror("malloc");
        free(tempText);
        return -1;
    }

    //Replace hidden word with underscores, replace challenge's word
    memset(hiddenWord, '_', chosenWordLength);
    hiddenWord[chosenWordLength] = '\0';
    free(c->word);
    c->word = strdup(chosenWord);

    //Insert hidden word into text
    char *position = strstr(c->text, chosenWord);
    if(position != NULL){
        memcpy(position, hiddenWord, chosenWordLength);
    }

    //Free memory
    free(hiddenWord);
    free(tempText);
    
    return EXIT_SUCCESS;
}