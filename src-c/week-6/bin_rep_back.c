/*
CH-230-A
a6_p5.c
Santiago Dominguez
11 October 2022
Prints decimal and backwards binary representation of a char read from user input
 */

#include <stdio.h>

void convertToBinary(int num);

int main(){
    unsigned char read;
    scanf("%c", &read);

    printf("The decimal representation is: %d\n", read);
    printf("The backwards binary representation is: ");

    int charInt = read;
    int result;

    for(int i = 0; i <= 7; i++){
        result = charInt >> i;
        if(result & 1){
            printf("1");
        } else {
            printf("0");
        }
    }

    //convertToBinary(read);

    printf("\n");
}

void convertToBinary(int num){
    if(num > 1){
        convertToBinary(num >> 1);
    }
    printf("%d", num & 1);
}