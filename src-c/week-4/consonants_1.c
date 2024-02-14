/*
CH-230-A
a4_p4.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int count_consonants(char string[]);

int main() {
    while(true){
        //Read string
        char string[100];
        fgets(string,sizeof(string),stdin);
        
        //Remove \n character from string
        string[strcspn(string, "\n")] = 0;

        //Break out of loop if empty string is introduced
        if(strlen(string) == 0){
            break;
        }

        printf("Number of consonants=%d\n", count_consonants(string));
    }

    return 0;
}

int count_consonants(char string[]){
    int consCount = 0;
    //Compare to a list of ASCII consonant values
    for(int i = 0; i < strlen(string); i++){
        int read = string[i];
        int consonant[] = {66,67,68,70,71,72,74,75,76,77,78,80,81,82,83,84,86,87,88,89,90,98,99,100,102,103,104,106,107,108,109,110,112,113,114,115,116,118,119,120,121,122};
        for(int j=0; j < 42; j++){
            if(read == consonant[j]){
                consCount++;
                break;
            }
        }
    }
    return consCount;
}