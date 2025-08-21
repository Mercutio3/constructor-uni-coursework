/*
CH-230-A
a3_p2.c 
Santiago Dominguez
20 September 2022
Reads character ch and integer n, prints characters ch, ch-1, ..., ch-n
*/

#include <stdio.h>

int main() {
    //Initialize variables and read input values
    char ch;
    int n;
    printf("Enter a character: ");
    scanf("%c",&ch);
    printf("Enter an integer: ");
    scanf("%d",&n);

    //Print ch,ch-1,..,ch-n characters
    for(int i=ch; i>=ch-n; i--){
        printf("%c\n",i);
    }

    return 0;
}