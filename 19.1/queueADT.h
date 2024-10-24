#ifndef __QUEUEADT__
#define __QUEUEADT__
#include<stdio.h>
#include<stdbool.h>

typedef struct Item{
    void *items;
    int size;
}Item;
typedef struct queue* Queue;
void queue_rm(Queue queue);
Queue queue_Initailize(Queue queue);
int queue_Add(Queue queue,Item *item);
void queue_Traverser(Queue queue,void(*qfun)(Item *items),int mod); 
Queue queue_first(Queue queue);
Queue queue_last(Queue queue);
bool is_queueEmpty(Queue queue);
#endif