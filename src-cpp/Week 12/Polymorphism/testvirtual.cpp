/*
CH-230-A
a12_p6.cpp
Santiago Dominguez
sdominguez@jacobs-university.de

Class relation diagram:

Area---+----Rectangle--+--Square
        \
		 +--Circle---+---Ring
 */

#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"
 
const int num_obj = 7;
int main(int argc, char** argv) {
	Area *list[num_obj];						// (1) Array of area object pointers is created
	int index = 0;								// (2) Int index initialized to 0
	double sum_area = 0.0;
	double sum_perim = 0.0;			// (3) Double area sum initialized to 0.0
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4) Creation of objects with parameters
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	cout << "Creating Square: ";
	Square brown_square("BROWN", 3);
	list[0] = &blue_ring;						// (5) Assigning memory adresses to pointers
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	list[6] = &brown_square;
	while (index < num_obj) {					// (7) Loop through pointer array once
		(list[index])->getColor();				
		double area = list[index]->calcArea();// (8) Calculate area of each pointer's object
		sum_area += area;
		double perim = list[index++]->calcPerimeter();// (8) Calculate perim of each pointer's object
		sum_perim += perim;
	}
	cout << "\nThe total area is "
			<< sum_area << " units " << endl;	// (9) Print total area and perimeter 
	cout << "\nThe total perimeter is "
			<< sum_perim << " units " << endl;
	return 0;
}
