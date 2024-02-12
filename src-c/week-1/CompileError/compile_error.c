/*
CH-230-A
a1_p3.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main() {
    float result;
    int a = 5;
    float b = 13.5;
    
    result = a / b;
    printf("The result is %f\n", result);
    
    return 0;
}

/* First of all, the absence of the '#' character for the include keyword caused a compile error.
After fixing that, in order to obtain the correct result, you must change "int b" to "float b" so that
float division can take place properly; afterwards, the "%d" signed decimal integer must be changed
to a "%f" floating point. */