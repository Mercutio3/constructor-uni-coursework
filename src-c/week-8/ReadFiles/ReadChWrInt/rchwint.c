/*
CH-230-A
a8_p5.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Create file pointer for reading file
    FILE *filePtr;
    filePtr = fopen("chars.txt", "r");
    if(filePtr == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Read characters, close reading file after ceasing operations
    int char1 = getc(filePtr);
    int char2 = getc(filePtr);
    fclose(filePtr);

    //Create file pointer for writing file
    FILE *outputPtr;
    outputPtr = fopen("codesum.txt", "w");
    if(outputPtr == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Write sum of chars on file, close writing file
    fprintf(outputPtr,"%d", char1+char2);
    fclose(outputPtr);

    return 0;
}