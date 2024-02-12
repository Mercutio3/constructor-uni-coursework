#include <stdio.h>
#include <string.h>
#include "quiz.h"
#include "fetch.c"
#include "parse.c"

extern int play(quiz_t *quiz){
    //Fetch JSON file from URL, then parse it
    char *url = fetch("https://opentdb.com/api.php?amount=1&category=18&type=multiple");
    parse(quiz, url);

    //Print question and choices
    printf("\n%s\n\n", quiz->question);
    printf("[a] %s\n", quiz->choices[0]);
    printf("[b] %s\n", quiz->choices[1]);
    printf("[c] %s\n", quiz->choices[2]);
    printf("[d] %s\n\n", quiz->choices[3]);

    int points = 8; //Initial possible points a right answer can give
    int correct = 0; //Boolean flag switches to 1 if answer is correct
    char answer;
    
    while(points >= 1){
        //Print answer prompt, read character, break loop if user ends standard input (CTRL + D)
        printf("(%dpt) > ", points);
        if(scanf(" %c", &answer) == EOF){
            break;
        }
        //Check if player's answer was correct
        switch(answer){
            case 'a':
                if(strcmp(quiz->choices[0], quiz->answer) == 0){
                    correct = 1;
                }
                break;
            case 'b':
                if(strcmp(quiz->choices[1], quiz->answer) == 0){
                    correct = 1;
                }
                break;
            case 'c':
                if(strcmp(quiz->choices[2], quiz->answer) == 0){
                    correct = 1;
                }
                break;
            case 'd':
                if(strcmp(quiz->choices[3], quiz->answer) == 0){
                    correct = 1;
                }
                break;
            default:
                correct = 0;
                break;
        }
        if(correct){
            //Print score, exit loop
            printf("Congratulation, answer [%c] is correct. Your current score is ", answer);
            quiz->score += points;
            printf("%d/%d points.\n", quiz->score, quiz->max);
            break;
        } else {
            //Reduce possible points for correct answer
            printf("Answer [%c] is wrong, try again.\n", answer);
            points /= 2;
        }
    }

    //If user ends the standard input (CTRL + D), return code to finish quiz.
    if(feof(stdin)){
        printf("\nYour current score is %d/%d points.\n\n", quiz->score, quiz->max);
        return 2;
    } else if(ferror(stdin)){
        perror("Input reading error.");
        return -1;
    }

    return 0;
}