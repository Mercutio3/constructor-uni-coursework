/*
CH-230-A
a10_p2.cpp
Santiago Dominguez
7 November 2022
Creates a critter with attributes read from user-input and prints them
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv){
	Critter c;

	string name;
	int hunger;
	int age;
	int boredom;
	double height;
	float weight;
 
	cout << endl << "Please enter data: " << endl;
	cout << "Name: "; // Will not work if name contains spaces
	getline(cin, name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);

	cout << "Age: ";
	cin >> age;
	c.setAge(age);

	cout << "Boredom: ";
	cin >> boredom;
	c.setBoredom(boredom);

	cout << "Height: ";
	cin >> height;
	c.setHeight(height);

	cout << "Weight: ";
	cin >> weight;
	c.setWeight(weight);

	cout << "You have created:" << endl;
	c.print();
        return 0;
}