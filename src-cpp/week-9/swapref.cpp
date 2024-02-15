/*
CH-230-A
a9_p7.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

void swapping(int &a, int &b){
    //Swap ints using 'real' call-by-reference
    int help = a;
    a = b;
    b = help;
}

void swapping(float &x, float &y){
    //Swap floats using 'real' call-by-reference
    float help = x;
    x = y;
    y = help;
}

void swapping(const char *&str1, const char *&str2){
    //Swap char pointers using 'real' call-by-reference
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
/*
eagle
black
car
saving someone
chess
plato
*/