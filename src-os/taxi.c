/* Operating Systems 2023 Problem Set #5
 * Problem 5.1: taxi stand offering shared rides
 * Santiago Dominguez
 * 13 October 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//Max size of the stand, defined as a macro
#define STAND_SIZE 20

//Define default number of travelers and drivers
int travelers = 1;
int drivers = 1;

//Define shared variables and taxi stand array
int waitingTravelers = 0;
int waitingDrivers = 0;
int standArray[STAND_SIZE] = {0};

//Define and initialize mutex and condition variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t travelerCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t driverCond = PTHREAD_COND_INITIALIZER;

//Enum for possible person types
enum PersonType{
    TRAVELER,
    DRIVER
};

//Define person struct
struct Person{
    enum PersonType type;
    int id;
};

//Helper function to print taxi stand array
void printStand(){
    printf("taxi: [");
    for(int i = 0; i < STAND_SIZE; i++){
        if(standArray[i] == 1){
            if(i < travelers) {
                printf("t%d, ", i + 1);
            } else {
                printf("d%d, ", i - travelers + 1);
            }
        }
    }
    printf("] ");
}

//Traveler's behavior
void stand_visit_traveler(struct Person* person){
    pthread_mutex_lock(&mutex);
    waitingTravelers++;

    //Print taxi stand and traveler entering message
    printStand();
    printf("Traveler %d entering.\n", person->id);

    //Add traveler to stand and print waiting message
    standArray[person->id - 1] = 1;
    printStand();
    printf("Traveler %d waiting.\n", person->id);

    if (waitingDrivers > 0) {
        //Signal a driver
        pthread_cond_signal(&driverCond);
        waitingDrivers--;
        
        //Print taxi stand, traveler leaving message, and remove traveler from stand
        printStand();
        printf("Traveler %d found a driver and left.\n", person->id);
        standArray[person->id - 1] = 0;
    } else {
        //Wait for a driver
        pthread_cond_wait(&travelerCond, &mutex);
        
        //Print taxi stand, traveler leaving message, and remove traveler from stand
        printStand();
        printf("Traveler %d found a driver and left.\n", person->id);
        standArray[person->id - 1] = 0;
    }

    pthread_mutex_unlock(&mutex);
}

//Driver's behavior
void stand_visit_driver(struct Person* person) {
    pthread_mutex_lock(&mutex);
    
    //Print taxi stand and driver entering message
    printStand();
    printf("Driver %d entering.\n", person->id);

    if (waitingTravelers > 0) {
        while (waitingTravelers > 0) {
            //Signal all travelers
            pthread_cond_signal(&travelerCond);
            waitingTravelers--;
        }

        //Print taxi stand, driver leaving message, and remove driver from stand
        standArray[person->id + travelers - 1] = 1;
        printStand();
        standArray[person->id + travelers - 1] = 0;
        printf("Driver %d picked up all waiting travelers and left.\n", person->id);
        standArray[person->id + travelers - 1] = 0;
    } else {
        //Add driver to stand and print waiting message
        waitingDrivers++;
        standArray[person->id + travelers - 1] = 1;
        printStand();
        printf("Driver %d waiting.\n", person->id);
        
        //Wait for a traveler
        pthread_cond_wait(&driverCond, &mutex);

        //Print taxi stand, driver leaving message, and remove driver from stand
        printStand();
        printf("Driver %d picked up a traveler and left.\n", person->id);
        standArray[person->id + travelers - 1] = 0;
    }

    pthread_mutex_unlock(&mutex);
}

//Mainloop executed by both traveler and driver treads
void* person_life(void* arg) {
    struct Person* person = (struct Person*)arg;

    while(1){
        switch(person->type) {
            case TRAVELER:
                stand_visit_traveler(person);
                break;
            case DRIVER:
                stand_visit_driver(person);
                break;
        }

        //Sleep for a random time before arriving again
        sleep(rand() % 3 + 1);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    //Parse command line input with getopt()
    int opt;
    while ((opt = getopt(argc, argv, "t:d:")) != -1) {
        switch (opt) {
            case 't':
                //Change number of travelers
                travelers = atoi(optarg);
                break;
            case 'd':
                //Change number of drivers
                drivers = atoi(optarg);
                break;
            default:
                //Print correct usage
                fprintf(stderr, "Usage: %s [-t numTravelers] [-d numDrivers]\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    //Initialize random number generator
    srand(time(NULL));

    //Create array of people
    pthread_t person_threads[STAND_SIZE];
    struct Person persons[STAND_SIZE];

    int rc;
    //Create traveler threads
    for (int i = 0; i < travelers; i++) {
        persons[i].type = TRAVELER;
        persons[i].id = i + 1;
        rc = pthread_create(&person_threads[i], NULL, person_life, &persons[i]);
        if(rc){
            //Error message if thread creation fails
            fprintf(stderr, "pthread_create() failed: %s\n", strerror(rc));
            return EXIT_FAILURE;
        }
    }

    //Create driver threads
    for (int i = travelers; i < travelers + drivers; i++) {
        persons[i].type = DRIVER;
        persons[i].id = i - travelers + 1;
        rc = pthread_create(&person_threads[i], NULL, person_life, &persons[i]);
        if(rc){
            //Error message if thread creation fails
            fprintf(stderr, "pthread_create() failed: %s\n", strerror(rc));
            return EXIT_FAILURE;
        }
    }

    //Join threads after execution finishes (this will never happen)
    for (int i = 0; i < travelers + drivers; i++) {
        rc = pthread_join(person_threads[i], NULL);
        if(rc){
            //Error message if thread joining fails
            fprintf(stderr, "pthread_join() failed: %s\n", strerror(rc));
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}