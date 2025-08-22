/*
CH-230-A
a5_p11.c
Santiago Dominguez
4 October 2022
Determines if a number is a prime number using recursion
 */

#include <stdio.h>

int isPrime(int num, int i);

int main(){
    //Declare integer and read user input into it
    int x;
    scanf("%d", &x);

    //Print appropriate result based on function return value
    if(isPrime(x,2) == 1){
        printf("%d is prime\n", x);
    } else {
        printf("%d is not prime\n", x);
    }

    return 0;
}

int isPrime(int num, int i){
    //Special case for num = 1 to avoid a segmentation fault
    if(num == 1){
        return 0;
    }
    
    //Return 1 if only divisor is the number itself
    if(num == i){
        return 1;
    }

    //If num is divisible by any number other than 1 or itself, return 0
    if(num % i == 0) {
        return 0;
    }
    
    //Call function with next divisor
    return isPrime(num, i+1);
}