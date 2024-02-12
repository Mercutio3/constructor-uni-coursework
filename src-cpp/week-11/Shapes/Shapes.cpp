/*
CH-230-A
a11_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"
#include <cmath> //Used for pi in the calculation of circum. and area of circle

using namespace std; 

//Shape constructors, setters, getters, and methods
Shape::Shape(const string& n) : name(n) {
    setName(n);
}

Shape::Shape(){
    setName("default_name");
}

Shape::Shape(const Shape& s){
    name = s.name;
}

void Shape::setName(string nname){
    name = nname;
}

string Shape::getName(){
    return name;
}

void Shape::printName() const {
	cout << name << endl;
}

//CenteredShape constructors, setters, getters, and methods
CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

CenteredShape::CenteredShape(){
    setX(1.0);
    setY(1.0);
}

CenteredShape::CenteredShape(const CenteredShape& cs){
    x = cs.x;
    y = cs.y;
}

void CenteredShape::setX(double nx){
    x = nx;
}

void CenteredShape::setY(double ny){
    y = ny;
}

double CenteredShape::getX(){
    return x;
}

double CenteredShape::getY(){
    return y;
}

//RegularPolygon constructors, setters, getters, and methods
RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) {
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon(){
    setEdges(4);
}

RegularPolygon::RegularPolygon(const RegularPolygon& rp){
    EdgesNumber = rp.EdgesNumber;
}

void RegularPolygon::setEdges(int nl){
    EdgesNumber = nl;
}

int RegularPolygon::getEdges(){
    return EdgesNumber;
}

//Circle constructors, setters, getters, and methods
Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) {
	Radius = r;
}

Circle::Circle(){
    setRadius(1.0);
}

Circle::Circle(const Circle& c){
    Radius = c.Radius;
}

void Circle::setRadius(double nr){
    Radius = nr;
}

double Circle::getRadius(){
    return Radius;
}

double Circle::perimeter(){
    return Radius*2*M_PI;
}

double Circle::area(){
    return (Radius*Radius)*M_PI;
}

//Rectangle constructors, setters, getters, and methods
Rectangle::Rectangle(const string& n, double nx, double ny, double nwidth,
 double nheight) : RegularPolygon(n, nx, ny, 4){
        width = nwidth;
        height = nheight;
}

Rectangle::Rectangle(){
    setWidth(1.0);
    setHeight(1.0);
}

Rectangle::Rectangle(const Rectangle& r){
    width = r.width;
    height = r.height;
}

void Rectangle::setWidth(double nw){
    width = nw;
}

void Rectangle::setHeight(double nh){
    height = nh;
}

double Rectangle::getWidth(){
    return width;
}

double Rectangle::getHeight(){
    return height;
}

double Rectangle::perimeter(){
    return (width*2)+(height*2);
}

double Rectangle::area(){
    return width*height;
}

//Square constructors, setters, getters, and methods
Square::Square(const std::string& n, double nx, double ny, double nside) :
    Rectangle(n, nx, ny, nside, nside){
        
}

Square::Square(){
    setSides(1.0);
}

Square::Square(const Square& sq){
    
}

void Square::setSides(double ns){
    setWidth(ns);
    setHeight(ns);
}

double Square::getSide(){
    return getWidth();
}