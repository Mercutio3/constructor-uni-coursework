#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){
    FILE *outputFile = fopen("output.txt", "wb");
    assert(outputFile!=NULL);

    char charBuffer[5] = "a aa\n";

    for(int i = 0; i < 10; i++){
        char curr = 97+i;
        charBuffer[0] = curr;
        charBuffer[1] = ' ';
        charBuffer[2] = curr;
        charBuffer[3] = curr;

        fwrite(charBuffer, sizeof(charBuffer), 1, outputFile);
    }

    fclose(outputFile);

    return 0;
}