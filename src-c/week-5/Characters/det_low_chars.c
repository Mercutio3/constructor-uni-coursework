/*
CH-230-A
a5_p3.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>

int count_lower(char* str);

int main() {
    while(1){
        //Initialize array, read user input
        printf("Enter string:\n");
        char line[50];
        fgets(line, sizeof(line), stdin);

        //Terminate program if string is empty
        if(line[0] == '\n'){
            break;
        }

        printf("Number of lowercase characters: %d\n", count_lower(line));
        printf("————————————————————\n");
    }

    return 0;
}

int count_lower(char* str){
    int lowerCount = 0;

    char *ptr = str;

    //Count lowercase characters, using pointer to loop through array
    while(*ptr != '\0') {
        if(*ptr >= 97 && *ptr <= 122){
            lowerCount++;
        }
        ptr++;
    }

    return lowerCount;
}