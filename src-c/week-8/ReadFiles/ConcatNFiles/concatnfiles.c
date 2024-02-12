/*
CH-230-A
a8_p9.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int concatFiles(char** fileNames, int numFiles, char* outputFilename);

int main(){
    //Read number of files
    int numFiles;
    scanf("%d", &numFiles);
    getchar();

    //Initialize array of strings, allocate memory, read filenames
    char **fileNames;
    int readLength = 100;
    fileNames = (char**)malloc(sizeof(char*)*numFiles);
    
    for(int i = 0; i < numFiles; ++i){
        fileNames[i] = (char*)malloc(sizeof(char)*readLength);
    }
    for(int i = 0; i < numFiles; i++){
        scanf("%100s", fileNames[i]);
    }

    //Print information
    printf("Concating the content of %d files ...\n", numFiles);
    printf("The result is:\n");

    //Call file concat function, print information
    concatFiles(fileNames, numFiles, "output.txt");
    printf("The result was written into output.txt\n");

    //Free memory
    for(int i = 0; i < numFiles; ++i){
        free(fileNames[i]);
    }
    free(fileNames);

    return 0;
}

int concatFiles(char** fileNames, int numFiles, char* outputFilename){
    //Create output file pointer, check if successful
    FILE *outputFile;
    outputFile = fopen(outputFilename, "wb");
    if(outputFile == NULL){
        printf("Some error occured while opening output file.\n");
        exit(1);
    }

    //Create char read buffer
    char charBuffer[64];
    
    for(int i = 0; i < numFiles; i++){
        char* fName = fileNames[i];

        //Create input file pointer, check if successful
        FILE *fileItem;
        fileItem = fopen(fName, "rb");
        if(fileItem == NULL){
            printf("Some error occured while opening input file.\n");
            exit(1);
        }

        int numFiles;

        //Read from input file, write in output file
        while((numFiles = fread(charBuffer, sizeof(char), 63, fileItem))){
            printf("%s\n", charBuffer);
            int k = fwrite(charBuffer, sizeof(char), numFiles, outputFile);
            fprintf(outputFile, "%s", "\n");
            if(!k){
                return 1;
            }
        }

        fclose(fileItem);
    }
    //Close files
    fclose(outputFile);

    return 0;
}