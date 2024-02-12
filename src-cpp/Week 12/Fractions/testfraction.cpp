/*
CH-230-A
a12_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "fraction.h"

using namespace std;

int main(void) {
	//Create fraction objects
	Fraction a(4, 2);
	Fraction b(17, 11);
	Fraction c(5);

	//Print fraction objects usingn cout and << operator overloading
    cout << a;
	cout << b;
	cout << c;

	//New fractions d and e created with overloaded >> operator
	Fraction d;
	cin >> d;
	cout << d;
	Fraction e;
	cin >> e;
	cout << e;

	//New fractions created using overriden operator operations
	Fraction f = d * e;
	cout << "Product of two fractions: " << f;
	Fraction g = d / e;
	cout << "Divison of two fractions: " << g;
	Fraction h = d + e;
	cout << "Addition of two fractions: " << h;
	Fraction i = d - e;
	cout << "Subtraction of two fractions: " << i;

	//Comparing fractions
	if(d < e){
		cout << "First fraction is smaller than second" << endl;
	} else {
		cout << "First fraction is larger than second" << endl;
	}
}