/*
 * CH-230-A
 * a2_p8.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>

int main() {
    //Read integer and store it in a variable
    char line[100];
    int num;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);

    //Determine if number is divisible by 2 and 7, print appropriate result.
    if(num%2==0 && num%7==0){
        printf("The number is divisible by 2 and 7\n");
    } else {
        printf("The number is NOT divisible by 2 and 7\n");
    }

    return 0;
}