/*
CH-230-A
a9_p7.c
Santiago Dominguez
2 November 2022
Swap ints, floats, and char pointers via reference
*/

#include <iostream>

using namespace std;

//Swap ints using 'real' call-by-reference
void swapping(int &a, int &b){
    int help = a;
    a = b;
    b = help;
}

//Swap floats using 'real' call-by-reference
void swapping(float &x, float &y){
    float help = x;
    x = y;
    y = help;
}

//Swap char pointers using 'real' call-by-reference
void swapping(const char *&str1, const char *&str2){
    const char *help = str1;
    str1 = str2;
    str2 = help;
}

int main(void) {
    //Initialize variables
    int a = 7, b = 15;
    float x = 3.5, y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";
    
    //Outputs before swapping
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    
    //Call swapping functions
    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2);
    
    //Outputs after swapping
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    
    return 0;
}