/* Operating Systems 2023 Problem Set #4
 * Problem 4.1: multi-threaded coin flipping
 * Santiago Dominguez
 * 5 October 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

//Define coin array, global lock, and mutex array for strategy 3
char coinArray[21] = "0000000000XXXXXXXXXX";
pthread_mutex_t gLock;
pthread_mutex_t coinLockArray[20];

//Define default values for persons and flips
int people = 100;
int flips = 10000;

//Flips a given coin in the coin array.
void flipCoin(int coinNum){
    if(coinArray[coinNum] == '0'){
        coinArray[coinNum] = 'X';
    } else {
        coinArray[coinNum] = '0';
    }
}

//Strategy 1 - global lock to protect all coins
void *globalLock(){
    pthread_mutex_lock(&gLock);
    for(int i = 0; i < flips; i++){
        
        for(int j = 0; j < 20; j++){
            flipCoin(j);
        }
    }
    pthread_mutex_unlock(&gLock);
    pthread_exit(NULL);
}

//Strategy 2 - global lock for each iteration
void *iterationLock(){
    for(int i = 0; i < flips; i++){
        pthread_mutex_lock(&gLock);
        for(int j = 0; j < 20; j++){
            flipCoin(j);
        }
        pthread_mutex_unlock(&gLock);
    }
    pthread_exit(NULL);
}

//Strategy 3 - separate lock for each coin
void *coinLock(){
    for(int i = 0; i < flips; i++){
        for(int j = 0; j < 20; j++){
            pthread_mutex_lock(&coinLockArray[j]);
            flipCoin(j);
            pthread_mutex_unlock(&coinLockArray[j]);
        }
    }
    pthread_exit(NULL);
}

//Creates n threads, each of which will run proc
void run_threads(int n, void* (*proc)(void*)){
    int rc;
    pthread_t tIDs[people];
    //Create threads
    for(int i = 0; i < n; i++){
        rc = pthread_create(&tIDs[i], NULL, proc, NULL);
        if(rc){
            //Error message if thread creation fails
            fprintf(stderr, "pthread_create() failed: %s\n", strerror(rc));
        }
    }

    //Join threads after execution finishes
    for(int i = 1; i < n; i++){
        if(tIDs[i]){
            rc = pthread_join(tIDs[i], NULL);
            if(rc){
                //Error message if thread joining fails
                fprintf(stderr, "pthread_join() failed: %s\n", strerror(rc));
            }
        }
    }
}

//Measures how long it takes to creates n threads and have each run proc
static double timeit(int n, void* (*proc)(void*)){
    clock_t t1, t2;
    t1 = clock();
    run_threads(n, proc);
    t2 = clock();
    return ((double) t2 - (double) t1) / CLOCKS_PER_SEC * 1000;
}

int main(int argc, char *argv[]){
    //Parse command line input with getopt()
    int opt;
    while ((opt = getopt(argc, argv, "p:n:")) != -1){
        switch (opt){
            case 'p':
                //Change lower boudnary
                people = atoi(optarg);
                break;
            case 'n':
                //Change upper boundary
                flips = atoi(optarg);
                break;
            default:
                //Print correct syntax
                fprintf(stderr, "Usage: ./coins [-p numPersons] [-n numFlips]\n");
                return EXIT_FAILURE;
        }
    }

    //Initialize timekeeping variable and all locks to NULL
    double executionTime;
    pthread_mutex_init(&gLock, NULL);
    for (int i = 0; i < 20; i++) {
        pthread_mutex_init(&coinLockArray[i], NULL);
    }

    //--------------STRATEGY 1--------------

    printf("coins: %s (start - global lock)\n", coinArray);
    executionTime = timeit(people, globalLock);
    //Print information after execution
    printf("coins: %s (end - global lock)\n", coinArray);
    printf("%d threads x %d flips: %.3lf microseconds\n", people, flips, executionTime);

    //--------------STRATEGY 2--------------

    printf("coins: %s (start - iteration lock)\n", coinArray);
    executionTime = timeit(people, iterationLock);
    //Print information after execution
    printf("coins: %s (end - iteration lock)\n", coinArray);
    printf("%d threads x %d flips: %.3lf microseconds\n", people, flips, executionTime);

    //--------------STRATEGY 3--------------

    printf("coins: %s (start - coin lock)\n", coinArray);
    executionTime = timeit(people, coinLock);
    //Print information after execution
    printf("coins: %s (end - coin lock)\n", coinArray);
    printf("%d threads x %d flips: %.3lf microseconds\n", people, flips, executionTime);

    return EXIT_SUCCESS;
}