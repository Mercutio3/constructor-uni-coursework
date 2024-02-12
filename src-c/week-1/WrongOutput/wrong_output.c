/*
CH-230-A
a1_p2.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main() {
    int result;
    result = (2 + 7) * 9 / 3;
    printf("The result is %d\n", result);
    
    return 0;
}

/* When using the %d formatted integer, it is necessary to match it with a corresponding parameter.
the program at first had no such parameter, so I added the "result" pareameter in line 13. Now it works. */