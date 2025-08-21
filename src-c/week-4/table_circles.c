/*
CH-230-A
a4_p1.c 
Santiago Dominguez
27 September 2022
Calcualtes area and perimeter using given values
*/

#include <stdio.h>
#include <math.h>

int main(){
    //Read floats and store them in variables
    float low;
    float high;
    float step;
    scanf("%f",&low);
    scanf("%f",&high);
    scanf("%f",&step);

    //Print table using helper functions to calcualte are and perimeter
    for(float i = low; i <= high; i += step){
        printf("%f %f %f\n", i, ((i*i)*M_PI), (2.0*M_PI*i));
    }

    return 0;
}