#include"queueADT.h"
#include<stdio.h>
#include<stdlib.h>
//#include<stdnoreturn.h> 有问题，无法使用


typedef struct queue_point{
    Item *items;
    struct queue_point * head;
    struct queue_point * next;
}Queue_point;

struct queue{
    Queue_point * queue;
    Queue_point * queue_last;
    int size;
};

static Queue_point * queue_Create(Item *item){
    Queue_point *temp=malloc(sizeof (Queue_point));
    if(temp==NULL){
        fprintf(stderr,"Error in queue_Create;%d \n");
    }
    temp->items=item;
    temp->head=NULL;
    temp->next=NULL;
    return temp;
}

Queue queue_Initailize(Queue queue){
    queue=malloc(sizeof (Queue));
    queue->queue=NULL;
    queue->queue_last=NULL;
    queue->size=0;
    return queue;
}

 int queue_Add(Queue queue_Dst,Item *item){
    if(is_queueEmpty(queue_Dst)){
        Queue_point *point=queue_Create(item);
        queue_Dst->queue=point;
        queue_Dst->queue_last=point;
        queue_Dst->size++;
    }else{
        Queue_point *point=queue_Create(item);
        point->next=queue_Dst->queue;
        queue_Dst->queue->head=point;
        queue_Dst->queue=point;
        queue_Dst->size++;
    }
}

void queue_Traverser(Queue queue,void(*qfun)(Item *items),int mod){
    Queue temp=malloc(sizeof(Queue));
    //*temp=*queue;会导致queue中的空指针不再指向NULL
    //*(queue->queue)=*(temp->queue);会报错
    if(mod==0){
        temp->queue=queue->queue;
        int i=0;
        while(temp->queue!=NULL){
            qfun(temp->queue->items);
            temp->queue=temp->queue->next;
            printf("##%d\n",i++);
        }
        free(temp);
    }else if(mod==1){
        temp->queue=queue->queue_last;
        int i=0;
        while(temp->queue!=NULL){
            qfun(temp->queue->items);
            temp->queue=temp->queue->head;
            printf("##%d\n",i++);
        }
        free(temp);
    }else{
        free(temp);
        fprintf(stderr,"Error mod \n");
    }
     
}

Queue queue_first(Queue queue){
    Queue temp=malloc(sizeof (Queue));
    temp->queue=queue->queue;
    temp->queue_last=NULL;
    temp->size=0;
    return temp; 
}

Queue queue_last(Queue queue){
    Queue temp=malloc(sizeof (Queue));
    temp->queue_last=queue->queue_last;
    temp->queue=NULL;
    temp->size=0;
    return temp; 
}

bool is_queueEmpty(Queue queue){
    return !queue->size;
}

void queue_rm(Queue queue){
     while (queue->queue!=NULL)
     {
        printf("q%s \n",queue_first(queue)->queue->items->items);
        printf("p%s \n",queue_last(queue)->queue_last->items->items);
        Queue_point *temp=queue->queue;
        queue->queue=queue->queue->next;
        free(temp);
        queue->size--;
        /* code */
     }
      queue->queue_last=NULL;   
}