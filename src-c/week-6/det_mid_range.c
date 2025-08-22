/*
CH-230-A
a6_p3.c
Santiago Dominguez
11 October 2022
Calculates midrange via macros
 */

#include <stdio.h>

//Determine smallest of two elements, compare to third element
#define MIN(a, b, c) (MIN2(MIN2(a,b), c))
#define MIN2(a, b) ((a) < (b) ? (a) : (b))

//Determine largest of two elements, compare to third element
#define MAX(a, b, c) (MAX2(MAX2(a,b), c))
#define MAX2(a, b) ((a) > (b) ? (a) : (b))

#define MIDRANGE(a,b,c) ((double)((MIN(a,b,c)) + (MAX(a,b,c))) / 2) //Computes midrange

int main(){
    //Initialize variables and get user input
    int int1, int2, int3;
    scanf("%d", &int1);
    getchar();
    scanf("%d", &int2);
    getchar();
    scanf("%d", &int3);

    //Call midrange macro and print output
    printf("The mid-range is: %.6lf\n", MIDRANGE(int1,int2,int3));

    return 0;
}