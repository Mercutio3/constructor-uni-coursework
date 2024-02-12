/*
CH-231-A 
a1_p4.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    //Create string vector, read user input, break loop when "END" entered
    vector<string> vString;
    string temp;
    while(true){
        cin >> temp;
        if(temp == "END"){
            break;
        }
        vString.push_back(temp);
    }

    //Print all words in vector separated by a space with index operator
    for(int i = 0; i < vString.size(); i++){
        cout << vString[i] << " ";
    }
    cout << endl;

    //Print all words in vector separated by a comma with iterator
    vector<string>::const_iterator pos;

    for(pos = vString.begin(); pos != vString.end(); ++pos){
        if(pos == vString.end()-1){
            cout << *pos << endl;
        } else {
            cout << *pos << ", ";
        }
    }
    cout << endl;

    return 0;
}