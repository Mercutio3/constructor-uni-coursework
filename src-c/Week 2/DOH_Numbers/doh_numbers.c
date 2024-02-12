/*
CH-230-A
a2_p2.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main() {
    //Read and store character
    char line[3];
    char char1;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c", &char1);

    //Print everything
    printf("character=%c\n",char1);
    printf("decimal=%d\n",char1);
    printf("octal=%o\n", char1);
    printf("hexadecimal=%x\n", char1);
}