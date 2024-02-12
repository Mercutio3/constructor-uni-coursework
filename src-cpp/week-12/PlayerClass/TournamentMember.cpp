/*
CH-230-A
a12_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "TournamentMember.h"
#include <string>

using namespace std;

string TournamentMember::location = "Bremen";

//TournamentMember method definitions
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
    cout << "Changing location to: " << nLoc << endl;
    location = nLoc;
}

//Player method & constructor definitions
Player::Player(){
    //Sets properties to default values
    cout << "++Player constructor called." << endl;
    number = 7;
    position = "midfielder";
    goalsScored = 0;
    leftFooted = false;
}

Player::Player(string nfName, string nlName, string nBday, int nTourns, 
    int tWon, int nNum, string nPos, int nGoal, bool nFoot) : TournamentMember
    (nfName,nlName,nBday,nTourns,tWon){
        cout << "++Player parametric constructor called." << endl;
        
        //Sets properties according to parameters
        number = nNum;
        position = nPos;
        goalsScored = nGoal;
        leftFooted = nFoot;
}

Player::Player(const Player& p){
    //Copy constructor
    cout << "++Player copy constructor called." << endl;
    strcpy(firstName, p.firstName);
    strcpy(lastName, p.lastName);
    strcpy(birthday, p.birthday);

    tournamentsPlayed = p.tournamentsPlayed;
    tournamentsWon = p.tournamentsWon;
    
    number = p.number;
    position = p.position;
    goalsScored = p.goalsScored;
    leftFooted = p.leftFooted;
}

Player::~Player(){
    cout << "++Player destructor called." << endl;
}

void Player::increaseGoals(){
    //Increase number of goals for a player
    goalsScored++;
}

void Player::printInfo(){
    //Prints out all properties
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Birthday: " << getBirthday() << endl;
    cout << "Location: " << location << endl;
    cout << "Tournaments played before: " << getTournsPlayed() << endl;
    cout << "Tournaments won before: " << getTournsWon() << endl;
    cout << "Number and position: " << getNumber() << ", " << getPosition() << endl;
    cout << "Goals scored: " << getGoals() << endl;
    if(leftFooted){cout << "Left-footed" << endl;} else {cout <<
        "Right-footed" << endl;}
    cout << endl;
}