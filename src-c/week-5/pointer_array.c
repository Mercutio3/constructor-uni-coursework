/*
CH-230-A
a5_p6.c
Santiago Dominguez
4 October 2022
Iterates over an array with pointers, prints number of items before first negative
 */

#include <stdio.h>

int main(){
    //Read array length and initialize array of that length
    int arrayLength;
    scanf("%d", &arrayLength);
    float numArray[arrayLength];

    //Read user values for array
    for(int i = 0; i < arrayLength; i++){
        scanf("%f", &numArray[i]);
    }

    //Declare variables and pointer
    int beforeNeg = 0;
    float *ptr = numArray;

    //Walk through array with pointer arithmetic
    while(*ptr != '\0') {
        if(*ptr < 0.0){
            break;
        }
        beforeNeg++;
        ptr++;
    }
    
    //Print results
    if(beforeNeg == 1){
        printf("Before the first negative value: %d element\n", beforeNeg);
    } else {
        printf("Before the first negative value: %d elements\n", beforeNeg);
    }
    
    return 0;
}