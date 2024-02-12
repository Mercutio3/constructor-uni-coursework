/* Operating Systems 2023 Problem Set #2
 * Problem 2.2: bench - measure command execution time
 * Santiago Dominguez
 * 22 September 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

//Return current time at the moment function is called
long long getTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000 + (long long)ts.tv_nsec / 1000;
}

int main(int argc, char *argv[]) {
    char *commands[50];
    int cmdNum = 0;
    //Default amount of warmup runs and time duration. Can be changed!
    int warmups = 0;
    int seconds = 5; 

    //Parse command line input with getopt()
    int opt;
    while ((opt = getopt(argc, argv, "d:w:")) != -1) {
	    switch (opt) {
            case 'd':
                seconds = atoi(optarg);
                break;
            case 'w':
                warmups = atoi(optarg);
                break;
	        default:
	            fprintf(stderr, "Usage: ./bench [-w warmups] [-d seconds] command [args]\n");
	            return(EXIT_FAILURE);
	    }
    }

    //Parse remaining command arguments, store them in commands[]
    for(int i = optind; i < argc; i++){
        commands[cmdNum++] = argv[i];
    }
    if(cmdNum == 0){
        //No command provided
        fprintf(stderr, "Usage: ./bench [-w warmups] [-d seconds] command [args]\n");
        return EXIT_FAILURE;
    }
    commands[cmdNum] = NULL;

    //Execute number of warmup runs specified
    for(int i = 0; i < warmups; i++){
        pid_t processID;
        int status;

        if((processID = fork()) == 0){
            //Child process, execute command
            execvp(commands[0], commands);
            exit(1);
        } else if(processID < 0){
            //Failure to fork()
            fprintf(stderr, "Error: Could not fork.\n");
            return EXIT_FAILURE;
        } else {
            //Parent process, wait for children
            waitpid(processID, &status, 0);
        }
    }

    //Initialize variables for benchmark data collection
    long long shortestRun = -1;
    long long longestRun = -1;
    long long totalTime = 0;
    int totalRuns = 0;
    int failRuns = 0;

    //Execute command in a loop for duration specified, obtain statistics
    long long startTime = getTime();
    while(getTime() - startTime < seconds * 1000000) {
        pid_t processID;
        int status;
        long long runStartTime, runEndTime;

        runStartTime = getTime();

        if((processID = fork()) == 0){
            //Child process, execute command
            execvp(commands[0], commands);
            exit(1);
        } else if(processID < 0){
            //Failure to fork()
            fprintf(stderr, "Error: Fork failed.\n");
            return EXIT_FAILURE;
        } else {
            //Parent process, wait for children
            waitpid(processID, &status, 0);
            runEndTime = getTime();
            long long runTime = runEndTime - runStartTime;
            totalRuns++;

            if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
                totalTime += runTime;
            } else {
                failRuns++;
            }
            
            //Update min and max runtimes
            if(shortestRun == -1 || runTime < shortestRun){
                shortestRun = runTime;
            }
            if(runTime > longestRun){
                longestRun = runTime;
            }
        }
    }

    //Print run summary info
    printf("Warmups: %d\n", warmups);
    printf("Runs: %d\n", totalRuns);
    printf("Fails: %d\n", failRuns);
    //Time info
    printf("Min: %.6f seconds\n", shortestRun / 1000000.0);
    double avgTime = (double)totalTime / (totalRuns);
    printf("Avg: %.6f seconds\n", avgTime / 1000000.0);
    printf("Max: %.6f seconds\n", longestRun / 1000000.0);
    printf("Total: %.6f seconds\n", totalTime / 1000000.0);

    return EXIT_SUCCESS;
}