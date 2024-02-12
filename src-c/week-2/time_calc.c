/*
 * CH-230-A
 * a2_p3.c
 * Santiago Dominguez
 * 14 September 2022
 */

#include <stdio.h>

int main() {
    //Read weeks, days, and hours and store them in variables
    char line1[100], line2[100], line3[100];
    int weeks, days, hours;
    printf("Enter weeks: ");
    fgets(line1, sizeof(line1), stdin);
    sscanf(line1, "%d", &weeks);
    printf("Enter days: ");
    fgets(line2, sizeof(line2), stdin);
    sscanf(line2, "%d", &days);
    printf("Enter hours: ");
    fgets(line3, sizeof(line3), stdin);
    sscanf(line3, "%d", &hours);

    //Find out total hours and print total
    int totalHours = (weeks*168) + (days*24) + hours;
    printf("Total hours: %d\n",totalHours);

    return 0;
}