#include <stdio.h>

void total_time(int mins[], int secs[], int n, int *sum_min, int *sum_sec);

int main(){
    int sum_min = 0;
    int sum_sec = 0;
    int mins[] = {3,4,5};
    int secs[] = {30,40,10};
    total_time(mins,secs,3,&sum_min,&sum_sec);

    printf("total time: %d mins %d sec\n", sum_min, sum_sec);

    return 0;
}

void total_time(int mins[], int secs[], int n, int *sum_min, int *sum_sec){
    int totalMins = 0;
    int totalSecs = 0;
    for(int i = 0; i < n; i++){
        totalMins += mins[i];
        totalSecs += secs[i];
    }
    totalMins += totalSecs/60;
    totalSecs %= 60;
    *sum_min = totalMins;
    *sum_sec = totalSecs;
}