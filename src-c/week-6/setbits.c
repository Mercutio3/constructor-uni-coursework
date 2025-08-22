/*
CH-230-A
a6_p7.c
Santiago Dominguez
12 October 2022
Reads a char from user input, sets three of its bits to 1, prints result
 */

#include <stdio.h>

int set3bits(unsigned char c, int bit1, int bit2, int bit3);
int setBit(int num, int bit);

int main(){
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

    //Call set3bits, turn result into binary and print result
    printf("After setting the bits: ");

    int charInt2 = set3bits(read, 7, 6, 1);
    int result2;
    for(int i = 7; i >= 0; i--){
        result2 = charInt2 >> i;
        if(result2 & 1){
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}

int set3bits(unsigned char c, int bit1, int bit2, int bit3){
    int intChar = c;
    
    //Call auxiliary function setBit three times, once per bit
    intChar = setBit(intChar, bit1);
    intChar = setBit(intChar, bit2);
    intChar = setBit(intChar, bit3);

    return intChar;
}

int setBit(int num, int bit){
    //Set the "bit"th bit in num to 1, return modified int
    return (num | (1 << bit));
}