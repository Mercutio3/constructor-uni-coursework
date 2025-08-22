/*
CH-230-A
a5_p10.c
Santiago Dominguez
4 October 2022
Recursive count-down from N to 1
 */

#include <stdio.h>
void countdownRecursive(int num);

int main() {
    //Read integer
    int n;
    scanf("%d", &n);

    countdownRecursive(n);

    return 0;
}

void countdownRecursive(int num){
    //Print number; if it's greater than 1, call function again with n-1
    printf("%d\n", num);
    if(num > 1){
        countdownRecursive(num-1);
    }
}