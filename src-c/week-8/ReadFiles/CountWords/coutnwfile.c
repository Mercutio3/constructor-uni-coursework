/*
CH-230-A
a8_p8.c
Santiago Dominguez
25 October 2022
Reads "words.txt" file and counts how many words use special characters
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    //Create file pointer for the file
    FILE *readFile;
    readFile = fopen("words.txt", "r");
    if(readFile == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Initialize variables and flags
    char read;
    int wordCount = 0;
    bool charRep = false;

    //Count words in file using special characters
    //Repeated special chars dont count as multiple words
    while((read = fgetc(readFile)) != EOF){
        if(read == ' ' || read == ',' || read == '?' || read == '!' || read == '.' || read == '\t' || read == '\r' || read == '\n'){
            if(charRep == false){
                wordCount++;
                charRep = true;
            }
        } else {
            charRep = false;
        }
    }
    
    //Close file and print result
    fclose(readFile);
    printf("The file contains %d words.\n", wordCount);
    
    return 0;
}