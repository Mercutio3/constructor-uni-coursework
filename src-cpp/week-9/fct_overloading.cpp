/*
CH-230-A
a9_p4.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

int mycount(int intOne, int intTwo);
int mycount(char countChar, string inputStr);

int main(int argc, char** argv){
    //initialize variables
    int a, b;
    char c;
    string s;

    //First mycount() call with two integers read from user input
    cout << "Enter two integers:" << endl;
    cin >> a;
    cin >> b;
    cout << "mycount() with integers " << a << " and " << b << " passed: " 
    << mycount(a,b) << endl;
    
    //Second mycount() call with a char and string read from user input
    cout << "Enter a char and a string:" << endl;
    cin >> c;
    cin.ignore();
    getline(cin, s);
    cout << "mycount() with char "<< c << " and string '" << s << "' passed: "
    << mycount(c, s) << endl;

    return 0;
}

int mycount(int intOne, int intTwo){
    //Return difference of intTwo and intOne
    return intTwo-intOne;
}

int mycount(char countChar, string inputStr){
    //Loop thorugh string and count instances of countChar
    int count = 0;

    for(int i = 0; i < (int)inputStr.size(); i++){
        if(inputStr[i] == countChar){
            count++;
        }
    }

    return count;
}