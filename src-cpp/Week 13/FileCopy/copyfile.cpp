/*
CH-230-A
a13_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
    //Initialize strings, read user input for input file name
    string line;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    //Open input file, check if opened correctly
    ifstream in(filename);
    if(!in.good()){
        cerr << "Error opening input file" << endl;
        exit(1);
    }
    
    //Substring without ".txt" necessary to append "_copy"
    int findDot = filename.find(".");
    string smallName = filename.substr(0, findDot);

    //Open output file, check if opened correctly
    ofstream out(smallName + "_copy.txt");
    if(!out.good()){
        cerr << "Error opening output file" << endl;
        exit(2);
    }

    //Copy every line in input file to output file
    while(getline(in, line)){
        out << line << endl;
    }

    //Close files
    in.close();
    out.close();

    return 0;
}