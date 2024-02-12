/*
CH-230-A
a5_p7.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char stringOne[100];
    char stringTwo[100];
    fgets(stringOne, sizeof(stringOne), stdin);
    fgets(stringTwo, sizeof(stringTwo), stdin);
    stringOne[strcspn(stringOne, "\n")] = 0;
    stringTwo[strcspn(stringTwo, "\n")] = 0;

    int concatLength = strlen(stringOne) + strlen(stringTwo);
    char *concatStr;

    concatStr = (char *) malloc(sizeof(char) * concatLength);
    if(concatStr == NULL){
        exit(1);
    }

    strcat(stringOne, stringTwo);

    printf("Result of concatenation: %s\n", stringOne);

    free(concatStr);

    return 0;
}