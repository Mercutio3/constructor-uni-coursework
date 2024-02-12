/*
CH-230-A
a13_p8.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

//Class definitions
class Garage {
    public:
        Garage();
};

class Car {
    public:
        Car();
};

class Motor {
    public:
        Motor();
};

//Class default constructors
Garage::Garage(){
    try{
        //Try creation of car
        Car aCar;
    } catch(const char* motEx){
        //Catch exception from car and print it
        cerr << motEx << endl;
    }
    //Throw separate exception to be caught in main()
    throw "The car in this garage has problems with motor";
}

Car::Car(){
    try{
        //Try creation of motor (will create exception)
        Motor mot;
    } catch(const char* motEx){
        //Catch exception from motor, throw it to garage
        throw motEx;
    }
}

Motor::Motor(){
    //Throw exception back to car class
    throw "This motor has problems";
}

int main(int argc, char** argv){
    try {
        //Try creation of garage (will create exception)
        Garage gar;
    } catch(const char* ex) {
        //Catch exception and print it
        cerr << ex << endl;
        exit(1);
    }

    return 0;
}