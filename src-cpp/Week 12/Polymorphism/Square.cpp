/*
CH-230-A
a12_p6.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <cmath>
#include "Square.h"

Square::Square(const char *n, double side) : Rectangle(n, side, side){
    sSide = side;
}

Square ::~Square() {
}

double Square::calcArea() const {
	std::cout << "calcArea of Square...";
	return sSide*sSide;
}

//Calcualte perimeter of square
double Square::calcPerimeter() const {
    std::cout << "calcPerimeter of Square...";
	return 4*sSide;
}