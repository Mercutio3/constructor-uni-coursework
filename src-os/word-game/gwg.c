#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "player.h"

int main(void){
    //Initialize player, message, and rc variable, check if valid player
    player_t *p;
    char *msg;
    int rc;
    p = player_new();
    if (!p) {
        return EXIT_FAILURE;
    }

    //Get greeting and print it on standard output, free msg and reset it to NULL
    rc = player_get_greeting(p, &msg);
    if (rc == 0) {
        (void) fputs(msg, stdout);
        free(msg);
        msg = NULL;
    }

    //Mainloop
    while (!(p->finished)) {
        char *line = NULL;
        size_t linecap = 0;

        //Obtain challenge message, print it on standard output
        rc = player_get_challenge(p, &msg);
        if (rc == 0) {
            (void)fputs(msg, stdout);
            free(msg);
        } else {
            fprintf(stderr, "Error getting challenge.\n");
            break;
        }

        if (getline(&line, &linecap, stdin) <= 0) {
            printf("fonfi\n");
            rc = player_post_challenge(p, "Q:", &msg);
            if (rc == 0) {
                (void)fputs(msg, stdout);
                free(msg); // Free the message obtained from player_post_challenge
            }
            break;
        }

        //Process user input, print returned message to standard output
        rc = player_post_challenge(p, line, &msg);
        if (rc == 0) {
            (void)fputs(msg, stdout);
            free(msg);
        }
        free(line);
    }
    
    player_del(p); //Delete player
    
    return EXIT_SUCCESS;
}