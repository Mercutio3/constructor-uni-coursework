/*
CH-230-A
a6_p9.c
Santiago Dominguez
13 October 2022
Extends linked_list.c to allow reversing elements, reversing list, and counting
 */

#include <stdio.h>
#include <stdlib.h>

struct list* insertFront(struct list *linked_list, int num);
struct list* insertBack(struct list *linked_list, int num);
struct list* insertAt(struct list **linked_list, int num, int place);
struct list* deleteFirst(struct list *linked_list);
void disposeList(struct list* linked_list);
void printList(struct list* linked_list);
void reverseElem(struct list* cursor, struct list* prevElem, struct list** head);
void reverseList(struct list** head);
int countElems(struct list* linked_list);

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
    int pos;

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
            case 'i':
                scanf("%d", &pos);
                getchar();
                scanf("%d", &read);
                getchar();
                linked_list = insertAt(&linked_list, read, pos);
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
            case 'R':
                reverseList(&linked_list);
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

struct list* insertAt(struct list **linked_list, int num, int place){
    //Check if position is valid
    if(place < 0 || place > countElems(*linked_list)){
        printf("Invalid position!\n");
        return *linked_list;
    }

    //Allocate memory for new element
    struct list* cursor = *linked_list;
    struct list* newEl;
    newEl = (struct list *) malloc(sizeof(struct list));
    newEl->info = num;
    newEl->next = NULL;

    //Insert element in place
    while(--place){
        cursor = cursor->next;
    }
    newEl->next = cursor->next;
    cursor->next = newEl;
    
    return *linked_list;
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

void reverseElem(struct list* cursor, struct list* prevElem, struct list** linked_list){
    //Reverse linked list using only pointers
    if(!cursor->next){
        *linked_list = cursor;
        cursor->next = prevElem;
        return;
    }
    struct list* next = cursor->next;
    cursor->next = prevElem;
    reverseElem(next, cursor, linked_list);
}

void reverseList(struct list** linked_list){
    //Call recursive function reverseElem to reverse linked list
    if(!linked_list){
        return;
    }
    reverseElem(*linked_list, NULL, linked_list);
}

int countElems(struct list* linked_list){
    int count = 0;
    struct list* cursor = linked_list;
    while(cursor != NULL){
        count++;
        cursor = cursor->next;
    }
    return count;
}