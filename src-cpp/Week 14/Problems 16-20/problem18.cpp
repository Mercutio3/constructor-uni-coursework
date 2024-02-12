#include <iostream>

using namespace std;

class Complex {
    private:
        float real;  // real part
        float imag;  // imaginary part
    public:
        Complex();
        Complex(float, float = 0);
        double magnitude();
        void print();
        friend ostream& operator<<(ostream& out, const Complex& co);
        bool operator>(Complex& co);
        bool operator<(Complex& co);
};

ostream& operator<<(ostream& out, const Complex& co){
    if (co.imag)
        out << noshowpos << co.real << showpos << co.imag << "i" << endl;
    else
        out << noshowpos << co.real << endl;
}

bool Complex::operator>(Complex& co){
    if(this->magnitude() > co.magnitude()){
        return true;
    } else {
        return false;
    }
}

bool Complex::operator<(Complex& co){
    if(this->magnitude() < co.magnitude()){
        return true;
    } else {
        return false;
    }
}

void Complex::print() {
    if (imag)
        cout << noshowpos << real << showpos << imag << "i" << endl;
    else
        cout << noshowpos << real << endl;
}