/*
CH-230-A
a8_p6.c
Santiago Dominguez
25 October 2022
Reads doubles from user-specified files, performs arithmetic, writes results in "results.txt"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100 //Max length of user input

int main(){
    //Create file pointer for reading files, read file names from user input
    char line1[MAX_LINE];
    char line2[MAX_LINE];
    fgets(line1, sizeof(line1), stdin);
    fgets(line2, sizeof(line2), stdin);
    
    //Remove \n character from read strings so they can be passed in fopen
    line1[strcspn(line1, "\n")] = 0;
    line2[strcspn(line2, "\n")] = 0;
    
    FILE *fileOne;
    fileOne = fopen(line1, "r");
    FILE *fileTwo;
    fileTwo = fopen(line2, "r");
    if(fileOne == NULL || fileTwo == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Read the two doubles from the two files and close the two files
    double read1, read2;
    fscanf(fileOne, "%lf", &read1);
    fscanf(fileTwo, "%lf", &read2);
    fclose(fileOne);
    fclose(fileTwo);

    //Create file pointer for output file
    FILE *outputPtr;
    outputPtr = fopen("results.txt", "w");
    if(outputPtr == NULL){
        printf("Some error occured.\n");
        exit(1);
    }

    //Compute results, write them in the output file and close file
    fprintf(outputPtr, "%lf\n", read1+read2);
    fprintf(outputPtr, "%lf\n", read1-read2);
    fprintf(outputPtr, "%lf\n", read1*read2);
    fprintf(outputPtr, "%lf\n", read1/read2);
    fclose(outputPtr);

    return 0;
}