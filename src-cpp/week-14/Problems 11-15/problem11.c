#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    char str[20];
    struct node* next;
};

struct node* insertBegin(struct node *head, char str[]){
    struct node* output = malloc(sizeof(struct node));
    assert(output);
    strcpy(output->str, str);
    output->next = head;
    return output;
}

void printList(struct node *head){
    struct node* ptr = head;
    while(ptr!=NULL){
        printf("%s ", ptr->str);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    struct node* linkList = NULL;
    char thing[] = "hello";
    linkList = insertBegin(linkList, thing);
    printList(linkList);

    return 0;
}