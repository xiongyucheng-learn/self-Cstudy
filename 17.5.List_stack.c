#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
typedef struct List
{
 int value;
  struct List *next;   
}List;
    List *ahead=NULL;
    List *stack_head=NULL;

struct  List * List_Create(int value){
    struct List* temp;
    temp=malloc(sizeof(struct List));
    temp->value=value;
    return temp;
}

struct List * List_pop(struct List * point){
    point->next=ahead;
    ahead=point;
    stack_head=point;
    return point;
}
struct List * List_pull()
{
    struct List *temp;
    temp=ahead;
    if(ahead)
    {  
        
        ahead=ahead->next;
        //free(temp);
        return ahead;
    }else{
        printf("WARN");
        return NULL;
    }
}
struct List * List_recycle(struct List * list)
{
    struct List * temp=stack_head;
    for(;temp!=list&&temp!=NULL;stack_head=stack_head->next,free(temp),temp=stack_head);
    /* data */
}


int main(void){
    time_t time1;
    time(&time1);

    for(int j=0;j<100;j++){
        for(int i=0;i<10000000;i++)List_pop(List_Create(i));
        for(int i=0;i<10000000;i++)List_pull();
        List_recycle(ahead);
    }
    time_t time2;
    time(&time2);
    printf("%d",(time2-time1));
    system("pause");
}
