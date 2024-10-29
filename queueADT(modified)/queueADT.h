#ifndef __QUEUEADT__
#define __QUEUEADT__
#include<stdio.h>
#include<stdbool.h>

typedef struct Item{
    void *items;
    int size;
}Item;
typedef struct queue* Queue;
/*�����������ΪPQueue�����ʣ���Ϊ����ָ����е�ָ�룬�����Ƕ��б���*/

void queue_rm(Queue queue);
Queue queue_Initailize(Queue queue);
int queue_Add(Queue queue,Item *item);

void queue_Traverser(Queue queue,void(*qfun)(Item *items),int mod);
/*�Ҳ²⣺mod=0�������������mod=1������������԰ɣ��������ע��һ��*/

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
