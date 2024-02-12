/*
 * CH-230-A
 * a2_p4.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>

int main() {
    //Reading the three floats and storing them.
    char line1[100], line2[100], line3[100];
    float a,b,h;
    fgets(line1, sizeof(line1), stdin);
    sscanf(line1, "%f", &a);
    fgets(line2, sizeof(line2), stdin);
    sscanf(line2, "%f", &b);
    fgets(line3, sizeof(line3), stdin);
    sscanf(line3, "%f", &h);

    //Compute and print areas
    printf("square area=%f\n", a * a);
    printf("rectangle area=%f\n", a * b);
    printf("triangle area=%f\n", (a * h) / 2);
    printf("trapezoid area=%f\n", ((a + b) / 2) * h);
   
    return 0;
}