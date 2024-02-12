#include <iostream>
#include <cmath>
#include "Ring.h"

Ring::Ring(const char *n, double outer, double inner) 
					: Circle(n, outer) {
	innerradius = inner;
}

Ring::~Ring() {
}

double Ring::calcArea() const {
	std::cout << "calcArea of Ring...";
	return (Circle::calcArea()-
		(innerradius * innerradius * M_PI));
}

//Calcualte perimeter of ring (outer + inner circmference)
double Ring::calcPerimeter() const {
	std::cout << "calcPerimeter of Ring...";
	return 2 * M_PI * (innerradius+radius);
}