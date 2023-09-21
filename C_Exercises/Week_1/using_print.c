/*
Simple program that demonstrates how to print different data types.
Also demonstrates how to adjust floating point precision.
*/

#include <stdio.h>

int main() {
    int x = 2138;
    printf("x=%9d\n", x);
    
    float y = -52.358925;
    printf("y=%11.5f\n", y);
    
    char z = 'G';
    printf("z=%c\n", z);
    
    double u = 61.295339687;
    printf("u=%.7lf\n", u);
    
    return 0;
}
