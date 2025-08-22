/*
CH-230-A
a9_p3.c
Santiago Dominguez
1 November 2022
Calculates absolute values of floats
*/

#include <iostream>

using namespace std;

float absoluteValue(float num);

int main(int argc, char** argv){
    //Intialize float variables, one positive and one negative
    float floatParam1 = 12.3;
    float floatParam2 = -15.2;

    //Call absolute value function and print returned result on output
    cout << absoluteValue(floatParam1) << endl;
    cout << absoluteValue(floatParam2) << endl;

    return 0;
}

//Return input if positive (already absolute value) or with opposite sign if negative
float absoluteValue(float num){
    
    if(num >= 0.0){
        return num;
    } else {
        return 0.0-num;
    }
}