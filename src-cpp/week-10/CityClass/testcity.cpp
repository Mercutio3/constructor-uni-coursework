/*
CH-230-A
a10_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
Defines three cities, sets their properties, and prints them
*/

#include <iostream>
#include <cstdlib>
#include "City.h"

using namespace std;

int main(int argc, char** argv){
    City Bremen;
    City Paris;
    City London;

    //Set properties for "Bremen"
    Bremen.setName("Bremen");
    Bremen.setPop(569352);
    Bremen.setMayor("Andreas Bovenschulte");
    Bremen.setArea(326.7);

    //Set properties for "Paris"
    Paris.setName("Paris");
    Paris.setPop(2161000);
    Paris.setMayor("Anne Hidalgo");
    Paris.setArea(105.4);

    //Set properties for "London"
    London.setName("London");
    London.setPop(8982000);
    London.setMayor("Sadiq Khan");
    London.setArea(1572.0);

    //Print information for the three cities
    cout << "First city:" << endl;
    Bremen.print();

    cout << "Second city:" << endl;
    Paris.print();

    cout << "Third city:" << endl;
    London.print();

    return 0;
}