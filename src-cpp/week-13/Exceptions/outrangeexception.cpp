/*
CH-230-A
a13_p6.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    //Initialize vector
    vector<int> vec;

    //Set 20 elements of vector to the number 8
    for(int i = 0; i < 20; i++){
        vec.push_back(8);
    }

    try{
        //Attempt to access 21st element of fector
        cout << "Accessing 21st element of vector..." << endl;
        vec.at(20);
    } catch(const out_of_range& oor) {
        //Throw out of range error with what() method
        cerr << "Out of Range Error: " << oor.what() << endl;
        exit(1);
    }

    return 0; 
}