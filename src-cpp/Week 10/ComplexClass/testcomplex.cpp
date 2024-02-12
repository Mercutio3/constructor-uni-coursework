/*
CH-230-A
a10_p8.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Complex.h"

using namespace std;

int main(int argc, char** argv) {
    //Initialization of variables and objects
    Complex c1, c2, c3;
    float real, imag;

    //Read keyboard input, create first complex number
    cout << "Enter real part of first number: ";
    cin >> real;
    cout << "Enter imaginary part of first number: ";
    cin >> imag;
    c1.setReal(real);
    c1.setImag(imag);

    //Read keyboard input, create second complex number
    cout << "Enter real part of second number: ";
    cin >> real;
    cout << "Enter imaginary part of second number: ";
    cin >> imag;
    c2.setReal(real);
    c2.setImag(imag);

    //Print out the two numbers entered
    cout << endl;
    cout << "Your two numbers:" << endl;
    c1.print();
    c2.print();
    cout << endl;

    //Calculate conjugate of c1, result stored in c3 and printed
    cout << "Conjugate of first number:" << endl;
    c3 = c1.conjugate();
    c3.print();
    cout << endl;

    //Add c1 and c2, result stored in c3 and printed
    cout << "Sum of the two numbers:" << endl;
    c3 = c1.add(c2);
    c3.print();
    cout << endl;

    //Subtract c2 from c1, result stored in c3 and printed
    cout << "Difference between the two numbers:" << endl;
    c3 = c1.subtract(c2);
    c3.print();
    cout << endl;

    //Multiply c1 and c2, result stored in c3 and printed
    cout << "Product of the two numbers:" << endl;
    c3 = c1.multiply(c2);
    c3.print();
    cout << endl;
	
    return 0;
}