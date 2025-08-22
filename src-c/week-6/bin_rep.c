/*
CH-230-A
a6_p6.c
Santiago Dominguez
12 October 2022
Prints decimal and binary representation of a char read from user input
 */

#include <stdio.h>

int main(){
    //Initialize char and read user input
    unsigned char read;
    scanf("%c", &read);

    //Print decimal represenation
    printf("The decimal representation is: %d\n", read);
    printf("The binary representation is: ");

    //Convert an unsigned char (8 bits) into binary and print result
    int charInt = read;
    int result;
    
    for(int i = 7; i >= 0; i--){
        result = charInt >> i;
        if(result & 1){
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}