/**
 * @file queue.c
 */

/*
CH-230-A
a8_p3.c
Santiago Dominguez
25 October 2022
Implements queue structs functionality. Pre-written code that I fixed.
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    Node *newEl = (Node*) malloc(sizeof(Node));
    if(newEl == NULL){
        printf("Memory allocation error!");
        return -1;
    }
    newEl->item = item;
    newEl->next = NULL;
    
    if(queue_is_empty(pq)){
        pq->front = newEl;
        pq->rear = newEl;
    } else {
        pq->rear->next = newEl;
        pq->rear = newEl;
    }

    pq->items++;
    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
    if(queue_is_empty(pq)){
        return -1;
    }
    *pitem = pq->front->item;
    Node* temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    pq->items--;
    if(queue_is_empty(pq)){
        pq->front = NULL;
        pq-> rear = NULL;
    }
    
    return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
    pq->front = NULL;
    pq-> rear = NULL;
}

void printq(Queue *pq){
    printf("content of the queue: ");
    Node* currItem = pq->front;
    while(currItem != NULL){
        printf("%d ", currItem->item);
        currItem = currItem->next;
    }
    printf("\n");
}