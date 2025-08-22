/*
CH-230-A
a7_p2.c
Santiago Dominguez
18 October 2022
Implements doublely-linked list with insertion, deletion, printing, and reversing
 */

#include <stdio.h>
#include <stdlib.h>

//Define structure "list"
struct list {
    char info;
    struct list *next;
    struct list *prev;
};

void insertFront(struct list** linked_list, char c);
void deleteElem(struct list** linked_list, struct list* del);
void deleteAllChars(struct list** linked_list, char x);
void printList(struct list* linked_list);
void printReverse(struct list** linked_list);
void disposeList(struct list* linked_list);

int main(){
    //Initialize variables and linked list
    int choice;
    char read;
    struct list* linked_list = NULL;

    while(1){
        //Read command
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                //Read character and call insertion function
                scanf("%c", &read);
                getchar();
                insertFront(&linked_list, read);
                break;
            case 2:
                //Read character and call deletion function
                scanf("%c", &read);
                getchar();
                deleteAllChars(&linked_list, read);
                break;
            case 3:
                //Call print list function
                printList(linked_list);
                break;
            case 4:
                //Call reverse print function
                printReverse(&linked_list);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Wrong input.");
                break;
        }
    }

    return 0;
}

void insertFront(struct list** linked_list, char insertChar){
    //Initialize new node, keeping in mind it's always the first in the list
    struct list* newEl = (struct list*) malloc(sizeof(struct list));
    
    newEl->info = insertChar;
    newEl->prev = NULL;
    newEl->next = (*linked_list);
 
    if((*linked_list) != NULL)
        (*linked_list)->prev = newEl;
 
    (*linked_list) = newEl;
}

void deleteElem(struct list** linked_list, struct list* delEl){
    //Function to delete element in given list. Cases where element is the
    //first, last, or head element are handled accordingly.
    if(*linked_list == NULL || delEl == NULL){
        return;
    }
    if(*linked_list == delEl){
        *linked_list = delEl->next;
    }
    if(delEl->next != NULL){
        delEl->next->prev = delEl->prev;
    } 
    if(delEl->prev != NULL){
        delEl->prev->next = delEl->next;
    }  
    free(delEl);
}

void deleteAllChars(struct list** linked_list, char c){
    int opCount = 0;
    
    //Iterate through linked list, if element contained equals c, delete element
    if((*linked_list) == NULL){
        return;
    }
    struct list* current = *linked_list;
    struct list* next;
 
    while(current != NULL){
        if(current->info == c){
            opCount++;
            next = current->next;
            deleteElem(linked_list, current);
            current = next;
        } else {
            current = current->next;
        }
    }
    //If no operations were performed, that means character was not in list
    if(opCount == 0){
        printf("The element is not in the list!\n");
    }
}

void printList(struct list* linked_list){
    //Print all elements of linked list
    while(linked_list != NULL){
        printf("%c ", linked_list->info);
        linked_list = linked_list->next;
    }
    printf("\n");
}

void printReverse(struct list** linked_list){
    //Print list in reverse, starting from the last element
    struct list* last = *linked_list;

    while(last->next != NULL){
        last = last->next;
    }

    while(last != *linked_list){
        printf("%c ", last->info);
        last = last->prev;
    }
    printf("%c\n", last->info);
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