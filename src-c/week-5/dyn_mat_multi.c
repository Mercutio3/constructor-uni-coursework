/*
CH-230-A
a5_p8.c
Santiago Dominguez
5 October 2022
Multiplies two dynamically allocated matrices of given dimensions and characters
 */

#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols, char id);
void computeResult(int **matrix1, int **matrix2, int **resultMatrix, int rows, int cols);

int main(){
    //Initialize variables and read values for n, m, and p
    int **matrix1, **matrix2, **matrix3;
    int n, m, p;
    scanf("%d", &n);
    getchar();
    scanf("%d", &m);
    getchar();
    scanf("%d", &p);
    getchar();

    //Initialize first matrix
    matrix1 = (int **) malloc(n * sizeof(int));
    if(matrix1 == NULL){
        exit(1);
    }
    for(int row = 0; row < n; row++){
        matrix1[row] = (int *) malloc(m * sizeof(int));
        if(matrix1[row] == NULL){
            exit(1);
        }
    }

    //Initialize second matrix
    matrix2 = (int **) malloc(m * sizeof(int));
    if(matrix2 == NULL){
        exit(1);
    }
    for(int row = 0; row < m; row++){
        matrix2[row] = (int *) malloc(p * sizeof(int));
        if(matrix2[row] == NULL){
            exit(1);
        }
    }

    //Initialize result matrix
    matrix3 = (int **) malloc(n * sizeof(int));
    if(matrix3 == NULL){
        exit(1);
    }
    for(int row = 0; row < n; row++){
        matrix3[row] = (int *) malloc(p * sizeof(int));
        if(matrix3[row] == NULL){
            exit(1);
        }
    }

    //Call functions to write values into matrices and compute result matrix
    readMatrix(matrix1, n, m);
    readMatrix(matrix2, m, p);
    computeResult(matrix1, matrix2, matrix3, n, p);

    //Print results
    printMatrix(matrix1, n, m, 'A');
    printMatrix(matrix2, m, p, 'B');
    printMatrix(matrix3, n, p, '$');

    //Free memory allocated to the three matrices
    for(int i = 0; i < n; i++){
        free(matrix1[i]);
        free(matrix3[i]);
    }
    for(int i = 0; i < m; i++){
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);

    return 0;
}

void readMatrix(int **matrix, int rows, int cols){
    //Write values for matrix using nested for loops
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols, char id){
    //Print values for matrix using nested for loops
    if(id == '$'){
        printf("The multiplication result AxB:\n");
    } else {
        printf("Matrix %c:\n", id);
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void computeResult(int **matrix1, int **matrix2, int **resultMatrix, int rows, int cols){
    //Iterate through the two matrices, calculate sum of multiplications accordingly
    //Assign result to its appropriate place in the result matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            resultMatrix[i][j] = 0;
            for(int k = 0; k < cols; k++){
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }            
        }
    }
}