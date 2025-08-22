/*
CH-230-A
a10_p2.h
Santiago Dominguez
7 November 2022
Header file defining variables and methods for critter class
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

	//New properties of my chocie
	int age;
	float weight;

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setHeight(double newheight);
	void setAge(int newage);
	void setWeight(float newweight);
	// getter method
	int getHunger();
	int getBoredom();
	double getHeight();
	int getAge();
	float getWeight();
	// service method
	void print();
};