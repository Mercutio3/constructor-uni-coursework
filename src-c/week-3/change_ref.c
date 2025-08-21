/*
CH-230-A
a3_p10.c 
Santiago Dominguez
29 September 2022
Demonstrates arithmetic operations via pointers
*/

#include <stdio.h>

float product(float a, float b);
void productbyref(float a, float b, float *p);
void modifybyref(float *a, float *b);

int main(){
    //Initialize and read floats
    float one, two;
    printf("Enter two floats:\n");
    scanf("%f",&one);
    scanf("%f",&two);

    printf("Product of floats: %f\n", product(one,two));

    //Define pointers, call productbyref() and print result
    float refProduct = 0.0;
    float *refPtr;
    refPtr = &refProduct;
    productbyref(one, two, refPtr);
    printf("Product of floats by reference: %f\n", refProduct);

    printf("Both functions have the same effect.\n");

    //Initialize pointers, call modifybyref() and print result
    float *refOne;
    float *refTwo;
    refOne = &one;
    refTwo = &two;
    printf("Floats before using modifybyref(): %f, %f\n", one, two);
    modifybyref(refOne, refTwo);
    printf("Changed floats using modifybyref(): %f, %f\n", one, two);

    printf("First float increased by 3 and second float increased by 11.\n");

    return 0;
}

float product(float a, float b){
    return a*b;
}

void productbyref(float a, float b, float *p){
    *p = a*b;
}

void modifybyref(float *a, float *b){
    *a += 3;
    *b += 11;
}