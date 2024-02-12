/*
CH-230-A
a2_p1.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main() {
    //Read doubles and turn them into numbers
    char line[100], line2[100];
    double double1, double2;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &double1);
    fgets(line2, sizeof(line2), stdin);
    sscanf(line2, "%lf", &double2);

    //Read ints and turn them into numbers
    char line3[100], line4[100];
    int int1, int2;
    fgets(line3, sizeof(line3), stdin);
    sscanf(line3, "%d", &int1);
    fgets(line4, sizeof(line4), stdin);
    sscanf(line4, "%d", &int2);

    //Read chars
    char line5[3], line6[3];
    char char1, char2;
    fgets(line5, sizeof(line5), stdin);
    sscanf(line5, "%c", &char1);
    fgets(line6, sizeof(line6), stdin);
    sscanf(line6, "%c", &char2);

    //Operations with doubles
    double doubleSum = double1 + double2;
    double doubleDiff = double1 - double2;
    double firstSquare = double1 * double1;
    printf("sum of doubles=%f\n",doubleSum);
    printf("difference of doubles=%f\n",doubleDiff);
    printf("square=%f\n",firstSquare);

    //Operations with ints
    int intSum = int1 + int2;
    int intProduct = int1 * int2;
    printf("sum of integers=%d\n",intSum);
    printf("product of integers=%d\n",intProduct);

    //Operations with chars
    printf("sum of chars=%d\n",char1 + char2);
    printf("product of chars=%d\n",char1 * char2);
    printf("sum of chars=%c\n",char1 + char2);
    printf("product of chars=%c\n",char1 * char2);  
}