#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Object3D{
    private:
        string name;
    public:
        Object3D(string);
        virtual double volume(){
            return -1;
        }
};

Object3D::Object3D(string nName){
    name = nName;
}

class Sphere : public Object3D{
    private:
        double radius;
    public:
        Sphere(string, double);
        double volume() ;
};

class Cylinder : public Object3D{
    private:
        double radius;
        double height;
    public:
        Cylinder(string, double, double);
        double volume() ;
};

class RectPrism : public Object3D{
    private:
        double width;
        double length;
        double height;
    public:
        RectPrism(string, double, double, double);
        double volume() ;
};

class Cube : public RectPrism{
    private:
        double side;
    public:
        Cube(string, double);
        double volume() ;
};

Sphere::Sphere(string nName, double nRadius) : Object3D(nName){
    radius = nRadius;
}

double Sphere::volume() {
    return (4/3)*M_PI*pow(radius,3);
}

Cylinder::Cylinder(string nName, double nRadius, double nHeight) : Object3D(nName){
    radius = nRadius;
    height = nHeight;
}

double Cylinder::volume() {
    return M_PI*pow(radius,2)*height;
}

RectPrism::RectPrism(string nName, double nWidth, double nLength, double nHeight) : Object3D(nName){
    width = nWidth;
    length = nLength;
    height = nHeight;
}

double RectPrism::volume() {
    return width*length*height;
}

Cube::Cube(string nName, double nSide) : RectPrism(nName, nSide, nSide, nSide){
    side = nSide;
}

double Cube::volume() {
    return pow(side,3);
}

int main(int argc, char *argv[]) {
    Object3D *arr[5];
    arr[0] = new Sphere("sphere", 1.3);
    arr[1] = new RectPrism("rectprism", 2.0, 3.0, 4.0);
    arr[2] = new Cylinder("cylinder", 2.0, 1.3);
    arr[3] = new Cube("cube", 2.0);
    arr[4] = new RectPrism("rectprism2", 1.0, 2.0, 3.5);
    for(int i=0; i<5; i++)
        cout << arr[i]->volume() << endl;
    for(int i=0; i<5; i++)
        delete arr[i];
    return 0;
}