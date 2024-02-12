/*
CH-230-A
a13_p2.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {

private:
    float real;  // real part
    float imag;  // imaginary part

public:
    //Constructors, both empty and with values taken
    Complex();
    Complex(float, float = 0);

    //Operation methods
    Complex conjugate();
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);

    //Overloading =, <<, >>, *, /, +, and -
    Complex operator+ (const Complex&);
    Complex operator- (const Complex&);
    Complex operator* (const Complex&);
    Complex& operator= (const Complex&);
    friend std::ostream& operator<<(std::ostream& out, const Complex& co);
    friend std::istream& operator>>(std::istream& in, const Complex& co);

    //Setter methods
    void setReal(float r);
    void setImag(float i);

    //Print method
	void print();
};

#endif