/*
CH-230-A
a3_p8.c 
Santiago Dominguez
21 September 2022
Reads float array of user-defined length, computes sum and average of its values
*/

#include <stdio.h>
float computeSum(float nums[], int length);
float computeAvg(float nums[], int length);

int main(){
    //Initalize array and int to store it's arbitrary length
    float numbers[10];
    int length;

    //Read user input
    for(int i = 0; i < 10; i++){
        float read;
        scanf("%f",&read);
        if(read == -99.0){
            length = i;
            break;
        }
        numbers[i] = read;
        length = i;
    }

    //Print sum and average by calling functions
    printf("Sum of values: %f\n", computeSum(numbers, length));
    printf("Average of values: %f\n", computeAvg(numbers, length));

    return 0;
}

//Compute sum of all elements in array and return result
float computeSum(float nums[], int length){
    float sum = 0.0;
    for(int i=0;i<length;i++){
        sum += nums[i];
    }
    return sum;
}

//Compute average of all elements in array and return result
float computeAvg(float nums[], int length){
    return computeSum(nums, length) / length;
}