/*
CH-230-A
a6_p3.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>

//Define min/max, determine smallest/largest of two elements and then compare to third element
#define MIN(a, b, c) (MIN2(MIN2(a,b), c))
#define MIN2(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b, c) (MAX2(MAX2(a,b), c))
#define MAX2(a, b) ((a) > (b) ? (a) : (b))
//Define macro that computes midrange
#define MIDRANGE(a,b,c) ((double)((MIN(a,b,c)) + (MAX(a,b,c))) / 2)

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