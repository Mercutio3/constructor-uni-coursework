/*
 * CH-230-A
 * a2_p5.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>

int main() {
    //Read integer, store it, and print it
    char line[100];
    int a;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &a);
    printf("You've entered: %d\n", a);

    //Create pointer and manipulate a with it
    int *ptr_a;
    ptr_a = &a;
    printf("Pointer address: %p\n", ptr_a);
    *ptr_a = *ptr_a + 5;
    printf("Modified value through pointer: %d\n", *ptr_a);

    return 0;
}