#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include "player.h"
#include "chlng.h"

#define BACKLOG 5 //Max number of clients that can be queued up waiting for server

void mode_blocking(int client_socket) {
    player_t* player = player_new();

    //Send welcome message and instructions to client
    char* welcomeMsg;
    if(player_get_greeting(player, &welcomeMsg) == EXIT_SUCCESS) {
        send(client_socket, welcomeMsg, strlen(welcomeMsg), 0);
        free(welcomeMsg);
    } else {
        fprintf(stderr, "Error sending welcome message.\n");
    }

    //Main gameplay loop 
    while (!player->finished) {
        char* msg;
        int rc;

        //Get challenge, send to client
        rc = player_get_challenge(player, &msg);
        if (rc == 0) {
            send(client_socket, msg, strlen(msg), 0);
            free(msg);
        } else {
            fprintf(stderr, "Error getting challenge.\n");
            break;
        }

        //Receive from client
        char buffer[256];
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if(bytes_received <= 0){
            printf("Client disconnected.\n");
            break;
        }
        buffer[bytes_received] = '\0';

        //Process user input, send result to client
        rc = player_post_challenge(player, buffer, &msg);
        if(rc == 0){
            send(client_socket, msg, strlen(msg), 0);
            free(msg);
        }

        //Break loop after player quits
        if(player->finished){
            printf("Client disconnected.\n");
            break;
        }
    }

    // Clean up player resources
    player_del(player);
    close(client_socket);
}

void* mode_threading(void* arg) {
    //Simple thread handling, arg isn't needed anymore
    int client_socket = *((int*)arg);
    free(arg);

    mode_blocking(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    //Initialize default mode and port (string)
    char* mode = "blocking";
    char* port = "12345";
    int modeOpt;

    //Switch statement to read console args
    while((modeOpt = getopt(argc, argv, "tfp:")) != -1){
        switch(modeOpt){
            case 't':
                mode = "threading"; //Switch to 'threading' mode
                break;
            case 'f':
                mode = "forking"; //Switch to 'forking' mode
                break;
            case 'p':
                port = optarg; //Change port
                break;
            default:
                fprintf(stderr, "Usage: ./server [-t] [-f] [-p PORT_NUM]\n");
                return EXIT_FAILURE;
        }
    }
    printf("Running in %s mode.\n", mode);
    
    //Socket initialization
    int server_fd, client_socket;
    struct sockaddr_storage client_addr;
    socklen_t addr_size = sizeof client_addr;
    struct addrinfo hints, *res, *p;
    int opt = 1;

    //Support IPv4 and IPv6, SOCK_STREAM for TCP, and localhost
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    //Get address information
    if (getaddrinfo(NULL, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    //Loop through results, bind to first one available
    for(p = res; p != NULL; p = p->ai_next){
        //Create socket
        if((server_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        //Set socket options
        if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1){
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        //Bind socket to address and port
        if(bind(server_fd, p->ai_addr, p->ai_addrlen) == -1){
            close(server_fd);
            perror("bind");
            continue;
        }
        break;
    }

    //Free linked list
    freeaddrinfo(res);

    //Check if we bound successfully
    if(p == NULL){
        fprintf(stderr, "Failed to bind.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, BACKLOG) == -1){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %s.\n", port);

    int clientTotal = 0;
    while(1){
        //Accept a new connection
        client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
        if(client_socket == -1){
            perror("accept");
            continue;
        }

        char client_ip[INET6_ADDRSTRLEN];
        if(client_addr.ss_family == AF_INET){
            inet_ntop(AF_INET, &((struct sockaddr_in*)&client_addr)->sin_addr, client_ip, sizeof client_ip);
        } else { // AF_INET6
            inet_ntop(AF_INET6, &((struct sockaddr_in6*)&client_addr)->sin6_addr, client_ip, sizeof client_ip);
        }

        printf("Client %d connected with IP %s.\n", ++clientTotal, client_ip);

        //Proceed according to operating mode set by user
        if(strcmp(mode, "forking") == 0){
            //Forking mode
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                close(client_socket);
            } else if (pid == 0) {
                //Child process: cose server socket, handle client
                close(server_fd);
                mode_blocking(client_socket);
                exit(EXIT_SUCCESS);
            } else {
                //Parent process: close client socket
                close(client_socket); 
            }
        } else if(strcmp(mode, "threading") == 0){
            //Threading mode
            pthread_t tid;
            int* client_socket_ptr = (int*)malloc(sizeof(int));
            if (client_socket_ptr == NULL) {
                perror("malloc");
                close(client_socket);
                continue;
            }
            *client_socket_ptr = client_socket;

            //Create thread, check for errors, detach for automatic cleanup
            if (pthread_create(&tid, NULL, mode_threading, client_socket_ptr) != 0) {
                perror("pthread_create");
                close(client_socket);
                free(client_socket_ptr);
            } else {
                pthread_detach(tid);
            }
        } else {
            //Blocking mode (default)
            mode_blocking(client_socket);
        }
    }

    return EXIT_SUCCESS;
}