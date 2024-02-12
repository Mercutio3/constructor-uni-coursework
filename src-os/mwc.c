/* Operating Systems 2023 Problem Set #4
 * Problem 8.3: memory-mapped word count
 * Santiago Dominguez
 * 30 October 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//Global variables for total counts
int totalLines, totalWords = 0;
long int totalBytes = 0;

void mappingCount(char* fileName){
    //Open and read file with memory mapping, check for errors
    int readFile = open(fileName, O_RDONLY);
    if(readFile == -1){
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    struct stat fileStat;
    if(fstat(readFile, &fileStat) == -1){
        perror("Failed to retrieve file information.");
        exit(EXIT_FAILURE);
    }

    char* fileData = mmap(NULL, fileStat.st_size, PROT_READ, MAP_PRIVATE, readFile, 0);
    if(fileData == MAP_FAILED){
        perror("Memory mapping failure.");
        close(readFile);
        exit(EXIT_FAILURE);
    }

    //Count lines and words
    int lineCount = 1;
    int wordCount = 0;
    for(size_t i = 0; i < fileStat.st_size; i++){
        if(fileData[i] == '\n'){
            lineCount++;
        }
        if(isspace(fileData[i])){
            wordCount++;
        }
    }

    //Print results, add totals, close file
    printf("%d\t\t%d\t\t%ld\t\t%s\n", lineCount, wordCount, (long)fileStat.st_size,fileName);
    totalLines += lineCount;
    totalWords += wordCount;
    totalBytes += (long)fileStat.st_size;
    munmap(fileData, 0);
    close(readFile);
}

void stdIOCount(char* fileName){
    //Open file with standard I/O; if failure, exit program
    FILE *readFile = fopen(fileName, "r");
    if(readFile == NULL){
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    //Count lines and words
    int lineCount = 1;
    int wordCount = 0;
    char ch;
    while ((ch = fgetc(readFile)) != EOF){
        if(ch == '\n'){
            lineCount++;
        }
        if(isspace(ch)){
            wordCount++;
        }
    }

    //Calculate file size
    fseek(readFile, 0L, SEEK_END);
    long int fileSize = ftell(readFile);

    //Print results, add totals, close file
    printf("%d\t\t%d\t\t%ld\t\t%s\n", lineCount, wordCount, fileSize, fileName);
    totalLines += lineCount;
    totalWords += wordCount;
    totalBytes += fileSize;
    fclose(readFile);
}

int main(int argc, char *argv[]){
    int standardIOMode = 0;
    char** fileNames = NULL;
    int fileCount = 0;

    if(argc < 2){
        //If no command line arguments given, read & process files with standard I/O 
        standardIOMode = 1;
        char fileName[20];

        printf("Enter filename. Enter q to process all entered files.\n");
        while(1){
            //Read user input, check for errors
            if(scanf("%s", fileName) != 1){
                perror("User input error.");
                return EXIT_FAILURE;
            }

            //Exit loop when user enters 'q'
            if(strcmp(fileName, "q") == 0){
                break;
            }

            //Use dynamic array to read as many files as user wants
            fileCount++;
            fileNames = (char**) realloc(fileNames, fileCount * sizeof(char *));
            if(fileNames == NULL){
                perror("Memory allocation error.");
                return EXIT_FAILURE;
            }
            fileNames[fileCount-1] = strdup(fileName);
        }
    }

    printf("Lines\t\tWords\t\tBytes\n");
    if(standardIOMode){
        //Process I/O input with standard I/O
        for(int i = 0; i < fileCount; i++){
            stdIOCount(fileNames[i]);
            free(fileNames[i]);
        }
        free(fileNames);
    } else {
        //Process command line input using memory mapping
        for(int i = 1; i < argc; i++){
            mappingCount(argv[i]);
        }
    }

    //Print totals, in case of multiple file input
    if(argc > 2 || fileCount > 1){
        printf("%d\t\t%d\t\t%ld\t\ttotal\n", totalLines, totalWords, totalBytes);
    }

    return EXIT_SUCCESS;
}