/*
This program computes some basic arithmetic operations and prints the results.
The goal is to demonstrate usage of five basic operators.
*/

#include <stdio.h>

int main() {
    //Declare variables
    int x = 17, y = 4;
    float z = y;

    //Print variables
    printf("x=%d\n", x);
    printf("y=%d\n", y);

    //Perform caltulations
    int sum = x + y;
    int product = x * y;
    int difference = x - y;
    float quotient = x / z;
    int remainder = x % y;

    //Print results
    printf("sum=%d\n", sum);
    printf("product=%d\n", product);
    printf("difference=%d\n", difference);
    printf("division=%f\n", quotient);
    printf("remainder of division=%d\n", remainder);

    return 0;
}
