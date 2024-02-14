#include <iostream>
#include <math.h>

using namespace std;

int baseTen = 530;
int i = 0;
int targetBase = 2;

int main(){
    while(baseTen > 0){
        cout << baseTen%targetBase;
        baseTen = (int)baseTen/targetBase;
        i++;
    }
    cout << endl;
}