/*
CH-231-A 
a1_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "stack.h"

using namespace std;

//Stack constructor, if not size provided will use default 10
template<class T, int initialsize>
Stack<T, initialsize>::Stack(){
    ptr = new T[initialsize];
    size = initialsize;
    where = -1;
}

template<class T, int initialsize>
Stack<T, initialsize>::Stack(const Stack& st){
    ptr = st.ptr;
    size = st.size;
    where = st.where;
}

//Destructor
template<class T, int initialsize>
Stack<T, initialsize>::~Stack(){
    delete[] ptr;
}

//Push element to stack, if stack is full return false
template<class T, int initialsize>
bool Stack<T, initialsize>::push(T element){
    if(where+1 == size){
        return false;
    }
    where++;
    ptr[where] = element;
    return true;
}

//Pop element from stack, if stack is empty return false
template<class T, int initialsize>
bool Stack<T,initialsize>::pop(T& out){
    if(where>=0){
        out = ptr[where--];
        return true;
    } else {
        return false;
    }
}

//Return element on top of stack without changing stack
template<class T, int initialsize>
T Stack<T,initialsize>::back(){
    return ptr[where];
}

//Return number of entries in stack
template<class T, int initialsize>
int Stack<T,initialsize>::getNumEntries(){
    return where+1;
}

int main(){
    //Create int stack
    Stack<int> intStack;
    cout << "Number of entries: " << intStack.getNumEntries() << endl;
    cout << "—————" << endl;
    //Demonstrate push and back methods
    for(int i = 0; i < 5; i++){
        intStack.push(i);
        cout << "Number of entries: " << intStack.getNumEntries() << endl;
        cout << "Top entry: " << intStack.back() << endl;
        cout << "—————" << endl;
    }
    //Pop topmost element, show updated stack, print popped element
    int popped;
    intStack.pop(popped);
    cout << "Number of entries: " << intStack.getNumEntries() << endl;
    cout << "Top entry: " << intStack.back() << endl;
    cout << "Popped entry: " << popped << endl;
    cout << "—————" << endl;
    
    //Create float stack size 5 and fill it up to intentionally fail push()
    Stack<float, 5> floatStack;
    for(int i = 0; i < 6; i++){
        if(floatStack.push(i)){
            cout << "Succesfully pushed element " << i << " into stack." << endl;
        } else {
            cout << "Failed to push element " << i << " into stack." << endl;
        }
    }
    //Intentionally demonstrate pop() fail
    float popped2;
    for(int i = 0; i < 6; i++){
        if(floatStack.pop(popped2)){
            cout << "Succesfully popped element " << popped2 << endl;
        } else {
            cout << "Failed to pop element, stack empty." << endl;
        }
    }

    return 0;
}