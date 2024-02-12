#include <iostream>

using namespace std;

double divide(double a, double b){
    if(b == 0){
        throw logic_error("Attempted to divide by 0!");
    }
    return a/b;
}

int main(){
    try{
        cout << divide(3,0) << endl;
    } catch(logic_error le) {
        cerr << le.what() << endl;
    }
}