/*
CH-231-A 
a1_p3.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "linkedList.h"

using namespace std;

template<typename T>
Node<T>::Node(){
    this->next = NULL;
    this->prev = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
}

//Add item to the front of the list
template<typename T>
void LinkedList<T>::addFront(T item){
    Node<T>* node = new Node<T>;
    node->data = item;
    if(head == NULL){
        head = node;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;
}

//Add item to the back of the list
template<typename T>
void LinkedList<T>::addBack(T item){
            Node<T>* node = new Node<T>;
            node->data = item;
            if(head == NULL){
                head = node;
                return;
            }
            Node<T>* temp = head;
            Node<T>* prev;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            temp->next = node;
            temp->prev = prev;
}

//Remove item from the front of the list
template<typename T>
void LinkedList<T>::removeFront(){
    if(head == NULL){
        return;
    }
    head = head->next;
    head->next->prev = head;
}

//Remove item from the back of the list
template<typename T>
void LinkedList<T>::removeBack(){
    if(head == NULL){
        cout << "List is empty." << endl;
        return;
    }
    if(head->next == NULL){
        head = NULL;
        return;
    }

    Node<T>* temp = head;
    while(temp != NULL){
        if(temp->next->next == NULL){
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }            
}

//Return number of elements
template<typename T>
int LinkedList<T>::getNumElems(){
    int length = 0;
    Node<int>* temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

//Main element retreival function
template<typename T>
T LinkedList<T>::get(int index){
    //Check list isn't empty
    if(head == NULL){
        cout << "List is empty" << endl;
        return -1;
    }
    //Check desired index is valid
    if(index >= getNumElems() || index < 0){
        cout << "Index out of bound" << endl;
        return -1;
    }
    if(index == 0){
        return head->data;
    }
    int count = 0;
    T res;
    Node<T>* temp = head;
    while(temp != NULL){
        if(count++ == index){
            res = temp->data;
            break;
        }
        temp = temp->next;
    }
    return res;
}

//Get item in index 0
template<typename T>
T LinkedList<T>::getFirst(){
    return get(0);
}

//Get item in last index
template<typename T>
T LinkedList<T>::getLast(){
    return get(getNumElems()-1);
}

//Displays all list items
template <typename T>
void LinkedList<T>::print(){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    cout << "List items: ";
    Node<T>* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    LinkedList<int> list;
    //Add elements to front and back of list
    list.addFront(1);
    list.addBack(2);
    list.addFront(1);
    list.addBack(3);

    //Get number of elements
    cout << "Number of items: " << list.getNumElems() << endl;
    list.print();

    //Retrieve first and last elements from list without removing
    cout << "First element: " << list.getFirst() << endl;
    cout << "Last element: " << list.getLast() << endl;

    //Remove first and last elements from the list
    list.removeFront();
    list.removeBack();
    list.print();
    return 0;
}