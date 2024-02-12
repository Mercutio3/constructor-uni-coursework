/*
CH-231-A 
a1_p2.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

template <class T, int initialsize = 10>
class Stack{
    private:
        T *ptr;
        int size;
        int where;
    public:
        Stack();
        Stack(const Stack&);
        ~Stack();
        bool push(T element);
        bool pop(T& out);
        T back(void);
        int getNumEntries();
};