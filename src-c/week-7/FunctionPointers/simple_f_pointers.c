/*
CH-230-A
a7_p4.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUpper(char readString[]);
void printLower(char readString[]);
void swapCaps(char string[]);
void quitProgram(char readString[]);

void (*stringFunc[4]) (char readString[]);

int main() {
    char line[100];
    int read;
    fgets(line, sizeof(line), stdin);

    stringFunc[0] = printUpper;
    stringFunc[1] = printLower;
    stringFunc[2] = swapCaps;
    stringFunc[3] = quitProgram;

    while(1){
        scanf("%d",&read);
        getchar();
        
        (*stringFunc[read-1]) (line);
    }

    return 0;
}

void printUpper(char readString[]){
    char string[100];
    strcpy(string, readString);
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'a' && string[i] <= 'z'){
            string[i] = string[i] - 32;
        }
    }
    printf("%s", string);
}

void printLower(char readString[]){
    char string[100];
    strcpy(string, readString);
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
    }
    printf("%s", string);
}

void swapCaps(char readString[]){
    char string[100];
    strcpy(string, readString);
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'a' && string[i] <= 'z'){
            string[i] = string[i] - 32;
        } else if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
    }
    printf("%s", string);
}

void quitProgram(char readString[]){
    exit(0);
}