/*
CH-230-A
a12_p3.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#ifndef __TOURNAMENT_H
#define __TOURNAMENT_H
#include <string>
#include <cstring>

class TournamentMember{
    protected:
        //Class properties, accessible by child classes
        static std::string location;
        char firstName[36];
        char lastName[36];
        char birthday[11];
        int tournamentsPlayed;
        int tournamentsWon;
    public:
        //Constructors, copy consturctors, and destructor
        TournamentMember();
        TournamentMember(std::string, std::string, std::string, int = 0, int = 0);
        TournamentMember(const TournamentMember&);
        ~TournamentMember();
        
        //Operational methods
        void printInfo();
        void changeLocation(std::string);

        //Inline setters and getters
        void setFirstName(std::string);
        std::string getFirstName();
        void setLastName(std::string);
        std::string getLastName();
        void setBirthday(std::string);
        std::string getBirthday();
        void setTournsPlayed(int);
        int getTournsPlayed();
        void setTournsWon(int);
        int getTournsWon();
};

class Player : public TournamentMember {
    private:
        int number;
        std::string position;
        int goalsScored;
        bool leftFooted;
    public:
        //Constructors, copy constructor, and destructor
        Player();
        Player(std::string nfName, std::string nlName, std::string nBday, 
        int nTourns, int tWon, int nNum, std::string nPos, int nGoal, bool nFoot);
        Player(const Player&);
        ~Player();
        
        //Operational methods
        void increaseGoals();
        void printInfo();

        //Inline setters and getters
        void setNumber(int);
        int getNumber();
        void setPosition(std::string);
        std::string getPosition();
        int getGoals();
        void setFoot(bool);
        bool getFoot();
};

//Tournamentmember class inline methods
inline void TournamentMember::setFirstName(std::string nName){
    strcpy(firstName, nName.c_str());
}

inline std::string TournamentMember::getFirstName(){
    return firstName;
}

inline void TournamentMember::setLastName(std::string nName){
    strcpy(lastName, nName.c_str());
}

inline std::string TournamentMember::getLastName(){
    return lastName;
}

inline void TournamentMember::setBirthday(std::string nBday){
    strcpy(birthday, nBday.c_str());
}

inline std::string TournamentMember::getBirthday(){
    return birthday;
}

inline void TournamentMember::setTournsPlayed(int nTourns){
    tournamentsPlayed = nTourns;
}

inline int TournamentMember::getTournsPlayed(){
    return tournamentsPlayed;
}

inline void TournamentMember::setTournsWon(int nTourns){
    tournamentsWon = nTourns;
}

inline int TournamentMember::getTournsWon(){
    return tournamentsWon;
}

//Player class inline methods
inline void Player::setNumber(int nNum){
    number = nNum;
}

inline int Player::getNumber(){
    return number;
}

inline void Player::setPosition(std::string nPos){
    position = nPos;
}

inline std::string Player::getPosition(){
    return position;
}

inline int Player::getGoals(){
    return goalsScored;
}

inline void Player::setFoot(bool nFoot){
    leftFooted = nFoot;
}

inline bool Player::getFoot(){
    return leftFooted;
}

#endif