/*
CH-230-A
a5_p4.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
void divby5(float arr[], int size);

int main() {
    //Declare variables and read array size
    float *floatArray;
    int size;
    printf("Enter array size:\n");
    scanf("%d", &size);

    //Dynamically allocated array
    floatArray = (float*) malloc(sizeof(float) * size);
    if(floatArray == NULL){
        exit(1);
    }

    printf("Enter floats:\n");
    for(int i = 0; i < size; i++){
        scanf("%f", &floatArray[i]);
    }

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

    free(floatArray);

    return 0;
}

void divby5(float arr[], int size){
    //Divide all elements of array by 5
    for(int i = 0; i < size; i ++){
        arr[i] = arr[i] / 5;
    }
}