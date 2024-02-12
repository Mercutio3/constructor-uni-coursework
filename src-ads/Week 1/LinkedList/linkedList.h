/*
CH-231-A 
a1_p3.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

template<typename T>
class Node{
    //Define node class
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
        template<typename U>friend class LinkedList;
    public:
        Node();
};

template<typename T>
class LinkedList{
    //Define linkedlist class
    private:
        Node<T>* head;
    public:
        LinkedList();
        void addFront(T item);
        void addBack(T item);
        void removeFront();
        void removeBack();
        int getNumElems();
        T get(int index);
        T getFirst();
        T getLast();
        void print();
};