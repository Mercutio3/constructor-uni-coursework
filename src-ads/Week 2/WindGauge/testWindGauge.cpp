#include <iostream>
#include "WindGauge.h"

using namespace std;

//Number dumping function
void dumpNumbers(WindGauge wg){
    cout << "Number dump" << endl << "------------" << endl;
    cout << "Highest number: " << wg.highest() << endl;
    cout << "Lowest number: " << wg.lowest() << endl;
    cout << "Average: " << wg.average() << endl << endl;
}

int main(){
    //Create WindGauge
    WindGauge windSpeeds;

    //Add five wind speeds
    windSpeeds.currentWindSpeed(15);
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(12);
    windSpeeds.currentWindSpeed(15);
    windSpeeds.currentWindSpeed(15);

    //Dump the gauge
    dumpNumbers(windSpeeds);

    //Add ten more measurements
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(17);
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(20);
    windSpeeds.currentWindSpeed(17);
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(15);
    windSpeeds.currentWindSpeed(16);
    windSpeeds.currentWindSpeed(20);

    //Dump the numbers again
    dumpNumbers(windSpeeds);

    return 0;
}