/*
CH-230-A
a11_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Shapes.h"

using namespace std;

int main(int argc, char** argv) {
    //Creating circle with parameters, calling perimeter() and area()
    cout << "Creating circle 'CIRCLE' with x = 1.0, y = 1.0, and r = 3.0" << endl;
    Circle circ("CIRCLE", 1.0, 1.0, 3.0);
    cout << "Perimeter of circle: " << circ.perimeter() << endl;
    cout << "Area of circle: " << circ.area() << endl << endl;

    //Creating rectangle with parameters, calling perimeter() and area()
    cout << "Creating rectangle 'RECT' with x = 1.0, y = 1.0, ";
    cout << "width = 3.0, and height = 4.0" << endl;
    Rectangle rect("RECT", 1.0, 1.0, 3.0, 4.0);
    cout << "Perimeter of rectangle: " << rect.perimeter() << endl;
    cout << "Area of rectangle: " << rect.area() << endl << endl;

    //Creating square with parameters, calling perimeter() and area()
    cout << "Creating square 'SQUARE' with x = 1.0, y = 1.0, ";
    cout << "and side = 3.0" << endl;
    Square sqr("SQUARE", 1.0, 1.0, 3.0);
    cout << "Perimeter of rectangle: " << sqr.perimeter() << endl;
    cout << "Area of rectangle: " << sqr.area() << endl << endl;

    return 0;
}