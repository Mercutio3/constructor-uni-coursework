#include <stdio.h>
#include <stdbool.h>

bool odd(unsigned char data);

int main(){
    printf("%d", odd('g'));
    printf("%d", odd('h'));
    return 0;
}

bool odd(unsigned char data){
    int charInt = data;
    return (!(charInt & 1));
}