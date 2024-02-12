#include <stdio.h>
#include "quiz.h"
#include "play.c"

int main(){
    //Initialize quiz data structre and its integer attributes
    quiz_t *csQuiz;
    csQuiz->n = 0;
    csQuiz->score = 0;
    csQuiz->max = 0;

    printf("Answer multiple choice questions about computer science.\n");
    printf("You score points for each correctly answered question.\n");
    printf("If you need multiple attempts to answer a question, the\n");
    printf("points you score for a correct answer go down.\n");

    //Repeatedly ask questions until the user ends the standard input (CTRL + D)
    while(1){
        if(play(csQuiz) == 2){
            break;
        }
    }

    //Print final score
    printf("Thanks for playing today.\n");
    printf("Your final score is %d/%d points.\n", csQuiz->score, csQuiz->max);

    return 0;
}