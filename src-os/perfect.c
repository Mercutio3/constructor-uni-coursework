/* Operating Systems 2023 Problem Set #3
 * Problem 3.2: perfect numbers (multi-threading)
 * Santiago Dominguez
 * 29 September 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <time.h>

//Function that returns time at the moment it is called
long long getTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000 + (long long)ts.tv_nsec / 1000;
}

//Global verbose flag used to print thread debugging info
static int verbose = 0;

//Timekeeping variables
static long long startTime, endTime;

//Define thread_data object
struct thread_data{
    int threadID;
    int lowBound;
    int uppBound;
};

//Function that tests whether a given number is perfect
static int is_perfect(uint64_t num){
    uint64_t i, sum;
    if (num < 2) {
        return 0;
    }
    
    for (i = 2, sum = 1; i*i <= num; i++) {
        if (num % i == 0) {
            sum += (i*i == num) ? i : i + num / i;
        }
    }
    return (sum == num);
}

//Function takes in a thread_data object, checks for perfect numbers in its interval
//Also prints debugging info if -v is enabled
void *findPerfects(void* threadarg){
    struct thread_data *myData;
    myData = (struct thread_data *) threadarg;
    if(verbose){
        fprintf(stderr, "perfect: t%d searching [%d,%d]\n", myData->threadID, myData->lowBound, myData->uppBound);
    }
    for(int i = myData->lowBound; i <= myData->uppBound; i++){
        if(is_perfect(i)){
            printf("%d\n", i);
            fflush(stdout);
        }
    }
    if(verbose){
        fprintf(stderr, "perfect: t%d finishing\n", myData->threadID);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    //Define default values for lower and upper search boundaries and thread count
    int threadCount = 1;
    int lowerBound = 1;
    int upperBound = 10000;
    
    //Parse command line input with getopt()
    int opt;
    while ((opt = getopt(argc, argv, "s:e:t:v")) != -1){
        switch (opt){
            case 's':
                //Change lower boudnary
                lowerBound = atoi(optarg);
                break;
            case 'e':
                //Change upper boundary
                upperBound = atoi(optarg);
                break;
            case 't':
                //Change thread count
                threadCount = atoi(optarg);
                break;
            case 'v':
                //Enable verbose mode
                verbose = 1;
                break;
            default:
                //Print correct syntax
                fprintf(stderr, "Usage: ./perfect [-s lowBound] [-e highBound] [-t threadCount]\n");
                return EXIT_FAILURE;
        }
    }

    startTime = getTime();
    //If thread count is 1, no need to create additional threads
    if(threadCount == 1){
        struct thread_data single_thread_array;
        single_thread_array.threadID = 0;
        single_thread_array.lowBound = lowerBound;
        single_thread_array.uppBound = upperBound;
        findPerfects(&single_thread_array);
    } else {
        //Create array of thread datas and another of thread IDs
        struct thread_data thread_data_array[threadCount];
        pthread_t tIDs[threadCount];
        
        //Define partition width for each thread
        double partitionWidth = (upperBound - lowerBound) / (double)threadCount;

        int rc, status = EXIT_SUCCESS;

        //For each thread, calculate its lower and upper boudnaries, run findPerfects()
        for(int i = 0; i < threadCount; i++){
            thread_data_array[i].threadID = i;
            thread_data_array[i].lowBound = lowerBound + i * partitionWidth;
            thread_data_array[i].uppBound = i == threadCount - 1 ? upperBound : lowerBound + (i + 1) * partitionWidth;
            rc = pthread_create(&tIDs[i], NULL, findPerfects, (void *) &thread_data_array[i]);
            if(rc){
                //Error message if thread creation fails
                fprintf(stderr, "pthread_create() failed: %s\n", strerror(rc));
                status = EXIT_FAILURE;
            }
        }

        //Join threads after execution finishes
        for(int i = 1; i < threadCount; i++){
            if(tIDs[i]){
                rc = pthread_join(tIDs[i], NULL);
                if(rc){
                    //Error message if thread joining fails
                    fprintf(stderr, "pthread_join() failed: %s\n", strerror(rc));
                    status = EXIT_FAILURE;
                }
            }
        }
        endTime = getTime();
        if(verbose){
            printf("Time: %.6f seconds\n", (endTime - startTime) / 1000000.0);
        }
        return status;
    }

    return EXIT_SUCCESS;
}