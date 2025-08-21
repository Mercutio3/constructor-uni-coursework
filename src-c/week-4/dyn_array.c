/*
CH-230-A
a4_p9.c 
Santiago Dominguez
27 September 2022
Allocates memory for int array dynamically, prints product of smallest and largest elements
*/

#include <stdio.h>
#include <stdlib.h>

int prodminmax(int arr[], int n);

int main(){
    int *numArray;
    int n;
    printf("How many integers?\n");
    scanf("%d", &n);

    //Initialize array dynamically using malloc
    numArray = (int*) malloc(sizeof(int) * n);
    if(numArray == NULL){
        exit(1);
    }

    //Read user input
    printf("Enter integers:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &numArray[i]);
    }

    printf("Product of smallest and largest elements: %d\n", prodminmax(numArray, n));

    free(numArray);

    return 0;
}

int prodminmax(int arr[], int n){
    //Calculate min and max; then return their product
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return max*min;
}