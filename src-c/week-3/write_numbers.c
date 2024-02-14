/*
CH-230-A
a3_p1.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    //Initialize variables and read float
    float x;
    int n;
    scanf("%f", &x);
    
    //Infinte loop that only breaks when a valid int (greater than 0) is entered
    while(true){
        scanf("%d",&n);
        if(n>0){
            break;
        }
        printf("Input is invalid, reenter value\n");
    }

    //Print x, n times
    for(int i = 0; i<n; i++){
        printf("%f\n",x);
    }

    return 0;
}