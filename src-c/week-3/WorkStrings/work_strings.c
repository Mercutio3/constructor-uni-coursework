/*
CH-230-A
a3_p11.c 
Santiago Dominguez
30 September 2022
Reads strings, measures length, concatenates, copies, compares order, searches for a character
*/

#include <stdio.h>
#include <string.h>

int main(){
    char one[100];
    char two[100];

    //Read user input string and store them in char arrays
    fgets(one, sizeof(one), stdin);
    fgets(two, sizeof(two), stdin);

    //Print string lengths
    printf("length1=%lu\n", strlen(one)-1);
    printf("length2=%lu\n", strlen(two)-1);

    //Concatenate two strings, save a copy of "one"
    char oneCopy[100];
    strcpy(oneCopy,one);
    one[strcspn(one, "\n")] = 0;
    strcat(one,two);
    printf("concatenation=%s", one);

    //Copy string
    char three[100];
    strcpy(three,two);
    printf("copy=%s", three);

    //Compare strings
    int compare = strcmp(oneCopy,two);
    if(compare > 0){
        printf("one is larger than two\n");
    } else if(compare < 0){
        printf("one is smaller than two\n");
    } else {
        printf("one is equal to two\n");
    }

    //Search for character and print position
    char c;
    scanf("%c", &c);
    int pos = (int)(strchr(two, c) - two);
    if(pos < 0 || pos > 100){
        printf("The character is not in the string\n");
    } else {
        printf("position=%d\n", pos);
    }

    return 0;
}