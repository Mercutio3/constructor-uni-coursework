/*
CH-230-A
a12_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"
#include "cmath"

using namespace std; 

//Shape constructors
Shape::Shape(const string& n) : name(n) {
}

Shape::Shape(){
    name = "default_name";
}

Shape::Shape(const Shape& s){
    name = s.name;
}

void Shape::printName() const {
	cout << name << endl;
}

//CenteredShape constructors
CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

CenteredShape::CenteredShape(){
    x = 1.0;
    y = 1.0;
}

CenteredShape::CenteredShape(const CenteredShape& cs){
    x = cs.x;
    y = cs.y;
}

//RegularPolygon constructors
RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon(){
    EdgesNumber = 4;
}

RegularPolygon::RegularPolygon(const RegularPolygon& rp){
    EdgesNumber = rp.EdgesNumber;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

//Hexagon Class constructors, setters, getters, and methods definitions
Hexagon::Hexagon(const string&n, double nx, double ny, double ns, string ncolor) :
    RegularPolygon(n, nx, ny, 6){
        side = ns;
        color = ncolor;
}

Hexagon::Hexagon(){
    side = 5;
    color = "red";
}

Hexagon::Hexagon(const Hexagon& h){
    side = h.side;
    color = h.color;
}

Hexagon::~Hexagon(){}

void Hexagon::setSide(double ns){
    side = ns;
}

void Hexagon::setColor(string ncolor){
    color = ncolor;
}

double Hexagon::getSide(){
    return side;
}

string Hexagon::getColor(){
    return color;
}

double Hexagon::perimeter(){
    return side*6;
}

double Hexagon::area(){
    return ((3*sqrt(3))/2)*pow(side,2);
}