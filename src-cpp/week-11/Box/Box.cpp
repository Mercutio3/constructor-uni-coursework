/*
CH-230-A
a11_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Box.h"

using namespace std;

//Constructors, copy constructor, and destructor
Box::Box(){
    //Default empty constructor sets everything to 0
    height = width = depth = 0.0;
}

Box::Box(double h, double w, double d){
    //Constructor with properties specified
    height = h;
    width = w;
    depth = d;
}

Box::Box(const Box& b){
    //Copy constructor
    height = b.height;
    width = b.width;
    depth = b.depth;
}

Box::~Box(){}

//Setter methods
void Box::setHeight(double h){
    height = h;
}

void Box::setWidth(double w){
    width = w;
}

void Box::setDepth(double d){
    depth = d;
}

//Getter methods
double Box::getHeight(){
    return height;
}

double Box::getWidth(){
    return width;
}

double Box::getDepth(){
    return depth;
}