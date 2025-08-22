/*
CH-230-A
a7_p7.c
Santiago Dominguez
22 October 2022
Header file defining struct for stack implementation
 */

struct stack {
    unsigned int count;
    int array[12];
};

int isEmpty(struct stack *intStack);
void push(struct stack *intStack, int pushInt);
void pop(struct stack *intStack);
void empty(struct stack *intStack);