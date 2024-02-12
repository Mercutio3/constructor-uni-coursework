/*
CH-230-A
a10_p4.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

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