/*
CH-230-A
a9_p3.c
Santiago Dominguez
sdominguez@jacobs-university.de
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

float absoluteValue(float num){
    //Return input number if it's positive (already its absolute value)
    //Return input number with opposite sign if it's negative
    if(num >= 0.0){
        return num;
    } else {
        return 0.0-num;
    }
}