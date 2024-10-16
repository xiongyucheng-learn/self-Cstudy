#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

struct Tree{
    struct Tree * Left;
    struct Tree * Right;
    int value;
};

struct TreeARoot{
    struct Tree * Root;
    struct Tree * Child;
};

struct Tree_Stack{
    struct Tree * point;
    struct Tree_Stack * next;
};
struct Tree_Stack * Tree_Stack_head=NULL;
struct Tree_Stack * Tree_Stack_push();
struct Tree_Stack * Tree_Stack_Create(struct Tree *);


struct Tree * Tree_Create(int);
struct Tree * Tree_point_add(struct Tree *,struct Tree *);
int Tree_Stack_pull(struct Tree *);

int main(void){
    ;
}

struct Tree_Stack * Tree_Stack_Create(struct Tree * point){
    struct Tree_Stack * temp=malloc(sizeof (struct Tree_Stack));
    temp->point=point;
    temp->next=NULL;
    return temp;
}

int Tree_Stack_pull(struct Tree * point){
    if(Tree_Stack_head==NULL){
        Tree_Stack_head=Tree_Stack_Create(point);
    }else{
        struct Tree_Stack *temp=Tree_Stack_Create(point);
        temp->next=Tree_Stack_head;
        Tree_Stack_head=temp;
    }
}

struct Tree_Stack *Tree_Stack_push(){
    struct Tree_Stack *temp=Tree_Stack_head;
    if(Tree_Stack_head->next){
        Tree_Stack_head=Tree_Stack_head->next;
        return temp;
    }else{
        Tree_Stack_head=NULL;
        return temp;
    }
}

struct Tree * Tree_Create(int value){
    struct Tree * temp=malloc(sizeof(struct Tree));
    temp->Left=NULL;
    temp->Right=NULL;
    temp->value=value;
}

struct Tree * Tree_point_add(struct Tree *Root,struct Tree * point){
    struct Tree * temp=Root;
    for(;;){
        if((temp->Left==NULL)&&(temp->Right==NULL))
        {
            
        }
    }
}