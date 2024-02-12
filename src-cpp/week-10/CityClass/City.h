/*
CH-230-A
a10_p3.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <string>

class City {
    private:
    //Class variables
    std::string name;
    int population;
    std::string mayor;
    double area;

    public:
    //Setter methods
    void setName(std::string newName);
    void setPop(int newPop);
    void setMayor(std::string newMayor);
    void setArea(double newArea);

    //Getter methods
    int getPop();
    int getMayor();
    double getArea();

    //Print method
    void print();
};