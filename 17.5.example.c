#include<stdio.h>
#include<stdlib.h>
struct List{
    int value;
    struct List *next;
};
struct List *ahead=NULL;
struct List * Create_point(int value){
    struct List *new_point;
    new_point=malloc(sizeof (struct List));
    new_point->value=value;
    return new_point;
}

struct List * Cat_point(struct List *point){
    point->next=ahead;
    ahead=point;
    return point;
}
int Found(int value ){
    int sum=0;
    struct List *temp=ahead;
    for(;temp->next;temp=temp->next,sum++){
        if(temp->value==value)
        return sum;
    }
}
struct List * Struct_Found(int value ,struct List *list){
    struct List *temp=list;
    for(;temp;temp=temp->next){
        if(temp->value==value)
        return temp;
    }
    return NULL;
}

struct List *Struct_Del(struct List *point,struct List * list){
    if(point==NULL)
    {
        printf("warn");
          return NULL;
    }
  
    struct List *head,*behind;
    head=list;
    behind=NULL;
    for(;head->next!=point->next&&head!=NULL;behind=head,head=head->next){
        ;
    }
    if(behind==NULL){
        list=head->next;
        free(head);
        head=NULL;
        return list;
    }else if(head==NULL){
        printf("NO FOUND\n");
        return NULL;
    }else{
        behind->next=head->next;
        free(head);
        return list;
    }
    /* data */
}

struct List *insert_point(struct List *new_point,struct List *point,struct List *list)
{
    struct List *head,*behind;
    head=list;
    behind=NULL;
    for(;head->next!=point->next&&head!=NULL;behind=head,head=head->next){
        ;
    }
    if(behind==NULL){
        return Cat_point(new_point);
    }else if(head==NULL){
        printf("NO FOUND\n");
        return list;
    }else{
        new_point->next=head;
        behind->next=new_point;
        return list;
    }
    /* data */
}

int main(void){
    struct List *list1;
    for(int i=0;i<10;i++){
        list1=Create_point(i);
        list1=Cat_point(list1);
    }
    
   struct List list2={.next=NULL,.value=100};
   list1=insert_point(&list2,Struct_Found(6,list1),list1);
   for(;list1;list1=list1->next){
    printf("%d  ",list1->value);
   }
    return 0;
}

