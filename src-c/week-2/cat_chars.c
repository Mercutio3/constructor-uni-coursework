/*
 * CH-230-A
 * a2_p9.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>

int main() {
    //Read character and store it in a variable
    char line1[3];
    char char1;
    fgets(line1, sizeof(line1), stdin);
    sscanf(line1, "%c", &char1);

    //Use if statments to categorize character and print result.
    if(char1>=48 && char1<=57){
        printf("%c is a digit\n", char1);
    } else if (char1>=65 && char1<=90){
        printf("%c is a letter\n", char1);
    } else if (char1>=97 && char1<=122){
        printf("%c is a letter\n", char1);
    } else { 
        printf("%c is some other symbol\n", char1);
    }

    return 0;
}