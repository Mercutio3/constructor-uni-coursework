#include <iostream>
#include <deque>
#include "WindGauge.h"

using namespace std;

WindGauge::WindGauge(int periods){
    history = periods;
}

void WindGauge::currentWindSpeed(int speed){
    //Add speed to Gauge. If gauge is full, delete last element.
    if(speeds.size() == history){
        speeds.pop_back();
        speeds.push_front(speed);
    } else {
        speeds.push_front(speed);
    }
}

int WindGauge::highest() const{
    //Use iterator to traverse deque, find largest number and return it
    int highest = speeds[0];
    deque<int>::const_iterator it;
    for(it = speeds.cbegin(); it != speeds.cend(); ++it){
        if(*it > highest){
            highest = *it;
        }
    }
    return highest;
}

int WindGauge::lowest() const{
    //Use iterator to traverse deque, find smallest number and return it
    int lowest = speeds[0];
    deque<int>::const_iterator it;
    for(it = speeds.cbegin(); it != speeds.cend(); ++it){
        if(*it > lowest){
            lowest = *it;
        }
    }
    return lowest;
}

int WindGauge::average() const{
    //Use iterator to traverse deque, calculate average return it
    int avg = 0;
    deque<int>::const_iterator it;
    for(it = speeds.cbegin(); it != speeds.cend(); ++it){
        avg += *it;
    }
    return avg/speeds.size();
}