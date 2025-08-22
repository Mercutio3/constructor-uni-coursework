/*
CH-230-A
a10_p6.cpp
Santiago Dominguez
9 November 2022
Implements getter, setter, constructor, and operation methods for critter class
*/

#include <iostream>
#include "Critter.h"

using namespace std;

//Constructor for critter given no properties, will use all defaults
Critter::Critter(){
	cout << "Creating critter with no properties..." << endl;
    name = "default_critter";
	height = 5.0;
	hunger = intToDouble(0);
	boredom = 0;
}

//Constructor for critter given only name, rest will be defaults
Critter::Critter(string newName){
	cout << "Creating critter with only name specified..." << endl;
	name = newName;
	height = 5.0;
	hunger = intToDouble(0);
	boredom = 0;
	thirst = hunger;
}

//Constructor for critter given all four properties
Critter::Critter(string newName, int newHunger, int newBoredom, double newHeight){
	cout << "Creating critter with all properties specified..." << endl;
	name = newName;
	hunger = intToDouble(newHunger);
	boredom = newBoredom;
	height = newHeight;
	thirst = hunger;
}

//Constructor for critter given all four properties
Critter::Critter(string newName, int newHunger, int newBoredom, double newHeight, double newThirst){
	cout << "Creating critter with all properties specified..." << endl;
	name = newName;
	hunger = intToDouble(newHunger);
	boredom = newBoredom;
	height = newHeight;
	thirst = newThirst;
}

//Setter methods
void Critter::setName(string& newname) {
	name = newname;
}
void Critter::setHunger(int newhunger) {
	hunger = intToDouble(newhunger);
	setThirst(newhunger);
}

void Critter::setThirst(int newthirst) {
	thirst = intToDouble(newthirst);
}

//Modified print method so that it prints all four properties.
void Critter::print() {
	int retHung = getHunger();
	cout << "I am " << name << ". My hunger level is " << retHung;
	cout << " and my thirst level is ";
	printf("%0.1lf", thirst);
	cout << ". My boredom level is " << boredom << ". My height is ";
	cout << height << "." << endl;
}

double Critter::intToDouble(int x){
	return (double)x/10.0;
}

int Critter::doubleToInt(double x){
	return (int)(x*10.0);
}

//Getter methods
int Critter::getHunger() {
	return doubleToInt(hunger);
}