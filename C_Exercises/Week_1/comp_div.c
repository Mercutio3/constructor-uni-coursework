/*
CH-230-A
a1_p1.c
Santiago Dominguez 
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main(){
    double result;
    result = (3.0 + 1.0) / 5.0;
    printf("The value of 4/5 is %lf\n", result);
    
    return 0;
}

/*
 * When using the integers 4 and 5 to calculate division result, 
 * the result is also given as an integer so it's rouned down to 0. 
 * You have to specify the dividend and divisor as floats or doubles
 * so that the output is given as a real number.
 */
