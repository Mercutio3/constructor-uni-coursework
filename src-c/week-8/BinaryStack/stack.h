/*
CH-230-A
a8_p4.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#ifndef _STACK_H_
#define _STACK_H_

struct stack {
    unsigned int count;
    int array[12];
};

int isEmpty(struct stack *intStack);
void push(struct stack *intStack, int pushInt);
void pop(struct stack *intStack);
void empty(struct stack *intStack);
void printStack(struct stack *intStack);

#endif