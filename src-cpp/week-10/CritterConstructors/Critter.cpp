/*
CH-230-A
a10_p4.cpp
Santiago Dominguez
8 November 2022
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
	hunger = 0;
	boredom = 0;
}

//Constructor for critter given only name, rest will be defaults
Critter::Critter(string newName){
	cout << "Creating critter with only name specified..." << endl;
	name = newName;
	height = 5.0;
	hunger = 0;
	boredom = 0;
}

//Constructor for critter given all four properties
Critter::Critter(string newName, int newHunger, int newBoredom, double newHeight){
	cout << "Creating critter with all properties specified..." << endl;
	name = newName;
	hunger = newHunger;
	boredom = newBoredom;
	height = newHeight;
}

//Setter methods
void Critter::setName(string& newname) {
	name = newname;
}
void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

//Modified print method so that it prints all four properties
void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger;
	cout << ". My boredom level is " << boredom << ". My height is ";
	cout << height << "." << endl;
}

//Getter methods
int Critter::getHunger() {
	return hunger;
}