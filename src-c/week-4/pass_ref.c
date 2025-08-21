/*
CH-230-A
a4_p10.c 
Santiago Dominguez
2 October 2022
Performs float arithmetic, returning results by pointer reference
*/

#include <stdio.h>
#include <math.h>
void proddivpowinv(float a, float b, float *prod, float *div, float *pwr, float *invb);

int main(){
    //Initialize variables where the computation results will be "returned"
    float product;
    float division;
    float power;
    float inverse;

    //Initialize pointers
    float *prod = &product;
    float *div = &division;
    float *pwr = &power;
    float *invb = &inverse;
    
    //Initialize user-defined variables and read input into them
    float float1;
    float float2;
    printf("Enter two floats:\n");
    scanf("%f",&float1);
    scanf("%f", &float2);

    //Call function
    proddivpowinv(float1, float2, prod, div, pwr, invb);

    //Print results 
    printf("Product of the two floats: %f\n", product);
    printf("Divison of the two floats: %f\n", division);
    printf("A raised to the power of b: %f\n", power);
    printf("Inverse of b (1/b): %f\n", inverse);

    return 0;
}

void proddivpowinv(float a, float b, float *prod, float *div, float *pwr, float *invb){
    //Compute results and "return" them by reference
    *prod = a * b;
    *div = a / b;
    *pwr = pow(a,b);
    *invb = 1/b;
}