/*
CH-230-A
a13_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    //Read number of files, initalize string filename array
    int n;
    cout << "Enter number of files: ";
    cin >> n;
    string filenames[n];

    //Read filenames for n files
    for(int i = 0; i < n; i++){
        cout << "Enter filename for file " << i+1 << ": " << endl;
        cin >> filenames[i];
    }

    //Open output file, check if opened correctly
    ofstream out("concatn.txt", ifstream::binary);
    if(!out.good()){
        cerr << "Error opening output file" << endl;
        exit(0);
    }

    //For loop will repeat operations for every input file
    for(int i = 0; i < n; i++){
        //Open input file with binary mode, check if opened correctly
        ifstream in(filenames[i], ifstream::binary);
        if(!in.good()){
            cerr << "Error opening input file " << i+1 << endl;
            exit(1);
        }

        //Determine length of file, initialize char buffer of right size
        in.seekg(0, in.end);
        long size = in.tellg();
        in.seekg(0);
        char* buffer = new char[size];

        //Read input file's content into buffer; write into output file
        in.read(buffer, size);
        out.write(buffer, size);
        
        //Insert newline char to separate content of different files
        out.put('\n');

        //Release memory occupied by buffer and close input file
        delete[] buffer;
        in.close();
    }

    //Close output file
    out.close();
    cout << "Succesfully concatenated " << n << " files!" << endl;

    return 0;
}