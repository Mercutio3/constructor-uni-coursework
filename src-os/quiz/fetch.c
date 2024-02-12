#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "quiz.h"

extern char* fetch(char* url){
    //Initialize variables, create pipe, check for errors
    int pipe_fd[2];
    int maxResponseSize = 4096;
    char response[maxResponseSize];
    int status;
    if(pipe(pipe_fd) == -1){
        perror("Pipe error.");
        return NULL;
    }

    //Fork, check for error
    pid_t childpid = fork();
    if(childpid == -1){
        perror("Forking error.");
        return NULL;
    }

    if(childpid == 0){
        //Child process
        close(pipe_fd[0]);

        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);

        //Run curl command with given URL in silent mode
        execlp("curl", "curl", "-s", url, NULL);

        //Handle execlp error
        perror("Execlp failed.");
        return NULL;
    } else {
        //Parent process
        close(pipe_fd[1]);

        //Read pipe data, handle error
        int bytesRead = read(pipe_fd[0], response, maxResponseSize);
        close(pipe_fd[0]);
        if(bytesRead < 0){
            perror("Read error.");
            return NULL;
        }

        //Wait for child process, return curled data
        waitpid(childpid, &status, 0);
        if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
            response[bytesRead] = 0;
            return strdup(response);
        } else {
            fprintf(stderr, "\n", WEXITSTATUS(status));
            return NULL;
        }
    }
}