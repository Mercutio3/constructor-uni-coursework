#include <stdio.h>

int main(){
    double readD;
    float readFloat;
    int readInt;

    scanf("%lf", &readD);
    scanf("%f", &readFloat);
    scanf("%d", &readInt);

    double result = readD * readFloat * readInt;
    printf("%lf\n", result);

    double *r_ptr = &result;
    *r_ptr += 5;

    printf("%lf\n", result);
    printf("%lf\n", *r_ptr);

    return 0;
}