/*
CH-230-A
a5_p9.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
void readMatrix(int ***matrix, int rows, int cols, int depth);
void printMatrix(int ***matrix, int rows, int cols, int depth);

int main(){
    //Initialize variables, read user input for matrix dimensions
    int ***matrix;
    int x, y, z;
    scanf("%d", &x);
    getchar();
    scanf("%d", &y);
    getchar();
    scanf("%d", &z);
    getchar();

    //Allocate memory for three-dimensional matrix
    matrix = (int ***) malloc(x * sizeof(int));
    if(matrix == NULL){
        exit(1);
    }
    for(int row = 0; row < x; row++){
        matrix[row] = (int **) malloc(y * sizeof(int));
        if(matrix[row] == NULL){
            exit(1);
        }
    }   
    for(int row = 0; row < x; row++){
        for(int col = 0; col < y; col++){
            matrix[row][col] = (int *) malloc(z * sizeof(int));
            if(matrix[row][col] == NULL){
                exit(1);
            }
        }
    }

    //Call functions that compute and print results
    readMatrix(matrix, x, y, z);
    printMatrix(matrix, x, y, z);

    //Free memory allocated to the matrix
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void readMatrix(int ***matrix, int rows, int cols, int depth){
    //Write values for matrix using nested for loops
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            for(int k = 0; k < depth; k++){
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }
}

void printMatrix(int ***matrix, int rows, int cols, int depth){
    //Print values for matrix using nested for loops
    for(int k = 0; k < depth; k++){
        printf("Section %d:\n", k+1);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
    }
}