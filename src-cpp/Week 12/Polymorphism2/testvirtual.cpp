/*
CH-230-A
a12_p7.cpp
Santiago Dominguez
sdominguez@jacobs-university.de

Class relation diagram:

Area---+----Rectangle--+--Square
        \
		 +--Circle---+---Ring
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

double random01();
double random02();

const int num_obj = 25;
int main(int argc, char** argv) {
	//Set seed for random number generator
	unsigned int seed;
	cout << "Provide a random seed: ";
	cin >> seed;
	srandom(seed);

	//Initialize area object pointer array
	Area* list[num_obj];

	//Create objects randomly and add them to array
	for(int i = 0; i < num_obj; i++){
		string thisColor;
		double colorRand = random01();
		if(colorRand < 0.25) {
			thisColor = "RED";
		} else if (colorRand < 0.5){
			thisColor = "BLACK";
		} else if (colorRand < 0.75){
			thisColor = "VIOLET";
		} else {
			thisColor = "BLUE";
		}
		
		double thisRand = random01();
		if (thisRand < 0.25){
			double ringOne = random02();
			double ringTwo = random02();
			if(ringOne < ringTwo){
				list[i] = new Ring(thisColor.c_str(), ringTwo, ringOne);
			} else{
				list[i] = new Ring(thisColor.c_str(), ringOne, ringTwo);
			}
		} else if (thisRand < 0.5){
			list[i] = new Circle(thisColor.c_str(), random02());
		} else if (thisRand < 0.75){
			list[i] = new Rectangle(thisColor.c_str(), random02(), random02());
		} else {
			list[i] = new Square(thisColor.c_str(), random02());
		}
	}

	//Calculate area and perimeter of each object and print it
	for(int i = 0; i < num_obj; i++){
		cout << "Object " << i+1;
		list[i]->getColor();
		cout << endl;
		cout << list[i]->calcArea() << endl;
		cout << list[i]->calcPerimeter() << endl << endl;
		delete list[i];
	}

	return 0;
}

double random01(){
	return (double)random() / RAND_MAX;
}

double random02() {
	return (double(rand()) / (double(RAND_MAX) + 5.0))*100;
}