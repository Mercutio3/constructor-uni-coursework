/*
CH-230-A
a12_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
#include <string>

using namespace std;

string TournamentMember::location = "Bremen";

TournamentMember::TournamentMember(){
    cout << "//Constructor called." << endl;

    //Sets properties to default values
    string fName = "default_firstname";
    strcpy(firstName, fName.c_str());
    string lName = "default_lastname";
    strcpy(lastName, lName.c_str());
    string bDay = "2003-01-11";
    strcpy(birthday, bDay.c_str());

    tournamentsPlayed = 0;
    tournamentsWon = 0;
}

TournamentMember::TournamentMember(string nfName, string nlName, string nBday,
int nTourns, int tWon){
    cout << "//Parametric constructor called." << endl;
    
    //Sets properties according to parameters
    strcpy(firstName, nfName.c_str());
    strcpy(lastName, nlName.c_str());
    strcpy(birthday, nBday.c_str());
    tournamentsPlayed = nTourns;
    tournamentsWon = tWon;
}

TournamentMember::TournamentMember(const TournamentMember& t){
    //Copy constructor
    cout << "//Copy constructor called." << endl;
    strcpy(firstName, t.firstName);
    strcpy(lastName, t.lastName);
    strcpy(birthday, t.birthday);

    tournamentsPlayed = t.tournamentsPlayed;
    tournamentsWon = t.tournamentsWon;
}

TournamentMember::~TournamentMember(){
    cout << "//Destructor called." << endl;
}

void TournamentMember::printInfo(){
    //Prints out all properties
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Location: " << location << endl;
    cout << "Tournaments played before: " << tournamentsPlayed << endl;
    cout << "Tournaments won before: " << tournamentsWon << endl;
    cout << endl;
}

void TournamentMember::changeLocation(string nLoc){
    //Changes location of tournament
    cout << "Changing location to: " << nLoc;
    location = nLoc;
}