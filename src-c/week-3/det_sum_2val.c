/*
CH-230-A
a3_p9.c 
Santiago Dominguez
21 September 2022
Prints values in indexes 2 and 5 of an array
*/

#include <stdio.h>
double sum25(double v[], int n);

int main(){
    //Initialize array length, make sure it's not greater than 20
    int length;
    while(1){
        scanf("%d", &length);
        if(length <=20){
            break;
        }
    }
    double numbers[length];

    //Read numbers and store them in array
    for(int i = 0; i < length; i++){
        double read;
        scanf("%lf", &read);
        numbers[i] = read; 
    }

    //Call sumResult, print appropriate result
    double sumResult = sum25(numbers,length);
    if(sumResult == -111.0){
        printf("One or both positions are invalid\n");
    } else {
        printf("sum=%lf\n", sumResult);
    }

    return 0;
}

//Check if positions are available and return appropriate result
double sum25(double v[], int n){
    if(n<6){
        return -111;
    } else {
        return v[2] + v[5];
    }
}