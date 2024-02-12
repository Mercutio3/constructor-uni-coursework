#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//User-deifned function to determine if vector vec contains item x
bool contains(const vector<int> vec, int x){
    return find(vec.begin(), vec.end(), x) != vec.end();
}

int main(){
    vector<int> lottoNums;
    vector<int>::const_iterator it;
    
    //Initialize the random number generato
    srand(time(NULL));
    
    int draw;

    //Draw number and add to container
    draw = rand() % 49 + 1;
    lottoNums.push_back(draw);
    
    for(int i = 0; i < 5; i++){
        //Make sure container will not contain duplicates
        while(true){
            //Draw number and add to container
            draw = rand() % 49 + 1;
            if(!contains(lottoNums, draw)){
                lottoNums.push_back(draw);
                break;
            }
        }
    }

    //Sort vector in ascending order
    sort(lottoNums.begin(), lottoNums.end());

    //Print on the standard output
    for(it = lottoNums.cbegin(); it != lottoNums.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}