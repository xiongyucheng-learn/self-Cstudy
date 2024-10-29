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
    //printf("Error in pop");

    return 0;
    /*main函数结尾的return最好不要省略, main函数的返回值是有用的
    例如在windows操作系统中，main函数返回0xC0000005表示有内存异常错误*/
}
