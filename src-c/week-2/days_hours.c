/*
 * CH-230-A
 * a2_p10.c
 * Santiago Dominguez
 * 13 September 2022
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    //The boolean value serves to terminate the loop when printing is finished.
    bool flag = false;
    int hoursInDays = 24;
    
    //
    while(flag==false){
        //Read integer and store it in a variable
        char line[100];
        int days;
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &days);

        //Check that number of days is postiive and nonzero
        if(days>0){
            //Initialize integer that will increase with each loop iteration
            int currDay = 1;
            
            //Main loop
            while(currDay <= days){
                if(days==1){
                    printf("%d day = %d hours\n", currDay, currDay*hoursInDays);
                } else {
                    printf("%d days = %d hours\n", currDay, currDay*hoursInDays);
                }
                currDay++;
            }
            flag = true;
        }
    }
    
    return 0;
}