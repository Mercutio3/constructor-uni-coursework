/*
CH-230-A
a11_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Creature.h"

using namespace std;

int main(int argc, char** argv){ 
    //Create the four creatures and test properties

    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating a Jacobs Student.\n";
    JacobsStudent j;
    j.run();
    j.suffer();

    cout << "\nCreating a Mexican.\n";
    Mexican m;
    m.run();
    m.drinkTequila();

    cout << endl;

    return 0;
} 