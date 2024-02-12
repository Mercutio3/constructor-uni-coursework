/*
CH-230-A
a10_p4.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Critter.h"

using namespace std;

Critter::Critter(){
	//Constructor for critter given no properties, will use all defaults
	cout << "Creating critter with no properties..." << endl;
    name = "default_critter";
	height = 5.0;
	hunger = 0;
	boredom = 0;
}

Critter::Critter(string newName){
	//Constructor for critter given only name, rest will be defaults
	cout << "Creating critter with only name specified..." << endl;
	name = newName;
	height = 5.0;
	hunger = 0;
	boredom = 0;
}

Critter::Critter(string newName, int newHunger, int newBoredom, double newHeight){
	//Constructor for critter given all four properties
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

void Critter::print() {
	//Modified print method so that it prints all four properties.
	cout << "I am " << name << ". My hunger level is " << hunger;
	cout << ". My boredom level is " << boredom << ". My height is ";
	cout << height << "." << endl;
}

//Getter methods
int Critter::getHunger() {
	return hunger;
}