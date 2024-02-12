/*
CH-230-A
a11_p4.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Creature.h"

using namespace std;

//Creature constructor
Creature::Creature(): distance(10){
    cout << "Creature default constructor called." << endl;
}    

//Creature method using properties
void Creature::run() const{ 
    cout << "running " << distance << " meters!\n";
}  

//Creature destructor
Creature::~Creature(){
    cout << "Creature destructor called." << endl;
}

//Wizard constructor
Wizard::Wizard() : distFactor(3){
    cout << "Wizard default constructor called." << endl;
}  

//Wizard method using properties
void Wizard::hover() const{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

//Wizard destructor
Wizard::~Wizard(){
    cout << "Wizard destructor called." << endl;
}

//JacobsStudent constructor
JacobsStudent::JacobsStudent() : sufferTime(4) {
    cout << "JacobsStudent default constructor called." << endl;
}

//JacobsStudent method using properties
void JacobsStudent::suffer() const{
    cout << "suffering for " << (distance * sufferTime) << " hours!\n";
}

//Jacobsstudent destructor
JacobsStudent::~JacobsStudent(){
    cout << "JacobsStudent destructor called." << endl;
}

//Mexican constructor
Mexican::Mexican() : tequilaShots(5) {
    cout << "Mexican default constructor called." << endl;
}

//Mexican method using properties
void Mexican::drinkTequila() const{
    cout << "drinking " << (distance/tequilaShots) << " shots of tequila!\n";
}

//Mexican destructor
Mexican::~Mexican(){
    cout << "Mexican destructor called." << endl;
}