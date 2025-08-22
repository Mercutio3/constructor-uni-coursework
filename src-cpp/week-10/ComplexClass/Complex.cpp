/*
CH-230-A
a10_p8.cpp
Santiago Dominguez
9 November 2022
Implements getter, setter, and operation methods for complex class
 */

#include <iostream>
#include "Complex.h"

using namespace std;

//Default empty constructor sets everything to 0
Complex::Complex() {
    real = imag = 0;
    cout << "Empty constructor called." << endl;
}

//Constructor taking one or two values and setting them.
Complex::Complex(float r, float i){
    real = r;
    imag = i;
    cout << "Constructor taking one or both values called." << endl;
}

//Calculate conjugate of a complex number
Complex Complex::conjugate(){
    float returnImag = 0 - imag;
    return Complex(real, returnImag);
}

//Calculate sum of two numbers and return result 
Complex Complex::add(Complex secondNum){
    float returnReal = real + secondNum.real;
    float returnImag = imag + secondNum.imag;
    return Complex(returnReal, returnImag);
}

//Calculate difference between two numbers and return result 
Complex Complex::subtract(Complex secondNum){
    float returnReal = real - secondNum.real;
    float returnImag = imag - secondNum.imag;
    return Complex(returnReal, returnImag);
}

//Calculate product of two numbers and return result 
Complex Complex::multiply(Complex secondNum){
    float returnReal = (real * secondNum.real) - (imag * secondNum.imag);
    float returnImag = (imag * secondNum.real) + (real * secondNum.imag);
    return Complex(returnReal, returnImag);
}

//Setter methods
void Complex::setReal(float r){
    real = r;
}
void Complex::setImag(float i){
    imag = i;
}

//Print the complex number with cout
void Complex::print() {
    if(imag){
        cout << noshowpos << real << showpos << imag << "i" << endl;
    } else {
        cout << noshowpos << real << showpos << endl;
    }
}