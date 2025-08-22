/*
CH-230-A
a8_p4.c
Santiago Dominguez
25 October 2022
Implements stack struct functionality: push, pop, empty, print, and isEmpty check
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
        //printf("Pushing %d\n", pushInt);
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

void printStack(struct stack *intStack){
    //Create variable equal to the count
    int countDummy = intStack->count;

    //Print every item in the stack
    while(countDummy > -1){
        printf("%d", intStack->array[countDummy]);
        countDummy--;
    }
    printf(".\n");
}