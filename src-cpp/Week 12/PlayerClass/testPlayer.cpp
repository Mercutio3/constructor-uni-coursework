/*
CH-230-A
a12_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"

using namespace std;

int main(int argc, char** argv){
    //Player one (no parameters)
    Player one;
    one.printInfo();
    
    //Player two (given parameters)
    Player two("Muhammad","Ali","1977-08-20",10,7,22,"midfielder",1,true);
    two.printInfo();

    //Player three (copy of player2)
    Player three(two);
    three.printInfo();

    //Move all players to location "Hamburg"
    one.changeLocation("Hamburg");

    //Print player two info again to show location change and goal increase.
    two.increaseGoals();
    two.printInfo();

    return 0;
}