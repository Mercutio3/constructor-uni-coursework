/*
CH-230-A
a12_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "fraction.h"

using namespace std;

Fraction::Fraction(){
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d){
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b){
	int gcd;
	if(a < b){
		int temp = b;
		b = a;
		a = temp;
	}
	for(int i = 1; i < b; i++){
		if(a%i == 0 && b%i == 0){
			gcd = i;
		}
	}

	return gcd;
}

int Fraction::lcm(int a, int b){
	return a * b / gcd(a, b);
}

void Fraction::print() {
	std::cout << num << "/" << den << std::endl;
}

//Overloading <<, >>, *, /, +, and -
ostream& operator<<(ostream& out, const Fraction& fr){
	out << fr.num << "/" << fr.den << endl;
	
	return out;
}

istream& operator>>(istream& in , Fraction& fr){
	cout << "Enter numerator: ";
	in >> fr.num;
	cout << "Enter denominator: ";
	in >> fr.den;
	
	return in;
}

Fraction Fraction::operator* (const Fraction& fr) const{
	Fraction result((this->num * fr.num), (this->den * fr.den));
	return result;
}

Fraction Fraction::operator/ (const Fraction& fr) const{
	Fraction result((this->num * fr.den), (this->den * fr.num));
	return result;
}

Fraction Fraction::operator+ (const Fraction& fr) {
	Fraction result((((this->num * lcm(this->den, fr.den)) / this->den) + 
		((fr.num * lcm(this->den, fr.den)) / fr.den)),(lcm(this->den, fr.den))); 
	return result;
}

Fraction Fraction::operator- (const Fraction& fr) {
	Fraction result((((this->num * lcm(this->den, fr.den)) / this->den) - 
		((fr.num * lcm(this->den, fr.den)) / fr.den)),(lcm(this->den, fr.den)));
	return result;
}

bool Fraction::operator< (const Fraction& fr) {
	double first, second;
	first = (double)this->num / this->den;
	second = (double)fr.num / fr.den;
	if(first < second){
		return true;
	} else {
		return false;
	}
}

bool Fraction::operator> (const Fraction& fr) {
	double first, second;
	first = (double)this->num / this->den;
	second = (double)fr.num / fr.den;
	if(first > second){
		return true;
	} else {
		return false;
	}
}