/*
CH-230-A
a10_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "City.h"

using namespace std;

//Define setter methods
void City::setName(std::string newName){
    name = newName;
}

void City::setPop(int newPop){
    population = newPop;
}

void City::setMayor(std::string newMayor){
    mayor = newMayor;
}

void City::setArea(double newArea){
    area = newArea;
}

//Define getter methods
int City::getPop(){
    return population;
}

double City::getArea(){
    return area;
}

//Define print method
void City::print(){
    cout << name << " is a city with " << population << " inhabitants. ";
    cout << "It covers an area of " << area << " km^2 and its mayor is ";
    cout << mayor << "." << endl;
    cout << endl;
}