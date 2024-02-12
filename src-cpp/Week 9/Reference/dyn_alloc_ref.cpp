/*
CH-230-A
a9_p8.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

void subtract_max(int *array, int size);
void deallocate(int* array);

int main(int argc, char** argv){
    //Read user input for number of elements
    int n;
    cout << "Enter array size: ";
    cin >> n;

    //Initialize array of size n, read values
    int *array = new int[n];
    cout << "Please enter " << n << " integers." << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    //Print out array before calling subtract_max
    cout << "Original values of array: ";
    for(int i = 0; i < n; i++){
        cout  << array[i] << " ";
    }
    cout << endl;

    //Call subtract_max function and print out resulting array values
    subtract_max(array,n);

    cout << "Values of array after subtracting max: ";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    //Call de-allocation function
    deallocate(array);

    return 0;
}

void subtract_max(int *array, int size){
    //Determine max value in array and store it in 'max'
    int max = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    //Subtract max from all values in array
    for(int i = 0; i < size; i++){
        array[i] = array[i] - max;
    }
}

void deallocate(int* array){
    //Deallocate memory
    delete[] array;
}