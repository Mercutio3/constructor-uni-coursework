/*
CH-230-A
a7_p7.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isEmpty(struct stack *intStack){
    //Return 1 if stack is empty, 0 otherwise
    if(intStack->count == -1){
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack *intStack, int pushInt){
    //If stack isn't full, add pushInt to stack
    if(intStack->count == 11){
        printf("Pushing Stack Overflow\n");
    } else {
        printf("Pushing %d\n", pushInt);
        intStack->count++;
        intStack->array[intStack->count] = pushInt;
    }
    
}

void pop(struct stack *intStack){
    //If stack isn't empty, remove topmost element
    if(isEmpty(intStack)){
        printf("Popping Stack Underflow\n");
    } else {
        printf("Popping %d\n", intStack->array[intStack->count]);
        intStack->count--;
    }
}

void empty(struct stack *intStack){
    //As long as stack has elements, remove topmost element repeatedly
    printf("Emptying Stack ");
    while(isEmpty(intStack) == 0){
        printf("%d ", intStack->array[intStack->count]);
        intStack->count--;
    }
    printf("\n");
}