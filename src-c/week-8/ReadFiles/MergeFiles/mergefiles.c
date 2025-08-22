/*
CH-230-A
a8_p7.c
Santiago Dominguez
25 October 2022
Concatenates "text1.txt" and "text2.txt", writes result to "merge12.txt"
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Create file pointer for the three files
    FILE *fileOne;
    fileOne = fopen("text1.txt", "r");
    FILE *fileTwo;
    fileTwo = fopen("text2.txt", "r");
    FILE *outputPtr;
    outputPtr = fopen("merge12.txt", "w");
    if(fileOne == NULL || fileTwo == NULL || outputPtr == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Initialize char, read all chars from file one and copy them to file three
    //Then, do the same for file two
    char read;
    while((read = fgetc(fileOne)) != EOF){
        fputc(read, outputPtr);
    }
    while((read = fgetc(fileTwo)) != EOF){
        fputc(read, outputPtr);
    }

    fclose(fileOne);
    fclose(fileTwo);
    fclose(outputPtr);

    return 0;
}