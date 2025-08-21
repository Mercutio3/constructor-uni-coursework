/*
CH-230-A
a3_p3.c 
Santiago Dominguez
20 September 2022
Reads user input for centimeters and returns it in kilometers
*/

#include <stdio.h>
float convert(int cm){
    //Convert cm to km
    return (float)cm/100000;
}

int main() {
    //Read cm, print conversion
    int cm;
    scanf("%d",&cm);
    printf("Result of conversion: %f\n", convert(cm));

    return 0;
}