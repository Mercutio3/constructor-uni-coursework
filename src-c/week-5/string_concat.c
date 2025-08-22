/*
CH-230-A
a5_p7.c
Santiago Dominguez
4 October 2022
Concatenates two strings, dynamically allocating the result string
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE 100 // Size of static strings

int main(){
    //Initialize two strings and read user input
    char stringOne[STRING_SIZE];
    char stringTwo[STRING_SIZE];
    fgets(stringOne, sizeof(stringOne), stdin);
    fgets(stringTwo, sizeof(stringTwo), stdin);
    stringOne[strcspn(stringOne, "\n")] = 0;
    stringTwo[strcspn(stringTwo, "\n")] = 0;

    //Determine length of concatenated string, allocate memory
    int concatLength = strlen(stringOne) + strlen(stringTwo);
    char *concatStr;
    concatStr = (char *) malloc(sizeof(char) * concatLength);
    if(concatStr == NULL){
        exit(1);
    }

    //Concatenate strings and print result
    strcat(stringOne, stringTwo);
    printf("Result of concatenation: %s\n", stringOne);

    free(concatStr);

    return 0;
}