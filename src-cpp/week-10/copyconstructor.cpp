/*
CH-230-A
a10_p7.cpp
Santiago Dominguez
9 November 2022
Demonstrates usage of copy constructors, function calling via values and reference
*/

#include <iostream>
#include <cstring>  // standard C string.h header file

using namespace std;

/*
	Naive string: the goal is to illustrate how copy constructors 
	should be handled. See also charbuffer.cpp
*/

class NaiveString {
private:
	char *str;
public:
	NaiveString(const char*);
	NaiveString(const NaiveString&);
	void update(char, char);
	void print();
	void funcByRef(NaiveString&);
	~NaiveString();
};

NaiveString::NaiveString(const char* t) {
	cout << "default constructor called" << endl;
	str = new char[strlen(t) + 1];
	strcpy(str, t);
}

NaiveString::NaiveString(const NaiveString& src) {
	//Copy constructor: creates new instance of naive string starting from an existing one
	cout << "Copy constructor being called" << endl;
	str = new char[strlen(src.str) + 1];
	strcpy(str, src.str);
	//We can access src.str even if it is private as we are inside the NaiveString class
}

void NaiveString::update(char oldchar, char newchar) {
	//Replaces occurrences of oldchar by newchar
	unsigned int i;
	for (i = 0; i < strlen(str); i++) 
		if (str[i] == oldchar)
			str[i] = newchar;
}

void NaiveString::print() {
	cout << str << endl;
}

NaiveString::~NaiveString() {
	delete[] str;
}

void funcByVal(NaiveString s) {
	//Calls update method
	cout << "funcbyval() being called" << endl;
	s.update('B', 'C');
	s.print();
}

void funcByRef(NaiveString &s){
	//Calls update method using reference
	cout << "funcbyref() being called" << endl;
	s.update('B', 'C');
	s.print();
}

int main(int argc, char** argv){
	//Test both funcByVal and funcByRef
	
	NaiveString a("aBcBdB");
	a.print();
	cout << "About to call funcbyval()" << endl;
	funcByVal(a);
	a.print();

	NaiveString b("aBcBdB");
	b.print();
	cout << "About to call funcbyref()" << endl;
	funcByRef(b);
	b.print();

	return 0;
}