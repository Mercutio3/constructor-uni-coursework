/*
CH-230-A
a7_p7.c
Santiago Dominguez
22 October 2022
Runs stack implementation, uses switch statement to execute features
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    //Initialize stack and variables
    struct stack intStack;
    intStack.count = -1;
    char command;
    int readInt;

    while(1){
        //Get user input for command
        scanf("%c", &command);
        getchar();
        switch(command){
            case 's':
                //Scan int to be pushed, call push function
                scanf("%d", &readInt);
                getchar();
                push(&intStack, readInt);
                break;
            case 'p':
                //Call pop function
                pop(&intStack);
                break;
            case 'e':
                //Call empty function
                empty(&intStack);
                break;
            case 'q':
                //Quit program
                printf("Quit\n");
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}