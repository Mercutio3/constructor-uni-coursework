/*
CH-230-A
a4_p11.c 
Santiago Dominguez
29 September 2022
Case-insensitive count of characters in a dyanmically allocated array
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count_insensitive(char *str, char c);
const int MAX_STRING_LENGTH = 50;

int main(){
    //Intiialize dynamic array, allocate memory, and ensure array isn't empty
    char *dyn_chars;
    dyn_chars = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
    if(dyn_chars == NULL){
        exit(1);
    }
    
    //Read string, determine length
    printf("Input string:\n");
    fgets(dyn_chars, MAX_STRING_LENGTH, stdin);

    //Intitialize dynamic array of correct length, allocate memory, copy old array to new, free old array
    char *dyn_str;
    dyn_str = (char*) malloc(sizeof(char) * strlen(dyn_chars));
    strcpy(dyn_str, dyn_chars);
    
    free(dyn_chars);

    //Call count_insensitive for all 5 characters
    printf("The character 'b' occurs %d times.\n", count_insensitive(dyn_str, 'b'));
    printf("The character 'H' occurs %d times.\n", count_insensitive(dyn_str, 'H'));
    printf("The character '8' occurs %d times.\n", count_insensitive(dyn_str, '8'));
    printf("The character 'u' occurs %d times.\n", count_insensitive(dyn_str, 'u'));
    printf("The character '$' occurs %d times.\n", count_insensitive(dyn_str, '$'));

    free(dyn_str);

    return 0;
}

int count_insensitive(char *str, char c){
    int charCount = 0;
    int stringLength = strlen(str);
    
    //Create copy of input string
    char *lower_str;
    lower_str = (char*) malloc(sizeof(char) * strlen(str));
    strcpy(lower_str, str);

    //Convert string and character to all lowercase
    for (int i = 0; i < stringLength; i++) {
        lower_str[i] = tolower(str[i]);
    }
    
    char search = tolower(c);

    //Count instances of c in str
    for(int j = 0; j < stringLength; j++){
        if(lower_str[j] == search){
            charCount++;
        }
    }

    free(lower_str);
    return charCount;
}