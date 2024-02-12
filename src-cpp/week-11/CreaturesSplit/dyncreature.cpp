/*
CH-230-A
a11_p4.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Creature.h"

using namespace std;

int main(int argc, char** argv){ 
    while(1){
        //Read user input
        cout << endl << "Enter creature you wish to create: ";
        string cmd;
        getline(cin, cmd);
        
        if(cmd == "wizard"){
            //Create wizard dyamically, execute methods, delete wizard
            cout << "\nCreating a Wizard.\n";
            Wizard* w = new Wizard;
            w->run();
            w->hover();
            delete w;
        } else if (cmd == "object1"){
            //Create JacobsStudent dyamically, execute methods, delete JacobsStudent
            cout << "\nCreating a Jacobs Student.\n";
            JacobsStudent* j = new JacobsStudent;
            j->run();
            j->suffer();
            delete j;
        } else if (cmd == "object2"){
            //Create Mexican dyamically, execute methods, delete Mexican
            cout << "\nCreating a Mexican.\n";
            Mexican* m = new Mexican;
            m->run();
            m->drinkTequila();
            delete m;
        } else if (cmd == "quit"){
            //Quit program
            exit(1);
        } else {
            cout << "Invalid instruction!" << endl;
        }
    }

    return 0;
} 