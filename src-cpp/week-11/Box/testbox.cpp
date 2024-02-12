/*
CH-230-A
a11_p1.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Box.h"

using namespace std;

double calcBoxVol(Box b);

int main(int argc, char** argv){
    //Read number of boxes from user input, initialize dynamic box array
    int n;
    cout << "Enter number of boxes: ";
    cin >> n;
    cout << endl;
    Box* boxArray = new Box[2*n];

    //Read information for n boxes, create Box object and add it to array
    for(int i = 0; i < n; i++){
        double tHeight, tWidth, tDepth;
        
        cout << "Enter height for box number " << i+1 << ": ";
        cin >> tHeight;
        cout << "Enter width for box number " << i+1 << ": ";
        cin >> tWidth;
        cout << "Enter depth for box number " << i+1 << ": ";
        cin >> tDepth;
        
        Box thisBox(tHeight,tDepth,tWidth);
        boxArray[i] = thisBox;
        Box copyBox = thisBox;
        boxArray[n+i] = copyBox;
        
        cout << endl;
    }

    //Calculate and print volume of all boxes in array
    cout << "-------------------------" << endl;
    for(int i = 0; i < 2*n; i++){
        cout << "Volume of box number " << i+1 << ": " << calcBoxVol(boxArray[i]) << endl;
    }

    delete[] boxArray;

    return 0;
}

double calcBoxVol(Box b){
    //Calculate volume and return it
    return b.getHeight() * b.getWidth() * b.getDepth();
}