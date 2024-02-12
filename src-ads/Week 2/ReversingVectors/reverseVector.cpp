#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //Fill a vector with the integer values from 1 to 30
    vector<int> intVector;
    for(int i = 0; i < 30; i++){
        intVector.push_back(i+1);
    }

    //Add the value 5 at the end of the vector
    intVector.push_back(5);

    //Reverse the vector
    reverse(intVector.begin(),intVector.end());

    //Print the content of the vector on the standard output using an iterator
    vector<int>::const_iterator it;
    for(it = intVector.cbegin(); it != intVector.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    //Replace all occurrences of the value 5 by the value 129
    replace(intVector.begin(), intVector.end(), 5, 129);

    //Print the modified vector again on the standard output
    for(it = intVector.cbegin(); it != intVector.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}