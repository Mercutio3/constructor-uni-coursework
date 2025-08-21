/*
CH-230-A
a4_p8.c 
Santiago Dominguez
27 September 2022
Prints a square matrix of given dimensions, then elements under secondary diagonal
*/

#include <stdio.h>
#include <stdlib.h>

const int maxRow = 30;
const int maxCol = 30;
void printMatrix(int row, int col, int matrix[][maxCol]);
void printUnderSecDiag(int row, int col, int matrix[][maxCol]);

int main(){
    int matrix[maxRow][maxCol];
    int row, col;
    scanf("%d",&row);
    col = row;

    //Initialize array and fill in ints
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int read;
            scanf("%d",&read);
            matrix[i][j] = read;
        }
    }

    printf("The entered matrix is:\n");
    printMatrix(row,col,matrix);
    
    printf("Under the secondary diagonal:\n");
    printUnderSecDiag(row,col,matrix);

    return 0;
    
}

void printMatrix(int row, int col, int matrix[][maxCol]){
    //For loop through the array printing all elements
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printUnderSecDiag(int row, int col, int matrix[][maxCol]){
    //For loop wizardry to print elements under sec diag
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(row - i - 1 < j){
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}