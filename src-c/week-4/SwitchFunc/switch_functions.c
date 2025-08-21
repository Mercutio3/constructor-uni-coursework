/*
CH-230-A
a4_p3.c 
Santiago Dominguez
27 September 2022
Uses switch statement and user input to perform an operation on an array of arbitrary length
*/

#include <stdio.h>
#include <math.h>

float geometric_mean(float arr[], int num);
float highestNum(float numbers[], int length);
float lowestNum(float numbers[], int length);
float numSum(float numbers[], int length);

int main() {
    //Initalize array and int to store it's arbitrary length
    float numbers[15];
    int length;

    //Read user input
    for(int i = 0; i < 15; i++){
        char line[100];
        float read;
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f", &read);
        if(read < 0){
            length = i;
            break;
        }
        numbers[i] = read;
        length = i;
    }

    //Read user input
    char line[100];
    char input;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c", &input);

    //Switch statement with all four possible instructions calling their respective functions
    switch(input){
        case 'm':
            printf("Geometric mean of array: %f\n", geometric_mean(numbers,length));
            break;
        case 'h':
            printf("Highest value in array: %f\n", highestNum(numbers, length));
            break;
        case 'l':
            printf("Lowest value in array: %f\n", lowestNum(numbers, length));
            break;
        case 's':
            printf("Sum of values in array: %f\n", numSum(numbers, length));
            break;
        default:
            printf("Invalid command!\n");
    }

    return 0;
}

float geometric_mean(float arr[], int num){
    return pow(numSum(arr, num), (1.0/num));
}

float highestNum(float numbers[], int length){
    float result = 0.0;
    for(int i=0; i < length; i++){
        if(numbers[i] > result){
            result = numbers[i];
        }
    }
    return result;
}

float lowestNum(float numbers[], int length){
    float result = 0.0;
    for(int i=0; i < length; i++){
        if(numbers[i] < result){
            result = numbers[i];
        }
    }
    return result;
}

float numSum(float numbers[], int length){
    float sum = 0.0;
    for(int i = 0; i < length; i++){
        sum += numbers[i];
    }
    return sum;
}