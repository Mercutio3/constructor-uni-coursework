/*
CH-230-A
a5_p1.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
void printTriangleChars(int n, char ch);

int main() {
    //Initialize variables
    int triangleHeight;
    char triangleChar;
    char line[100], line2[100];

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