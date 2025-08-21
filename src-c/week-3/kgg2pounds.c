/*
CH-230-A
a3_p6.c 
Santiago Dominguez
20 September 2022
Reads weight in two ints (kgs + grams), converts to pounds as float, prints result
*/

#include <stdio.h>

float to_pounds(int kg, int g){
    //Add up total weight in kg, then convert to pounds
    float totalWeight = (float)kg + (float)g/1000;
    return totalWeight*2.2;
}

int main() {
    //Initialize variables and read kg and g values
    int kg;
    int g;
    scanf("%d",&kg);
    scanf("%d",&g);

    //Call to_pounds and print result
    printf("Result of conversion: %f\n", to_pounds(kg,g));

    return 0;
}