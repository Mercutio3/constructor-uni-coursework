/*
CH-230-A
a12_p7.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(const char *n, double a, double b) : Area(n) {
    length = a;
    width = b;
}

Rectangle::~Rectangle() {
}

double Rectangle::calcArea() const {
	std::cout << "calcArea of Rectangle...";
	return length*width;
}

//Caculate perimeter of a rectangle
double Rectangle::calcPerimeter() const {
    std::cout << "calcPerimeter of Rectangle...";
    return (2*length) + (2*width);
}