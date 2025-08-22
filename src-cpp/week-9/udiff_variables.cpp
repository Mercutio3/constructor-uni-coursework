/*
CH-230-A
a9_p2.c
Santiago Dominguez
1 November 2022
Prints string s and double x n times
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv){
    //Initialize variables
    int n;
    double x;
    string s;

    //Read user input
    cin >> n;
    cin >> x;
    cin >> s;

    //Print s:x n times
    for(int i = 0; i < n; i++){
        cout << s << ":" << x << endl;
    }

    return 0;
}