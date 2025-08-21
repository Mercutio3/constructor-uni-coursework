/*
CH-230-A
a4_p12.c 
Santiago Dominguez
30 September 2022
Replaces all instances of a read character in a read string with another read character
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void replaceAll(char *str, char c, char e);

int main(){
    while(true){
        //Initialize variables and read user input
        char readString[80];
        char replacedChar;
        char newChar;

        printf("Input string:\n");
        fgets(readString, sizeof(readString), stdin);
        readString[strcspn(readString, "\n")] = 0;
        
        if(strcmp(readString, "stop") == 0){
            break;
        }

        printf("Enter character to be replaced and replacing character:\n");
        scanf("%c\n",&replacedChar);
        scanf("%c", &newChar);
        getchar();

        //Print information and call replaceAll
        printf("Character to be replaced: %c\n", replacedChar);
        printf("Replacing character: %c\n", newChar);
        printf("String before replacement: %s\n", readString);
        
        replaceAll(readString, replacedChar, newChar);

        printf("String after replacement: %s\n", readString);

    }

    return 0;
}

void replaceAll(char *str, char c, char e){
    //Search for c in str and replace with e
    int length = strlen(str);

    for(int i = 0; i < length; i++){
        if(str[i] == c){
            str[i] = e;
        }
    }
}