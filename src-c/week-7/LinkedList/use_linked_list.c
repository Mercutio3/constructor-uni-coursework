/*
CH-230-A
a7_p1.c
Santiago Dominguez
18 October 2022
22 October 2022
Runs linked list implementation, uses switch statement to execute features
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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