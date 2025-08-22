/*
CH-230-A
a7_p5.c
Santiago Dominguez
21 October 2022
Implements ascending and descending quicksort using function pointers
 */

#include <stdio.h>
#include <stdlib.h>

//Initialize functions and funciton pointer array
void (*sortFunc[2]) (int numArray[], int size);
void sortUp(int numArray[], int size);
int ascendingOrder(const void *va, const void *vb);
void sortDown(int numArray[], int size);
int descendingOrder(const void *va, const void *vb);

int main() {
    //Initialie variables, read user input and array
    int n;
    scanf("%d", &n);
    char command;

    int numArray[n];
    for(int i=0; i < n; i++){
        int read;
        scanf("%d", &read);
        getchar();
        numArray[i] = read;
    }

    //Assign functions pointers to sorting functions
    sortFunc[0] = sortUp;
    sortFunc[1] = sortDown;

    while(1){
        //Read instruction and call according function
        scanf("%c", &command);
        getchar();
        switch(command){
            case 'a':
                (*sortFunc[0]) (numArray, n);
                break;
            case 'd':
                (*sortFunc[1]) (numArray, n);
                break;
            case 'e':
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}

//Call qsort with ascending order filter
void sortUp(int numArray[], int size){
    qsort(numArray, size, sizeof(numArray[0]), ascendingOrder);
    for(int i = 0; i < size; i++){
        printf("%d ", numArray[i]);
    }
    printf("\n");
}

//Ascending order filter
int ascendingOrder(const void *va, const void *vb) {
    const int* a = (const int*) va;
    const int* b = (const int*) vb;
    if (*a < *b){
        return -1;
    } else if (*a > *b){
        return 1;
    } else {
        return 0;
    }
}

//Call qsort with descending order filter
void sortDown(int numArray[], int size){
    
    qsort(numArray, size, sizeof(numArray[0]), descendingOrder);
    for(int i = 0; i < size; i++){
        printf("%d ", numArray[i]);
    }
    printf("\n");
}

//Descending order filter
int descendingOrder(const void *va, const void *vb) {
    const int* a = (const int*) va;
    const int* b = (const int*) vb;
    if (*a > *b){
        return -1;
    } else if (*a < *b){
        return 1;
    } else {
        return 0;
    }
}