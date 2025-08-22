/*
CH-230-A
a5_p1.c
Santiago Dominguez
4 October 2022
Prints a triangle shape of user-defined height using a user-defined character
 */

#include <stdio.h>

#define MAX_LINE 100 //Max length of user input

void printTriangleChars(int n, char ch);

int main() {
    //Initialize variables
    int triangleHeight;
    char triangleChar;
    char line[MAX_LINE], line2[MAX_LINE];

    //Read user input
    fgets(line, sizeof(line),stdin);
    sscanf(line, "%d", &triangleHeight);
    fgets(line2, sizeof(line),stdin);
    sscanf(line2,"%c", &triangleChar);

    printTriangleChars(triangleHeight, triangleChar);

    return 0;
}

void printTriangleChars(int n, char ch){
    //Nested for loop to print triangle shape
    for(int i = n; i > 0; i--){
        for(int j = i; j > 0; j--){
            printf("%c", ch);
        }
        printf("\n");
    }
}