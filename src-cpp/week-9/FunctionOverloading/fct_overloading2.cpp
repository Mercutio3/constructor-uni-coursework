/*
CH-230-A
a9_p6.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <cmath>

using namespace std;

int myfirst(int integers[], int size);
double myfirst(double doubles[], int size);
char myfirst(char chars[], int size);

int main(int argc, char** argv){
    //intArray has elements that match the criteria
    int intArray[] = {1,-5,-4,3,2,6,7};
    int arraySize = (sizeof(intArray)/sizeof(intArray[0]));
    cout << myfirst(intArray, arraySize) << endl;

    //intArray2 has no element that matches criteria
    int intArray2[] = {1,-5,-4,3,13,1233,7};
    arraySize = (sizeof(intArray2)/sizeof(intArray2[0]));
    cout << myfirst(intArray2, arraySize) << endl;

    //doubleArray2 has elements that match the criteria
    double doubleArray[] = {12.3,44.2,-2.3,-5.0,23.0};
    arraySize = (sizeof(doubleArray)/sizeof(doubleArray[0]));
    cout << myfirst(doubleArray, arraySize) << endl;

    //doubleArray2 has no element that matches criteria
    double doubleArray2[] = {12.3,44.2,-2.3,23.0,5.0};
    arraySize = (sizeof(doubleArray2)/sizeof(doubleArray2[0]));
    cout << myfirst(doubleArray2, arraySize) << endl;

    //charArray has elements that match the criteria
    char charArray[] = {'2','a','!','g','e','z'};
    arraySize = (sizeof(charArray)/sizeof(charArray[0]));
    cout << myfirst(charArray, arraySize) << endl;

    //charArray2 has no element that matches criteria
    char charArray2[] = {'2','a','!','U','e',';'};
    arraySize = (sizeof(charArray2)/sizeof(charArray2[0]));
    cout << myfirst(charArray2, arraySize) << endl;

    return 0;
}

int myfirst(int integers[], int size){
    //Loop through int array and return first even number
    //If not such number exists, return -1
    for(int i = 0; i < size; i++){
        if(integers[i] % 2 == 0){
            if(integers[i] >= 0){
                return integers[i];
            }
        }
    }

    return -1;
}

double myfirst(double doubles[], int size){
    for(int i = 0; i < size; i++){
        if(doubles[i] < 0.0){
            if(fmod(doubles[i],1.0) == 0.0){
                return doubles[i];
            }
        }
    }
    return -1.1;
}

char myfirst(char chars[], int size){
    //Define consonants, both upper and lowercase
    char lowerCons[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    char upperCons[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
    
    //Loop through char array and return first consonant
    //If not such char exists, return '0'
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 21; j++){
            if(chars[i] == lowerCons[j] || chars[i] == upperCons[j]){
                return chars[i];
            }
        }
    }

    return '0';
}