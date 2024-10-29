#ifndef __QUEUEADT__
#define __QUEUEADT__
#include<stdio.h>
#include<stdbool.h>

typedef struct Item{
    void *items;
    int size;
}Item;
typedef struct queue* Queue;
/*这个类型名改为PQueue更合适，因为它是指向队列的指针，而不是队列本身*/

void queue_rm(Queue queue);
Queue queue_Initailize(Queue queue);
int queue_Add(Queue queue,Item *item);

void queue_Traverser(Queue queue,void(*qfun)(Item *items),int mod);
/*我猜测：mod=0代表正向遍历，mod=1代表反向遍历，对吧？这里最好注释一下*/

#if 0
Queue queue_first(Queue queue);
#else
Item *queue_first(Queue queue);
#endif

#if 0
Queue queue_last(Queue queue);
#else
Item *queue_last(Queue queue);
#endif

bool is_queueEmpty(Queue queue);
#endif
