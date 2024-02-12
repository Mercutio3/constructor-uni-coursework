/*
CH-230-A
a11_p6.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Vector.h"

using namespace std;

int main(int argc, char** argv){
    //Initalize and read number of components
    int numComponents;
    cout << "Enter number of components per vector: ";
    cin >> numComponents;
    double vecArray[numComponents];

    //Vector 1 initialized with default constructor
    Vector v1;

    //Vector 2 initialized with properties & user input
    for(int i = 0; i < numComponents; i++){
        double currComp;
        cout << "Enter component " << i+1 << " of vector 2: ";
        cin >> currComp;
        vecArray[i] = currComp;
    }
    Vector v2(numComponents, vecArray);
    cout << "Vector 2 components:" << endl;
    v2.print();

    //Vector 3 initialized as copy of vector 2
    Vector v3(v2);
    cout << "Vector 3 components:" << endl;
    v3.print();

    //Vector 4 initialized with properties & user input
    for(int i = 0; i < numComponents; i++){
        double currComp;
        cout << "Enter component " << i+1 << " of vector 4: ";
        cin >> currComp;
        vecArray[i] = currComp;
    }
    Vector v4(numComponents, vecArray);
    cout << "Vector 4 components:" << endl;
    v4.print();
    
    //Perform calculations and method calls
    cout << "Norm of vector 2:" << endl << v2.norm() << endl;
    
    cout << "Sum of vectors 2 and 4:" << endl;;
    (v2.add(v4)).print();
    
    cout << "Difference between vectors 2 and 4:" << endl;
    (v2.difference(v4)).print();
    
    cout << "Scalar product of vectors 2 and 4:" << endl << v2.scalProd(v4) << endl;

    return 0;
}