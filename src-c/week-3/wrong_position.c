/*
CH-230-A
a3_p4.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int position(char str[], char c){
    int idx;

    for(idx = 0; str[idx] != c && str[idx] != '\0'; ++idx){
        /* Do nothing */
    }

    return idx;
}

int main() {
    char line[80];
    while(1) {
        printf("Enter string: \n");
        fgets(line, sizeof(line), stdin);
        printf("The first occurence of 'g' is: %d\n", position(line, 'g'));
    }
    
    return 0;
}

//The for loop in line 13 did not have curly brackets