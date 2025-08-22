/*
CH-230-A
a6_p4.c
Santiago Dominguez
11 October 2022
Computes scalar product of two vectors, with optional extra output via macro
 */

#include <stdio.h>

#define INTERMEDIATE //Optional printing of intermediate computation values

void scalarProduct(int vector1[], int vector2[], int components);

int main(){
    //Initialize variables and arrays, read user input
    int n;
    scanf("%d", &n);
    int v[n];
    int w[n];

    for(int i = 0; i < n; i++){
        int read;
        scanf("%d", &read);
        v[i] = read;
    }

    for(int i = 0; i < n; i++){
        int read;
        scanf("%d", &read);
        w[i] = read;
    }

    //Call function and print result
    scalarProduct(v,w,n);

    return 0;
}

void scalarProduct(int vector1[], int vector2[], int components){
    //Calculate scalar product by multiplying products of components
    //These are stored in a new array, whose sum of elements is returned
    int products[components];
    int productSum = 0.0;

    for(int i = 0; i < components; i++){
        products[i] = vector1[i] * vector2[i];
    }

    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
    #endif
    for(int i = 0; i < components; i++){
        #ifdef INTERMEDIATE
            printf("%d\n", products[i]);
        #endif
        productSum += products[i];
    }

    printf("The scalar product is: %d\n", productSum);
}