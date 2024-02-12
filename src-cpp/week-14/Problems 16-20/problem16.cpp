#include <iostream>

using namespace std;

class Car{
    public:
        Car(std::string,std::string, double);
        ~Car();
        void setName(std::string);
    protected:
        std::string brandName;
        std::string modelName;
        double price;
};

inline void Car::setName(string newName){
    modelName = newName;
}

inline Car::Car(string bName, string mName, double nprice){
    brandName = bName;
    modelName = mName;
    price = nprice;
}

inline Car::~Car(){}

class Taxi : public Car {
    public:
        void print();
        Taxi(string, string, double, int);
        ~Taxi();
    private:
        int passLimit;
};

Taxi::Taxi(string bName, string mName, double nPrice, int passLim) : Car(bName, mName, nPrice){
    passLimit = passLim;
}

Taxi::~Taxi(){}

void Taxi::print(){
    cout << "Brand name: " << brandName << endl;
    cout << "Model name: " << modelName << endl;
    cout << "Price: $" << price << endl;
    cout << "Passenger limit: " << passLimit << endl;
}

int main(int argc, char** argv){
    Car one("tesla","serp", 12.3);
    Taxi tax("tesla","x",44.33,6);
    tax.print();

    return 0;
}