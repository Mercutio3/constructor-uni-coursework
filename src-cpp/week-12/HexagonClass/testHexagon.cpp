/*
CH-230-A
a12_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Shapes.h"

using namespace std;

int main(int argc, char** argv){
    //Blue hexagon with side 9
    cout << "Creating blue hexagon with side length 9..." << endl;
    Hexagon hex("BLUEHEX",1,1,9,"blue");

    //Green hexagon with side 15
    cout << "Creating green hexagon with side length 15..." << endl;
    Hexagon hex2("GREENHEX",1,1,15,"green");

    //Copy of the second hexagon
    cout << "Creating copy of hexagon 2..." << endl;
    Hexagon hex3(hex2);

    //Perimeter and area of all three hexagons
    cout << "Perimeter of hexagon 1: " << hex.perimeter() << endl;
    cout << "Area of hexagon 1: " << hex.area() << endl;

    cout << "Perimeter of hexagon 2: " << hex2.perimeter() << endl;
    cout << "Area of hexagon 2: " << hex2.area() << endl;

    cout << "Perimeter of hexagon 3: " << hex3.perimeter() << endl;
    cout << "Area of hexagon 3: " << hex3.area() << endl;

    return 0;
}