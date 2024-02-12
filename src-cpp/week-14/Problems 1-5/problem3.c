#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    int n;
    int *numArray;
    int currInt;
    scanf("%d", &n);

    numArray = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &currInt);
        numArray[i] = currInt;
    }

    FILE *outputFile = fopen("squares.txt","w");
    assert(outputFile!=NULL);

    for(int i = n-1; i >= 0; i--){
        fprintf(outputFile, "%d %d \n", numArray[i], numArray[i]*numArray[i]);
    }

    fclose(outputFile);
    free(numArray);

    return 0;
}