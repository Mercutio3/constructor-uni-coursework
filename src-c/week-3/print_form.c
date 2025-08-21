/*
CH-230-A
a3_p7.c 
Santiago Dominguez
21 September 2022
Prints a trapezoid with attributes read from user input
*/

#include <stdio.h>
void print_form(int n, int m, char c);

int main() {
    //Initialize variables
    int n, m;
    char c;
    char line[100], line2[100], line3[2];
    
    //Read user input
    printf("Enter height: \n");
    fgets(line, sizeof(line),stdin);
    sscanf(line,"%d",&n);
    printf("Enter width: \n");
    fgets(line2, sizeof(line),stdin);
    sscanf(line2,"%d",&m);
    printf("Enter character: \n");
    fgets(line3, sizeof(line),stdin);
    sscanf(line3,"%c",&c);

    //Call print_form function
    print_form(n,m,c);

    return 0;
}

void print_form(int n, int m, char c){
    printf("Printing trapezoid with height %d, bases %d and %d+%d-1, consising of character %c\n",n,m,n,m,c);
    //Nested for loops print the trapezoid with the given parameters
    for(int i = 0; i <= m; i++){
        for(int j = m-i; j < n+m-1; j++){
            printf("%c ",c);
        }
        printf("\n");
    }
}