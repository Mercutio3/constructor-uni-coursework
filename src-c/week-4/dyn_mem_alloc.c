/*
CH-230-A
a4_p6.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void printTwoLargest(int arr[], int n);

int main(){
    //Intiialize dynamic array and read user value for n
    int *dyn_array;
    int n;
    printf("How many integers?\n");
    scanf("%d",&n);

    //Allocate memory, ensure array isn't empty
    dyn_array = (int*) malloc(sizeof(int) * n);

    if(dyn_array == NULL){
        exit(1);
    }
    
    //Read numbers
    printf("Input numbers:\n");
    for(int i = 0; i < n; i++){    
        scanf("%d", &dyn_array[i]);
    }

    printTwoLargest(dyn_array, n);
    
    free(dyn_array);

    return 0;
}

void printTwoLargest(int arr[], int n){
    //Initialize variables for max and 2nd max values
    int largest = arr[0];
    int secondLargest;
    if(n > 1){
        secondLargest = arr[1];
    } else {
        secondLargest = arr[0];
    }

    //Find two largest values iterating through the array only once
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
    }
    printf("Two largest numbers in array: %d and %d\n", largest, secondLargest);
}