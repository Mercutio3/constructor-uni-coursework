#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main(){
    //Create map
    map<string, string> birthdays;
    
    //Read the data from file “data.txt”
    ifstream file;
    string name;
    string birthday;
    file.open("data.txt");
    if(file.is_open()){
        while(file){
            getline(file, name);
            getline(file, birthday);
            birthdays[name] = birthday;
        }   
    } else {
        cout << "Couldn't open file." << endl;
    }
    file.close();

    //Querying collection
    string readName;
    cout << "Enter name to view birthday: ";
    getline(cin, readName);

    //If name isn't in map print “Name not found!"
    if(birthdays[readName] == ""){
        cout << "Name not found!" << endl;
    } else {
        cout << readName << "'s birthday is on " << birthdays[readName] << endl;
    }

    return 0;
}