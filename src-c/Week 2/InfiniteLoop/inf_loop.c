/*
CH-230-A
a2_p7.c 
Santiago Dominguez
sdominguez@jacobs-university.de
*/

#include <stdio.h>

int main() {
    int i = 8;
    while(i >= 4){
        printf("i is %d\n", i);
        i--;
    }
    printf("That's it.\n");
    
    return 0;

    /* The loop lacked curved brackets to indicate the part
    that loops. So it just looped indefinitely. The "{}" were
    added in lines 12 and 15. */
}