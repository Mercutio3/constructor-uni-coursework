/*
CH-230-A
a10_p5.h
Santiago Dominguez
9 November 2022
Definines variables, constructors, and methods for critter class, with private methods
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	double hunger;
	int boredom;
	double height;

	//Double <-> Int conversion methods for hunger
	double intToDouble(int x);
	int doubleToInt(double x);

public: // business logic methods are public
	//Constructor declarations
	Critter();
	Critter(std::string name);
	Critter(std::string name, int hunger, int boredom, double = 10.0);

	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	// getter method
	int getHunger();
	// service method
	void print();
};