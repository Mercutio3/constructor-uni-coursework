/*
CH-230-A
a6_p1.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#define SWAP(X, Y, type) {type TEMP = X; X = Y; Y = TEMP;}

int main(){
    //Define variables and read input into them
    int intOne, intTwo;
    double doubleOne, doubleTwo;

    scanf("%d", &intOne);
    getchar();
    scanf("%d", &intTwo);
    getchar();
    scanf("%lf", &doubleOne);
    getchar();
    scanf("%lf", &doubleTwo);

    //Call macro to swap values
    SWAP(intOne, intTwo, int);
    SWAP(doubleOne, doubleTwo, double);
    
    //Print results
    printf("After swapping:\n");
    printf("%d\n", intOne);
    printf("%d\n", intTwo);
    printf("%.6lf\n", doubleOne);
    printf("%.6lf\n", doubleTwo);

    return 0;
}