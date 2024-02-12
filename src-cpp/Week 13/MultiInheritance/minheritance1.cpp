/*
CH-230-A
a13_p4.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include<iostream>

using namespace std;
 
class A {
    int x;
    public:
        void setX(int i) {x = i;}
        void print() {cout << x;}
};
 
class B : public virtual A {
    public:
        B()  {setX(10);}
};
 
class C : public virtual A {
    public:
        C() {setX(20);}
};
 
class D: public B, public C {
};

/* EXPLANATION:
 * The code doesn't compile or run due to ambiguity related to the print() method,
 * due to the absence of constructors in A.
 * 
 * To fix this, we add the keyword "virtual" to D's base classes B and C, which
 * allows the code to compile and run.
 */
 
int main() {
    D d;
    d.print();
    return 0;
}