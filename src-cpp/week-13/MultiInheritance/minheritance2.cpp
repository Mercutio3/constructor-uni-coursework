/*
CH-230-A
a13_p5.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include<iostream>
using namespace std;
 
class A {
    int x;
    public:
        A() {x = 0;}
        A(int i) {x = i;}
        void print() {cout << x;}
};
 
class B: virtual public A {
    public:
        B():A(10) {  }
};
 
class C:  virtual public A {
    public:
        C():A(10) {  }
};
 
class D: public B, public C {
};

/* EXPLANATION
 * The code doesn't compile or run because the creation of D eventually requires
 * a default constructor for A (due to the inheritance structure). A has no
 * default constructor defined, causing an error.
 * 
 * To fix this, we simply define an empty default constructor in the A class.
 * This allows the code to compile and run.
 */
 
int main() {
    D d;
    d.print();
    return 0;
}