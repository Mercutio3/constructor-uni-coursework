/*
CH-230-A
a8_p4.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
    //Create stack and initialize count
    struct stack binaryNum;
    binaryNum.count = -1;

    //Read integer to be converted
    int decimalInt;
    scanf("%d", &decimalInt);
    printf("The binary representation of %d is ", decimalInt);

    //Convert decimal int to binary and store numbers in stack
    while(decimalInt > 0){
        push(&binaryNum, decimalInt%2);
        decimalInt /= 2;
    }

    //Print the stack with the binary result
    printStack(&binaryNum);

    return 0;
}