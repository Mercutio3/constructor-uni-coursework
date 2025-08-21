/*
CH-230-A
a3_p5.c 
Santiago Dominguez
20 September 2022
Uses switch statement to handle different operations with read temperature values
*/

#include <stdio.h>

int main() {
    //Initialize variables and read desired operation character & array length
    char c;
    int n;
    printf("What would you like to do with your temperatures?\n");
    printf("Enter s for sum, p for list, t for conversion to Fahrenheit, and anything else for average.\n");
    scanf("%c", &c);
    printf("How many temperatures will you enter?\n");
    scanf("%d",&n);
    double temperatures[n];
    
    //Read all temperature values and store them in array
    printf("Enter temperatures: \n");
    for(int i = 0; i < n; i++){
        double thisTemp;
        scanf("%lf",&thisTemp);
        temperatures[i] = thisTemp;
    }

    //Perform desired operation according to entered value of c
    switch(c){
        double sum;
        double tempF;
        
        case 's':
            for(int i = 0; i < n; i++){
                sum += temperatures[i];
            }
            printf("Sum of temperatures: %lf\n", sum);
            break;
        case 'p':
            for(int i = 0; i < n; i++){
                printf("%lf\n", temperatures[i]);
            }
            break;
        case 't':
            for(int i = 0; i < n; i++){
                tempF = (temperatures[i] * 9/5) + 32;
                printf("%lf\n", tempF);
            }
            break;
        default:
            for(int i = 0; i < n; i++){
                sum += temperatures[i];
            }
            printf("Average of temperatures: %lf\n", sum/n);
    }

    return 0;
}