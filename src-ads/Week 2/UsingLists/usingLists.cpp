#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main(){
    //Create two lists (A and B)
    list<int> A;
    list<int> B;
    int insert;

    //Read ints from the keyboard until the int is negative or zero
    while(true){
        cin >> insert;
        if(insert < 1){
            break;
        }
        //Insert the positive integers into list A by adding to the end
        A.push_back(insert);
        //Insert the same positive integers into list B by adding to the beginning
        B.push_front(insert);
    }

    //Print list A (separated by spaces) on the standard output
    list<int>::const_iterator it;
    cout << "List A: ";
    for(it = A.cbegin(); it != A.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    //Print list B (separated by spaces) into a file called “listB.txt”
    ofstream output("usingLists.txt");
    output << "List B: ";
    for(it = B.cbegin(); it != B.cend(); ++it){
        output << *it << " ";
    }
    output << endl;
    output.close();

    //Print an empty line on the standard output
    cout << endl;

    //Move the first element of the lists to the end (for both lists)
    A.push_back(A.front());
    B.push_back(B.front());
    A.pop_front();
    B.pop_front();

    //Print list A and list B on standard output (separated by comma) with iterator
    cout << "List A: ";
    int counter = 0;
    for(it = A.cbegin(); it != A.cend(); ++it){
        if(counter == A.size()-1){
            cout << *it;
        } else {
            cout << *it << ",";
            counter++;
        }
    }
    cout << endl;
    cout << "List B: ";
    counter = 0;
    for(it = B.cbegin(); it != B.cend(); ++it){
        if(counter == B.size()-1){
            cout << *it;
        } else {
            cout << *it << ",";
            counter++;
        }
    }
    cout << endl;

    //Print an empty line on the standard output
    cout << endl;

    //Merge list B into list A
    A.merge(B);

    //Print the result of the merging as a sorted list on the standard output
    //separated by spaces
    A.sort();
    for(it = A.cbegin(); it != A.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}