/*
CH-230-A
a12_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"

using namespace std;

int main(int argc, char** argv){
    //Default TournamentMember with no given parameters
    TournamentMember one;
    one.printInfo();

    //TournamentMember with given parameters
    TournamentMember two("Tonald", "Drump", "1945-30-03", 3, 2);
    two.printInfo();

    //Copy constructor demonstration
    TournamentMember three(one);
    three.printInfo();

    //Setter + getter demo
    three.setFirstName("Otto");
    cout << "Name retrieved using getter: " << three.getFirstName() << endl << endl;

    //Location changed from first instance, which affects all instances.
    one.changeLocation("Hamburg");
    two.printInfo();

    return 0;
}