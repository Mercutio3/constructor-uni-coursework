/*
CH-231-A 
a1_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <string>

using namespace std;

class Complex{
    private:
        double re, im;
    public:
        Complex(double re, double im){
            this->re = re;
            this->im = im;
        }
        void operator=(const Complex co){
            this->re = co.re;
            this->im = co.im;
        }
        bool operator==(const Complex co){
            if(this->re == co.re && this->im == co.im){
                return true;
            } else {
                return false;
            }
        }
        Complex operator+(const Complex co){
            return Complex(this->re + co.re, this->im + co.im);
        }
        friend ostream& operator<<(ostream &o, Complex co){
            o << co.re << "+" << co.im << "i" << endl;
            return o;
        }
};

template <class T>
int array_search(T arr[], int size, T search){
    //Simple for loop checks every element to see if it matches
    for(int i = 0; i < size; i++){
        if(arr[i] == search){
            return i;
        }
    }
    return -1;
}

int main(){
    //Create and test int array
    int iArray[] = {1,2,3,4,5};
    cout << "Int element index: " << array_search(iArray, 5, 3) << endl;
    //Second case where int is not found
    cout << "Int element index: " << array_search(iArray, 5, 1231) << endl;

    //Create and test double array
    double dArray[] = {1.1,2.2,3.3,4.4,5.5};
    cout << "Double element index: " << array_search(dArray, 5, 3.3) << endl;

    //Create and test string array
    string sArray[] = {"mit","karte","bitte"};
    cout << "String element index: " << array_search(sArray, 3, std::string("karte")) << endl;

    //Create and test complex array
    Complex cArray[] = {Complex(1,2), Complex(3,4), Complex(-3,-5)};
    cout << "Complex element index: " << array_search(cArray, 3, Complex(1,2)) << endl;

    return 0;
}