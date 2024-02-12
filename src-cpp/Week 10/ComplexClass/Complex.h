/*
CH-230-A
a10_p8.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

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

    //Setter methods
    void setReal(float r);
    void setImag(float i);

    //Print method
	void print();
};