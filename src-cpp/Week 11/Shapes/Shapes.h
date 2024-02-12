/*
CH-230-A
a11_p5.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  
        void setName(std::string nname);
        std::string getName();
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center
        void setX(double nx);
        double getX();
        void setY(double ny);
        double getY();
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);
        void setEdges(int nl);
        int getEdges();
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);
        void setRadius(double nr);
        double getRadius();
        double perimeter();
        double area();
};

class Rectangle : public RegularPolygon {
    private:
        double width;
        double height;
    public:
        Rectangle(const std::string& n, double nx, double ny, double nwidth, 
        double nheight);
        Rectangle();
        Rectangle(const Rectangle&);
        void setWidth(double nw);
        double getWidth();
        void setHeight(double nh);
        double getHeight();
        double perimeter();
        double area();
};

class Square : public Rectangle {
    private:
        double side;
    public:
        Square(const std::string& n, double nx, double ny, double nside);
        Square();
        Square(const Square&);
        void setSides(double ns);
        double getSide();
};
    
#endif