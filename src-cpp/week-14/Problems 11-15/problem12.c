#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct river {
    char name[40];
    int length;
    int drainage_area;
}river;

int comp(const void *a, const void *b){
    river* x = (river*)a;
    river* y = (river*)b;
    return x->length-y->length;
}

int main(){
    river riverList[30];
    FILE *inputFile = fopen("data.txt", "r");
    assert(inputFile!=NULL);

    int index = 0;

    while(1){
        if(index%3 == 0 && fscanf(inputFile, "%s", riverList[index/3].name)==EOF){
            break;
        }
        if(index%3 == 1 && fscanf(inputFile, "%d", &riverList[index/3].length)==EOF){
            break;
        }
        if(index%3 == 2 && fscanf(inputFile, "%d", &riverList[index/3].drainage_area)==EOF){
            break;
        }
        index++;
    }
    fclose(inputFile);

    qsort(riverList, (index-1)/3+1, sizeof(river), comp);
    for(int i = 0; i <= (index-1)/3; i++){
        printf("%s %d %d\n", riverList[i].name, riverList[i].length, riverList[i].drainage_area);
    }

    FILE *output = fopen("output2.txt", "w");
    assert(output!=NULL);

    for(int i = 0; i <= (index-1)/3; i++){
        fprintf(output,"%s %d %d\n", riverList[i].name, riverList[i].length, riverList[i].drainage_area);
    }
    fclose(output);
}