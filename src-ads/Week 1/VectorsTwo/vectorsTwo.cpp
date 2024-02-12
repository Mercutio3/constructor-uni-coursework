/*
CH-231-A 
a1_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    //Create vector, read user input, break loop when "END" entered
    vector<string> wordVector;
    string temp;
    while(true){
        cin >> temp;
        if(temp == "END"){
            break;
        }
        //Insert read string at end of vector
        wordVector.push_back(temp);
    }

    cout << "size: "  << wordVector.size() << endl;

    //Check if second and fifth elements exist; if so, swap them
    if(wordVector.size() >= 4){
        string swapTemp;
        swapTemp = wordVector[4];
        wordVector[4] = wordVector[1];
        wordVector[1] = swapTemp;
    } else {
        cout << "Second and fifth elements don't exist; cannot swap." << endl;
    }

    //Replace last element in vector with string "???"
    wordVector[wordVector.size()-1] = "???";

    //Print all words in vector separated by a comma
    for(int i = 0; i < wordVector.size()-1; i++){
        cout << wordVector[i] << ", ";
    }
    cout << wordVector[wordVector.size()-1] << endl;
    cout << endl;

    //Print all words in vector separated by a semicolon with iterator
    vector<string>::const_iterator pos;

    for(pos = wordVector.begin(); pos != wordVector.end(); ++pos){
        if(pos == wordVector.end()-1){
            cout << *pos << endl;
        } else {
            cout << *pos << "; ";
        }
    }
    cout << endl;

    //Print all words in vector in reverse separated by a space with iterator
    for(pos = wordVector.end()-1; pos != wordVector.begin()-1; pos--){
        if(pos == wordVector.begin()){
            cout << *pos << endl;
        } else {
            cout << *pos << " ";
        }
    }
    cout << endl;
}