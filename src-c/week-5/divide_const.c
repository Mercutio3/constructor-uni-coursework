/*
CH-230-A
a5_p2.c
Santiago Dominguez
4 October 2022
Iterative division of a static array by 5 (as per instructions)
 */

#include <stdio.h>

void divby5(float arr[], int size);

int main() {
    //Initialize array and size int
    float floatArray[] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    int size = 6;

    //Print array before change
    printf("Before:\n");
    for(int i = 0; i < size; i++){
        printf("%0.3f ", floatArray[i]);
    }
    printf("\n");

    divby5(floatArray, size);

    //Print array after change
    printf("After:\n");
    for(int i = 0; i < size; i++){
        printf("%0.3f ", floatArray[i]);
    }
    printf("\n");

    return 0;
}

void divby5(float arr[], int size){
    //Divide all elements of array by 5
    for(int i = 0; i < size; i ++){
        arr[i] = arr[i] / 5;
    }
}