/*
CH-230-A
a12_p7.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(const char *n, double a) : Area(n) {
	radius = a;
}

Circle::~Circle() {
}

double Circle::calcArea() const {
	std::cout << "calcArea of Circle...";
	return radius * radius * M_PI;
}

//Calculate perimeter of a circle (circumference)
double Circle::calcPerimeter() const {
	std::cout << "calcPerimeter of Circle...";
	return 2 * M_PI * radius;
}
