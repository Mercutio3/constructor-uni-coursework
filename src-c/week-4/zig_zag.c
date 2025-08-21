/*
CH-230-A
a4_p2.c 
Santiago Dominguez
27 September 2022
Prints string in zig-zag shape
*/

#include <stdio.h>
#include <string.h>

int main(){
    //Read string and store it in character array
    char string[50];
    fgets(string,sizeof(string),stdin);
    string[strcspn(string, "\n")] = 0;

    //For loop to print zigzag, using strLen function and mod operator
    for(int i = 0; i < strlen(string); i++){
        if(i % 2 != 0){
            printf(" %c\n",string[i]);
        } else {
            printf("%c\n",string[i]);
        }
    }

    return 0;
}