#include <iostream>
#include <deque>

using namespace std;

int main(){
    //Create a deque A able to store float values
    deque<float> A;
    float insert;

    //Read floats from the keyboard until the entered float value is 0
    while(true){
        cin >> insert;
        if(insert == 0.0){
            break;
        }
        if(insert > 0.0){
            ////Insert the positive elements at the end of A
            A.push_back(insert);
        } else {
            //Insert negative elements at the beginning of A
            A.push_front(insert);
        }
    }

    //Print the elements of A on the standard output separated by spaces
    deque<float>::const_iterator it;
    for(it = A.cbegin(); it != A.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    //Print an empty line on the standard output
    cout << endl;

    //Add the value 0 into the middle of the deque
    for(it = A.cbegin();it != A.cend();++it){
        if(*it > 0){
            break;
        }
    }
    A.insert(it,0);
    
    //Print the elements of A on the standard output separated by semicolons
    int counter = 0;
    for(it = A.cbegin(); it != A.cend(); ++it){
        if(counter == A.size()-1){
            cout << *it;
        } else {
            cout << *it << ";";
            counter++;
        }
    }
    cout << endl;

    return 0;
}