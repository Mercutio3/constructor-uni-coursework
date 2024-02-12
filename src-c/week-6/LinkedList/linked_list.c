/*
CH-230-A
a6_p8.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

struct list* insertFront(struct list *linked_list, int num);
struct list* insertBack(struct list *linked_list, int num);
struct list* deleteFirst(struct list *linked_list);
void disposeList(struct list* linked_list);
void printList(struct list* linked_list);

//Define structure "list"
struct list {
    int info;
    struct list *next;
};

int main() {
    //Initialize structure and characters
    struct list* linked_list = NULL;
    char choice;
    int read;

    while(1){
        //Infinte loop that continuously reads user input and executes code accordingly
        scanf("%c", &choice);
        getchar();
        switch(choice){
            case 'a':
                scanf("%d", &read);
                getchar();
                linked_list = insertBack(linked_list, read);
                break;
            case 'b':
                scanf("%d", &read);
                getchar();
                linked_list = insertFront(linked_list, read);
                break;
            case 'p':
                printList(linked_list);
                break;
            case 'q':
                disposeList(linked_list);
                exit(0);
                break;
            case 'r':
                linked_list = deleteFirst(linked_list);
                break;
            default:
                printf("Wrong input.");
                break;
        }
    }

    return 0;
}

struct list* insertFront(struct list *linked_list, int num){
    //Insert element in the beginning of the linked list
    struct list *newEl;
    newEl = (struct list *) malloc(sizeof(struct list));
    if(newEl == NULL){
        printf("Memory allocation error.\n");
        return linked_list;
    }
    newEl->info = num;
    newEl->next = linked_list;
    return newEl;
}

struct list* insertBack(struct list *linked_list, int num){
    //Insert element in the end of the linked list
    struct list *cursor, *newEl;
    cursor = linked_list;
    newEl = (struct list *) malloc(sizeof(struct list));
    if(newEl == NULL){
        printf("Memory allocation error.\n");
        return linked_list;
    }
    newEl->info = num;
    newEl->next = NULL;
    if(linked_list == NULL){
        return newEl;
    }
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = newEl;
    return linked_list;
}

struct list* deleteFirst(struct list *linked_list){
    //Delete first element of linked list
    struct list *newEl;
    if(linked_list == NULL){
        return linked_list;
    } else {
        newEl = linked_list;
        linked_list = linked_list->next;
        free(newEl);
    }
    return linked_list;
}

void printList(struct list* linked_list){
    //Print all elements of linked list
    while(linked_list != NULL){
        printf("%d ", linked_list->info);
        linked_list = linked_list->next;
    }
    printf("\n");
}

void disposeList(struct list* linked_list){
    //Free memory occupied by linked list
    struct list *nextElem;
    while(linked_list != NULL){
        nextElem = linked_list->next;
        free(linked_list);
        linked_list = nextElem;
    }
}