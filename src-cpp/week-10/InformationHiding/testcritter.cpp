/*
CH-230-A
a10_p5.cpp
Santiago Dominguez
9 November 2022
Creates critters with combinations of defaults and user-set attributes
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	//Critter that wil use empty constructor
	Critter cOne;
	//Hunger must be set using setter method
	cOne.setHunger(2);
	cOne.print();
	cout << endl;
	
	//Critter that's only given a name
	Critter cTwo("Johnny");
	//Hunger must be set using setter method
	cTwo.setHunger(2);
	cTwo.print();
	cout << endl;
	
	//Critter given name, hunger, and boredom (will use default height 10)
	Critter cThree("Pepe", 2, 4);
	//Hunger is already set to 2 via constructor
	cThree.print();
	cout << endl;
	
	//Critter given name, hunger, boredom, and height
	Critter cFour("Gaga", 2, 5, 15.0);
	//Hunger is already set to 2 via constructor
	cFour.print();
	cout << endl;

	//Another critter given name, hunger, boredom, and height
	Critter cFive("Poopoo", 2, 134, 4.5);
	//Hunger is already set to 2 via constructor
	cFive.print();
	
    return 0;
}