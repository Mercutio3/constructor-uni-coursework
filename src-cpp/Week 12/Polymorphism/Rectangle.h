/*
CH-230-A
a12_p6.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Area.h"

class Rectangle : public Area {
	public:
		Rectangle(const char *n, double a, double b);
		~Rectangle();
		double calcArea() const;
		double calcPerimeter() const;
	private:
		double length;
		double width;
};

#endif
