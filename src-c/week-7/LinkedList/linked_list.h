/*
CH-230-A
a7_p1.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

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