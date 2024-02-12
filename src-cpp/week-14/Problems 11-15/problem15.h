#include <iostream>

class Car{
    public:
        Car(std::string,std::string, double);
        ~Car();
        void setName(std::string);
    private:
        std::string brandName;
        std::string modelName;
        double price;
};

inline void Car::setName(std::string newName){
    modelName = newName;
}

inline Car::Car(std::string bName, std::string mName, double nprice){
    brandName = bName;
    modelName = mName;
    price = nprice;
}

inline Car::~Car(){}