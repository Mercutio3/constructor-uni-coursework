/*
 * CH-230-A
 * a2_p6.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>

int main() {
    //Read doubles and store them in variables
    char line1[100],line2[100];
    double x, y;
    fgets(line1, sizeof(line1), stdin);
    sscanf(line1, "%lf", &x);
    fgets(line2, sizeof(line2), stdin);
    sscanf(line2, "%lf", &y);

    //Create pointers and assign them to doubles
    double *ptr_one, *ptr_two, *ptr_three;
    ptr_one = &x;
    ptr_two = &x;
    ptr_three = &y;

    //Print memory addresses
    printf("Memory address of pointer one: %p\n", ptr_one);
    printf("Memory address of pointer two: %p\n", ptr_two);
    printf("Memory address of pointer three: %p\n", ptr_three);

    return 0;

    /* As demonstrated by the three print statements, ptr_one
    ptr_two contain the same memory address, while ptr_three's
    memory address is different. */
}