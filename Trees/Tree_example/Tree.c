#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Tree.h"

typedef struct pair{
    Trnode * parent;
    Trnode * child;
}Pair;

void InitializeTree(Tree * ptree){
    ptree->Root=NULL;
    ptree->size=0;
}

bool TreeIsEmpty(const Tree * ptree){
    if(ptree==NULL){
        fprintf(stderr," This is not Tree ;%d;TreeIsEmpty\n",time(NULL));
        return 0;
    }
    return ptree->size;
}

bool TreeIsFull(const Tree * ptree){
    if(ptree==NULL){
        fprintf(stderr," This is not Tree ;%d;TreeIsFull\n",time(NULL));
        return 0;
    }
    return ptree->size>MAXITEMS?1:0;
}

int TreeItemCout(const Tree * ptree){
    if(ptree==NULL){
        fprintf(stderr," This is not Tree ;%d;TreeItemCout\n",time(NULL));
        return 0;
    }
    return ptree->size;
}

static Trnode * MakeNode(const Item *item){
    Trnode * new_node =malloc(sizeof (Trnode));
    if(new_node!=NULL){
        new_node->item=*item;
        new_node->Left=NULL;
        new_node->Right=NULL;
        
    }
    return new_node;
}

 static bool ToLeft(const Item *i1,const Item *i2){
    int comp1;
    if((comp1=strcmp(i1->petname,i2->petname))<0){
        return 1;
    }else if(comp1==0 &&strcmp(i1->petkind,i2->petkind)<0){
        return 1;
    }else{
        return 0;
    }
 }


 static bool ToRight(const Item *i1,const Item *i2){
    int comp1;
    if((comp1=strcmp(i1->petname,i2->petname))>0){
        return 1;
    }else if(comp1==0 &&strcmp(i1->petkind,i2->petkind)>0){
        return 1;
    }else{
        return 0;
    }
 }

static void ADDNode(Trnode * new_node,Trnode * Root){
    if(ToLeft(&new_node->item,&Root->item)){
        if(Root->Left==NULL){
            Root->Left=new_node;
        }else{
            ADDNode(new_node,Root->Left);
        }
    }else if(ToRight(&new_node->item,&Root->item)){
        if(Root->Right==NULL){
            Root->Right=new_node;
        }else{
            ADDNode(new_node,Root->Right);
        }
    }else{
        fprintf(stderr,"location error in ADDnode  ;%d;ADDnode \n",time(NULL));
        exit(1);
    }
}

static Pair SeekItem(const Item * pi,const Tree * ptree){
    Pair look;
    look.parent=NULL;
    look.child=ptree->Root;
    if(look.child ==NULL){
        return look;
    }

    while (look.child !=NULL){
        if(ToLeft(pi,&(look.child->item))){
            look.parent=look.child;
            look.child=look.child->Left;

        }else if (ToRight(pi,&(look.child->item))) {
            look.parent=look.child;
            look.child=look.child->Right;

        }else {
            break;
        }
    }
    return look;
}

static void DeleteNode(Trnode **ptr){
    Trnode * temp;
    if((*ptr)->Left==NULL){
        temp=*ptr;
        *ptr=(*ptr)->Right;
        free(temp);
    }else if((*ptr)->Right==NULL){
        temp=*ptr;
        *ptr=(*ptr)->Left;
        free(temp);
    }else{
        
        for(temp=(*ptr)->Left;temp->Right!=NULL;temp=temp->Right) continue;
        
        temp->Right=(*ptr)->Right;
        temp=*ptr;
        *ptr=(*ptr)->Left;
        free(temp);
    }
}

bool AddItem(const Item *pi,Tree * ptree){
    Trnode * new_point;
    if(TreeIsFull(ptree)){
        fprintf(stderr,"Tree is full ;%d;AddItem \n",time(NULL));
        return 0;
    }
    if(SeekItem(pi,ptree).child!=NULL){
        fprintf(stderr,"Already had this Item ;%d;AddItem \n",time(NULL));
        return 0;
    }

    new_point=MakeNode(pi);

    if(new_point==NULL){
         fprintf(stderr,"Can not Create node ;%d;AddItem \n",time(NULL));
        return 0;
    }

    ptree->size++;

    if(ptree->Root==NULL){
        ptree->Root=new_point;
    }else {
        ADDNode(new_point,ptree->Root);
    }
    return 1;
}

bool InTree(const Item * item,const Tree *ptree){
    return (SeekItem(item,ptree).child==NULL)?0:1;
}

bool DeleteItem(const Item * pi,Tree * ptree){
    Pair look;
    look = SeekItem(pi,ptree);
    if(look.child==NULL){
        return 0;
    }

    if(look.parent==NULL){
        DeleteNode(&ptree->Root);
    }else if(look.parent->Left==look.child){
        DeleteNode(&look.parent->Left);
    }else {
        DeleteNode(&look.parent->Right);
    }
    ptree->size--;
    return 1;
}