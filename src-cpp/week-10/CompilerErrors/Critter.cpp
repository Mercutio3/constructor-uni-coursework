/*
CH-230-A
a10_p2.cpp
Santiago Dominguez
9 November 2022
Implements getter, setter, and operation methods for critter class
*/

#include <iostream>
#include "Critter.h"

using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setBoredom(int newboredom) {
	boredom = newboredom;
}

void Critter::setHeight(double newheight) {
	height = newheight;
}

void Critter::setAge(int newage) {
	age = newage;
}

void Critter::setWeight(float newweight) {
	weight = newweight;
}

int Critter::getHunger() {
	return hunger;
}

int Critter::getBoredom() {
	return boredom;
}

double Critter::getHeight() {
	return height;
}

int Critter::getAge() {
	return age;
}

float Critter::getWeight() {
	return weight;
}

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << ". ";
	cout << "I am " << age << " years old. My boredom level is " << boredom << ". ";
	cout << "I am " << height << " meters tall and weigh " << weight << " kilograms." << endl;
}
