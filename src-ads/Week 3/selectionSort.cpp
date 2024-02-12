/*
* Santiago Dominguez
* Algorithms and Data Structures Homework 3
* sdominguez@jacobs-university.de
* Problems 3.2 a, b, and c
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Swap two elements using pointers
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Main selection sort function
void selectionSort(int numbers[], int size){
    //For each element in array
    for(int i = 0; i < size-1; i++){
        int min = i;
        //Look for smallest element and swap with current
        for(int j = i+1; j < size; j++){
            if(numbers[j] < numbers[min]){
                min = j;
            }
        }
        swap(numbers[min], numbers[i]);
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

//Main function
int main(){
    //Read n from user input
    int n;
    cout << "Enter size n of arrays: ";
    cin >> n;

    //Initialize the random number generator
    srand(time(NULL));
    int draw;
    int randArray[n];
    for(int i = 0; i < n; i++){
        //Draw random numbers and add to array
        draw = rand() % 100 + 1;
        randArray[i] = draw;
    }
    cout << "Random array before sorting: " << endl;
    printArray(randArray, n);
    auto start3 = high_resolution_clock::now();
    selectionSort(randArray, n);
    auto stop3 = high_resolution_clock::now();
    duration<double, milli> durationDouble3 = stop3 - start3;
    cout << "Random array after sorting: " << endl;
    printArray(randArray, n);
    cout << durationDouble3.count() << "ms" << endl;
    
    //Demonstrate selection sort for Case A
    //Worst case is an array that's sorted, but the smallest element is at the end
    int caseA[n];
    for(int i = 0; i < n-1; i++){
        caseA[i] = i+1;
    }
    caseA[n-1] = 0;
    cout << "Case A before sorting: " << endl;
    printArray(caseA, n);
    auto start = high_resolution_clock::now();
    selectionSort(caseA, n);
    auto stop = high_resolution_clock::now();
    duration<double, milli> durationDouble = stop - start;
    cout << "Case A after sorting: " << endl;
    printArray(caseA, n);
    cout << durationDouble.count() << "ms" << endl;

    //Demonstrate selection sort for Case B
    //Best case is an array that's already sorted
    int caseB[n];
    for(int i = 0; i < n; i++){
        caseB[i] = i;
    }
    cout << "Case B before sorting: " << endl;
    printArray(caseB, n);
    auto start2 = high_resolution_clock::now();
    selectionSort(caseB, n);
    auto stop2 = high_resolution_clock::now();
    duration<double, milli> durationDouble2 = stop2 - start2;
    cout << "Case B after sorting: " << endl;
    printArray(caseB, n);
    cout << durationDouble2.count() << "ms" << endl;

    return 0;
}