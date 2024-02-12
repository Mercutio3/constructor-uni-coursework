/*
CH-230-A
a12_p2.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#ifndef __TOURNAMENT_H
#define __TOURNAMENT_H
#include <string>
#include <cstring>

class TournamentMember{
    private:
        //Class properties
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

#endif