/*
CH-230-A
a13_p7.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

void exceptionThrower(int param);

class OwnException : public exception {
    public:
        //Overriding the what() method to return custom string
        const char* what() const throw(){
            return "OwnException\n";
        }
};

int main(int argc, char** argv){
    for(int i = 1; i < 5; i++){
        //Run exceptionThrower() method (all four versions) and catch exception
        try{
            exceptionThrower(i);
        } catch(char x){
            cerr << "Caught in main: " << x << endl;
        } catch(int y){
            cerr << "Caught in main: " << y << endl;
        } catch(bool z){
            cerr << "Caught in main: " << z << " (true)" << endl;
        } catch(OwnException& oe){
            cerr << "Caught in main: " << oe.what() << endl;
        }
    }

    return 0;
}

void exceptionThrower(int param){
    //Method that throws appropriate exception according to parameter
    if(param == 1){
        throw 'a';
    } else if(param == 2){
        throw 12;
    } else if(param == 3){
        throw true;
    } else {
        OwnException oe;
        throw oe;
        throw "Default case exception";
    }
}