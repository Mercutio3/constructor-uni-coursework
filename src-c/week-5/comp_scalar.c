/*
CH-230-A
a5_p5.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
void scalarProduct(double vector1[], double vector2[], int components);
void determineSmallest(double vector[], int components);
void determineLargest(double vector[], int components);

int main(){
    //Initialize variables and arrays, read user input
    int n;
    scanf("%d", &n);
    double v[n];
    double w[n];

    for(int i = 0; i < n; i++){
        double read;
        scanf("%lf", &read);
        v[i] = read;
    }

    for(int i = 0; i < n; i++){
        double read;
        scanf("%lf", &read);
        w[i] = read;
    }

    //Call functions and print results
    scalarProduct(v,w,n);
    determineSmallest(v,n);
    determineLargest(v,n);
    determineSmallest(w,n);
    determineLargest(w,n);

    return 0;
}

void scalarProduct(double vector1[], double vector2[], int components){
    //Calculate scalar product by multiplying products of components
    //These are stored in a new array, whose sum of elements is returned
    double products[components];
    double productSum = 0.0;

    for(int i = 0; i < components; i++){
        products[i] = vector1[i] * vector2[i];
    }

    for(int i = 0; i < components; i++){
        productSum += products[i];
    }

    printf("Scalar product=%f\n", productSum);
}

void determineSmallest(double vector[], int components){
    //Determine smallest value and its position in the array
    double smallest = vector[0];
    int smallestPos = 0;
    
    
    for(int i = 0; i < components; i++){
        if(vector[i] < smallest){
            smallest = vector[i];
            smallestPos = i;
        }
    }

    printf("The smallest = %f\n", smallest);
    printf("Position of smallest = %d\n", smallestPos);
}

void determineLargest(double vector[], int components){
    //Determine largest value in the array and its position
    double largest = vector[0];
    int largestPos = 0;
    
    
    for(int i = 0; i < components; i++){
        if(vector[i] > largest){
            largest = vector[i];
            largestPos = i;
        }
    }

    printf("The largest = %f\n", largest);
    printf("Position of largest = %d\n", largestPos);
}