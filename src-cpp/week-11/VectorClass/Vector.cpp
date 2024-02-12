/*
CH-230-A
a11_p6.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>
#include "Vector.h"
#include <cmath>

using namespace std;

Vector::Vector(){
    numComponents = 0;
    compArray = NULL;
}

Vector::Vector(int comps, double* vecArray){
    numComponents = comps;
    compArray = new double[numComponents];
    for(int i = 0; i < numComponents; i++){
        compArray[i] = vecArray[i];
    }
}

Vector::Vector(const Vector& v){
    numComponents = v.numComponents;
    compArray = v.compArray;
}

Vector::~Vector(){
    delete[] compArray;
}

void Vector::setSize(int size){
    numComponents = size;
}

int Vector::getSize(){
    return numComponents;
}

void Vector::setComponents(double* comps){
    compArray = comps;
}

double* Vector::getComponents(){
    return compArray;
}

double Vector::norm(){
    int sum = 0;
    for(int i = 0; i < numComponents; i++){
        sum += pow(compArray[i],2);
    }
    return sqrt(sum);
}

Vector Vector::add(const Vector input) const{
    double thisVec[numComponents];
    Vector output(numComponents, thisVec);
    for(int i = 0; i < numComponents; i++){
        output.compArray[i] = compArray[i] + input.compArray[i];
    }
    return output;
}

Vector Vector::difference(const Vector input) const{
    double thisVec[numComponents];
    Vector output(numComponents, thisVec);
    for(int i = 0; i < numComponents; i++){
        output.compArray[i] = compArray[i] - input.compArray[i];
    }
    return output;
}

double Vector::scalProd(const Vector input) const{
    double scalProd;
    for(int i = 0; i < numComponents; i++){
        scalProd += compArray[i] * input.compArray[i];
    }
    return scalProd;
}

void Vector::print(){
    for(int i = 0; i < numComponents; i++){
        cout << compArray[i] << " ";
    }
    cout << endl;
}