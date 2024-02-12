#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_matrix(int **A, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r, c;
    FILE *inFile = fopen("matrix.dat", "r");
    assert(inFile!=NULL);

    fscanf(inFile, "%d", &r);
    fscanf(inFile, "%d", &c);

    int **matrix = malloc(sizeof(int*)*r);
    assert(matrix!=NULL);

    for(int i=0;i<r;i++){
        matrix[r] = malloc(sizeof(int)*c);
        assert(matrix[r]!=NULL);
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            matrix[r][c] = 0;
        }
    }

    int x, y, value;
    fscanf(inFile, "%d %d %d", &x, &y, &value);
    matrix[x-1][y-1] = value;
    fscanf(inFile, "%d %d %d", &x, &y, &value);
    matrix[x-1][y-1] = value;

    print_matrix(matrix, r, c);

    for(int i=0; i<r; i++){
        free(matrix[i]);
    }

    free(matrix);
    fclose(inFile);
    return 0;
}