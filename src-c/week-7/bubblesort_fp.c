/*
CH-230-A
a7_p6.c
Santiago Dominguez
21 October 2022
Implements Bubble Sort for name and age attributes of a "person" struct
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[30];
    int age;
};

void bubbleSort(struct person *people, int numPeople, int (*compareFunc)(struct person *personOne, struct person *personTwo)){
    //Loop through people array and call adequate sorting function for all elements
    for(int i = 0; i < numPeople; i++){
        for(int j = 0; j < numPeople-1; j++){
            if (compareFunc(&people[j+1], &people[j] ) < 0 ){
                struct person temp = people[j+1];
                people[j+1] = people[j];
                people[j] = temp;
            }
        }
    }
}

int nameComp(struct person *personOne, struct person *personTwo){
    //Compare names using strcmp function; if they're the same, compare ages
    int nameCompare = strcmp(personOne->name, personTwo->name);
    int intCompare = (personTwo->age < personOne->age) - (personOne->age < personTwo->age);
    return nameCompare != 0 ? nameCompare : intCompare;
}

int ageComp(struct person *personOne, struct person *personTwo){
    //Compare ages; if they're the same, compare names using strcmp function
    int nameCompare = strcmp(personOne->name, personTwo->name);
    int ageCompare = (personTwo->age < personOne->age) - (personOne->age < personTwo->age);
    return ageCompare != 0 ? ageCompare : nameCompare;
}

void printArray(struct person people[], int numPeople){
    //Print the people array
    for(int i = 0; i < numPeople; i++){
        printf("{%s, %d}; ", people[i].name, people[i].age);
    }
    printf("\n");
}

int main(){
    //Read array size int, intiialize array
    int numPeople;
    scanf("%d", &numPeople);
    getchar();

    struct person people[numPeople];

    //Read names of people and their ages from user input
    for(int i = 0; i < numPeople; i++){
        fgets(people[i].name, 30, stdin);
        people[i].name[strlen(people[i].name)-1]='\0';
        scanf("%d", &people[i].age);
        getchar();
    }

    //Call bubblesort with appropriate sort function, call print function
    bubbleSort(people, numPeople, nameComp);
    printArray(people, numPeople);
    bubbleSort(people, numPeople, ageComp);
    printArray(people, numPeople);
}