#include"queueADT.h"
#include <stdio.h>
#include<stdlib.h>
void qfun(Item *item){
    printf("%s  %d",item->items,item->size);
}
int main(void){
    Queue queue_temp=NULL;
    queue_temp=queue_Initailize(queue_temp);
    char a[]="hello world";
    Item item={.items=a,.size=sizeof a};
    queue_Add(queue_temp,&item);
     queue_Add(queue_temp,&item);
      queue_Add(queue_temp,&item);
    
    queue_Traverser(queue_temp,qfun,1);
    queue_rm(queue_temp);
    printf("Error in pop");
}