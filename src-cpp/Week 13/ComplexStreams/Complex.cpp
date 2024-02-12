/*
CH-230-A
a13_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {
    //Default empty constructor sets everything to 0
    real = imag = 0;
    cout << "Empty constructor called." << endl;
}
Complex::Complex(float r, float i){
    //Constructor taking one or two values and setting them.
    real = r;
    imag = i;
    cout << "Constructor taking one or both values called." << endl;
}

Complex Complex::conjugate(){
    //Calculate conjugate of a complex number
    float returnImag = 0 - imag;

    return Complex(real, returnImag);
}

Complex Complex::add(Complex secondNum){
    //Calculate sum of two numbers and return result 
    float returnReal = real + secondNum.real;
    float returnImag = imag + secondNum.imag;

    return Complex(returnReal, returnImag);
}

Complex Complex::subtract(Complex secondNum){
    //Calculate difference between two numbers and return result 
    float returnReal = real - secondNum.real;
    float returnImag = imag - secondNum.imag;

    return Complex(returnReal, returnImag);
}

Complex Complex::multiply(Complex secondNum){
    //Calculate product of two numbers and return result 
    float returnReal = (real * secondNum.real) - (imag * secondNum.imag);
    float returnImag = (imag * secondNum.real) + (real * secondNum.imag);

    return Complex(returnReal, returnImag);
}

//Operator overloading methods
Complex Complex::operator+ (const Complex& co) {
    Complex result = add(co);
    return result;
}

Complex Complex::operator- (const Complex& co) {
    Complex result = subtract(co);
    return result;
}

Complex Complex::operator* (const Complex& co) {
    Complex result = multiply(co);
    return result;
}

Complex& Complex::operator= (const Complex& co) {
    this->real = co.real;
    this->imag = co.imag;
    return *this;
}

ostream& operator<<(ostream& out, const Complex& co){
    if(co.imag){
        out << noshowpos << co.real << showpos << co.imag << "i" << endl;
    } else {
        out << noshowpos << co.real << showpos << endl;
    }

    return out;
}

istream& operator>>(istream& in, const Complex& co){
    cout << "Enter real part: ";
    in >> co.real;
    cout << "Enter imaginary part: ";
    in >> co.imag;

    return in;
}

//Setter methods
void Complex::setReal(float r){
    real = r;
}
void Complex::setImag(float i){
    imag = i;
}

void Complex::print() {
    //Print the complex number with cout
    if(imag){
        cout << noshowpos << real << showpos << imag << "i" << endl;
    } else {
        cout << noshowpos << real << showpos << endl;
    }
}