/*
CH-230-A
a13_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main(int argc, char** argv) {
    //Open both input files, check if opened correctly
    ifstream in("in1.txt");
    if(!in.good()){
        cerr << "Error opening input file 1" << endl;
        exit(1);
    }
    ifstream in2("in2.txt");
    if(!in2.good()){
        cerr << "Error opening input file 2" << endl;
        exit(2);
    }

    //Open output file, check if opened correctly
    ofstream out("output.txt");
    if(!out.good()){
        cerr << "Error opening output file" << endl;
        exit(3);
    }

    //Initialize floats, read values from input files
    float r, i, r2, i2;
    in >> r >> i;
    in2 >> r2 >> i2;

    //Initialize complex number objects
    Complex c1(r,i);
    Complex c2(r2,i2);
    Complex c3;

    //Print out the two numbers with overloaded <<
    cout << endl;
    cout << "Two complex numbers read from files: " << endl;
    cout << c1;
    cout << c2;
    cout << endl;
    
    //Add the two numbers and print sum
    c3 = c1 + c2;
    out << "Sum of the two numbers: " << c3 << endl;
    cout << "Sum of the two numbers: " << c3 << endl;

    //Subtract the two numbers and print difference
    c3 = c1 - c2;
    out << "Difference between the two numbers: " << c3 << endl;
    cout << "Difference between the two numbers: " << c3 << endl;

    //Mulitply the two numbers and print proeuct
    c3 = c1 * c2;
    out << "Product of the two numbers: " << c3 << endl;
    cout << "Product of the two numbers: " << c3 << endl;

    //Quick demo of the = operator
    Complex c4 = c3;
    cout << "Quick demo of = operator: ";
    cout << c4;

    //Close files
    in.close();
    in2.close();
    out.close();
	
    return 0;
}