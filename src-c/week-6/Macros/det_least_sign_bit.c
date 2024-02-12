/*
CH-230-A
a6_p2.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
//Macro uses bitwise AND to determine least significant bit
#define LEAST_SIG(num) ((num) & (1))

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