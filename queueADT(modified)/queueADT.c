#include"queueADT.h"
#include<stdio.h>
#include<stdlib.h>
//#include<stdnoreturn.h> 有问题，无法使用


typedef struct queue_point{
    Item *items; /*items没有必要定义为指针变量*/
    struct queue_point * head; /*这个一般叫prev*/
    struct queue_point * next;
}Queue_point;

struct queue{
    Queue_point * queue; /*这个一般叫head*/
    Queue_point * queue_last; /*这个一般叫tail*/
    int size;
};

static Queue_point * queue_Create(Item *item){
    Queue_point *temp=malloc(sizeof (Queue_point));
    if(temp==NULL){
        fprintf(stderr,"Error in queue_Create;%d \n");
        /*%d没有对应的参数*/
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

/*queue_Add()没有返回值*/
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

void queue_Traverser(Queue queue,void(*qfun)(Item *items),int mod)
/*我猜测：mod=0代表正向遍历，mod=1代表反向遍历，对吧？这里最好注释一下*/
{
#if 1
    Queue temp=malloc(sizeof(Queue));
    *temp=*queue;//会导致queue中的空指针不再指向NULL
    *(queue->queue)=*(temp->queue);//会报错
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
#else
    /*和以前一样，你又滥用动态存储分配了
    遍历双向链表完全没有必要使用动态存储分配
    请看我写的代码*/
    Queue_point *p_node;
    int i=0;
    if(mod==0){
        p_node=queue->queue;
        while(p_node!=NULL){
            qfun(p_node->items);
            p_node=p_node->next;
            printf("##%d\n",i++);
        }
    }else if(mod==1){
        p_node=queue->queue_last;
        while(p_node!=NULL){
            qfun(p_node->items);
            p_node=p_node->head;
            printf("##%d\n",i++);
        }
    }else{
        fprintf(stderr,"Error mod \n");
    }
#endif
}

#if 0
Queue queue_first(Queue queue){
    Queue temp=malloc(sizeof (Queue));
    temp->queue=queue->queue;
    temp->queue_last=NULL;
    temp->size=0;
    return temp;
}
#else
    /*新的queue_first()，不使用动态内存分配*/
Item *queue_first(Queue queue){
    return queue->queue->items;
}
#endif

#if 0
Queue queue_last(Queue queue){
    Queue temp=malloc(sizeof (Queue));
    temp->queue_last=queue->queue_last;
    temp->queue=NULL;
    temp->size=0;
    return temp;
}
#else
    /*queue_last()，不使用动态内存分配*/
Item *queue_last(Queue queue){
    return queue->queue_last->items;
}
#endif

bool is_queueEmpty(Queue queue){
    return !queue->size;
}

void queue_rm(Queue queue){
     while (queue->queue!=NULL)
     {
#if 0
        printf("q%s \n",queue_first(queue)->queue->items->items);
        printf("p%s \n",queue_last(queue)->queue_last->items->items);
        /*queue_first()函数中动态分配的内存没有释放*/
        /*queue_last()函数中动态分配的内存没有释放*/
#else
        /*使用新的queue_first()和queue_last()*/
        printf("q%s \n", (const char *)queue_first(queue)->items);
        printf("p%s \n", (const char *)queue_last(queue)->items);
#endif
        Queue_point *temp=queue->queue;
        queue->queue=queue->queue->next;
        free(temp);
        queue->size--;
        /* code */
     }
      queue->queue_last=NULL;
}
