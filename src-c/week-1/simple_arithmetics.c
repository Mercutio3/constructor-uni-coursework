/*
 * CH-230-A
 * a1_p4.c
 * Santiago Dominguez
 * 6 September 2022
 */

#include <stdio.h>

int main() {
    int x = 17, y = 4;
    float z = y;
    
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    
    int sum = x + y;
    int product = x * y;
    int difference = x - y;
    float quotient = x / z;
    int remainder = x % y;
    
    printf("sum=%d\n", sum);
    printf("product=%d\n", product);
    printf("difference=%d\n", difference);
    printf("division=%f\n", quotient);
    printf("remainder of division=%d\n", remainder);

    return 0;
}