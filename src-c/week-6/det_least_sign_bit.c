/*
CH-230-A
a6_p2.c
Santiago Dominguez
11 October 2022
Uses bitwise AND in a macro to determine least significant bit of a char
 */

#include <stdio.h>

#define LEAST_SIG(num) ((num) & (1)) //Least significant bit

int main(){
    //Initialize variables, read user input
    unsigned char read;
    scanf("%c", &read);
    int charInt = read;
    
    //Print results, call macro
    printf("The decimal representation is: %d\n", read);
    printf("The least significant bit is: %d\n", LEAST_SIG(charInt));

    return 0;
}