#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"


void InitializeTree(Tree * ptree){
    ptree->Root=NULL;
    ptree->size=0;
}

bool is_TreeEmpty(const Tree * ptree){
    return ptree->size;
}

bool is_TreeFull(const Tree * ptree){
    return ptree->size==TREE_MAX?1:0;
}

int TreeItemCount(const Tree * ptree){
    return ptree->size;
}

static bool SeekItem( Trpoint * ptree,const Item *item){
     bool BOOL=0;
    if(BOOL){
        return 1;
    }else{
        if(ptree==NULL){
            return 0;
        }else{
            if(ptree->item->ID==item->ID){
                BOOL=1;
                return 1;
            }else{
                if(ptree->Left){
                    if(SeekItem(ptree->Left,item))BOOL=1;
                }
                if(ptree->Right){
                    if(SeekItem(ptree->Right,item))BOOL=1;
                }
                return BOOL;
            } 
        }
    }
}

struct TreeARoot* SeekItemARoot( struct TreeARoot * ptree,const Item *item){
    struct TreeARoot * temp=NULL;
    if(ptree->BOOL){
        return ptree;
    }
    if(ptree->Child->item==item){
        temp=malloc(sizeof (struct TreeARoot));
        temp->Child=ptree->Child;
        temp->Root=ptree->Root;
        temp->BOOL=1;
        //ptree->BOOL=1;
        return temp;
    }else{
        if(ptree->Child->Left!=NULL){
            struct TreeARoot *ttemp=malloc(sizeof(struct TreeARoot));
            ttemp->BOOL=0;
            ttemp->Child=ptree->Child->Left;
            ttemp->Root=ptree->Child;
            if(temp=SeekItemARoot(ttemp,item)){
                free(ttemp);
                if(temp!=NULL)return temp;
            }else{
                free(ttemp);
            }
        }
        if(ptree->Child->Right!=NULL){
            struct TreeARoot *ttemp=malloc(sizeof(struct TreeARoot));
            ttemp->BOOL=0;
            ttemp->Child=ptree->Child->Right;
            ttemp->Root=ptree->Child;
            if(temp=SeekItemARoot(ttemp,item)){
                free(ttemp);
                if(temp!=NULL)return temp;
            }else{
                free(ttemp);
            }
        }
        free(temp);
        return NULL;
    }

}

static bool Tree_Add_point(Trpoint * ptree,Trpoint *point){
    if(ptree->item->ID>point->item->ID){
        if(ptree->Left==NULL){
            ptree->Left=point;
            return 1;
        }else{
            Tree_Add_point(ptree->Left,point);
        }
    }else{
        if(ptree->Right==NULL){
            ptree->Right=point;
            return 1;
        }else{
            Tree_Add_point(ptree->Right,point);
        }
    }
}
bool TreeADDItem( Tree * ptree,const Item *point )
{
    Trpoint *new_point;
    if(is_TreeFull(ptree)){
        fprintf(stderr,"Tree -s full\n");
        return 0;
    }
    if(SeekItem(ptree->Root,point)){
        fprintf(stderr,"This Item is already exist\n");
        return 0;
    }
    new_point=malloc(sizeof (struct tree_point));
    if(new_point==NULL){
            fprintf(stderr,"Fall to malloc\n");
            return 0;
        }
    new_point->item=point;
    new_point->Left=NULL;
    new_point->Right=NULL;
    if(is_TreeEmpty(ptree)==1){
        Tree_Add_point(ptree->Root,new_point);
    }else{
           
            ptree->Root=new_point;
        }
    
    ptree->size++;
    return 1;
}
bool  is_inTree(const Tree *ptree, const Item *point){
    struct TreeARoot temp;
    temp.BOOL=0;
    temp.Child=ptree->Root;
    temp.Root=NULL;
   if (SeekItemARoot(&temp,point)==NULL)return false;
   else return 1;
}  
void TreeTraverse(const Trpoint * ptree,void(*pfun)(Item item)){
    if(ptree!=NULL){
        pfun(*(ptree->item));
        if (ptree->Left) {
            TreeTraverse(ptree->Left, pfun);
        }
        if (ptree->Right) {
            TreeTraverse(ptree->Right, pfun);
        }
        return;
    }else{
        fprintf(stderr,"ptree is emtpy");
        return;
    }
   
}
bool TreeDelItem(Tree * ptree,const Item * point){
    struct TreeARoot *temp,*temp1;
    temp1=malloc(sizeof  (struct TreeARoot));
    temp1->BOOL=0;
    temp1->Child=ptree->Root;
    temp1->Root=NULL;
    temp=SeekItemARoot(temp1,point);
    free(temp1);
    if(temp==NULL){
        fprintf(stderr,"NO FOUND\n");
        return 0;
    }

    if((temp->Child->Left==NULL)&&(temp->Child->Right==NULL))
    {      
        if(temp->Root!=NULL){
            if(temp->Root->Right==temp->Child){
                temp->Root->Right=NULL;
                free(temp->Child);
                temp->Child=NULL;
            }else{
                temp->Root->Left=NULL;
                free(temp->Child);
                temp->Child=NULL;
            }
        }else{
            free(temp->Child);
            ptree->Root=NULL;
        }
    }else if((temp->Child->Left!=NULL)&&(temp->Child->Right!=NULL)){
        Tree *tRight;
        tRight=malloc(sizeof(struct Tree));
        tRight->Root=temp->Child->Right;
        if(temp->Root!=NULL){
            if(temp->Root->Right==temp->Child){
                temp->Root->Right=temp->Child->Left;
                free(temp->Child);
                temp->Child=NULL;
            }else{
                temp->Root->Left=temp->Child->Left;
                free(temp->Child);
                temp->Child=NULL;
            }
            Tree_Add_point(temp->Root,tRight->Root);
        }else{
           Trpoint *tt;
           tt=temp->Child->Left;
            *(temp->Child)=*(temp->Child->Left);
            free(tt);
            Tree_Add_point(temp->Child,tRight->Root);
        }

            free(tRight);
    }else if(temp->Child->Right!=NULL){
        if(temp->Root!=NULL){
                if(temp->Root->Right==temp->Child){
                temp->Root->Right=temp->Child->Right;
                free(temp->Child);
                temp->Child=NULL;
            }else{
                temp->Root->Left=temp->Child->Right;
                free(temp->Child);
                temp->Child=NULL;
            }
        }else {
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Right;
            *(temp->Child)=*(temp->Child->Right);
            free(ttRight->Root);
            free(ttRight);
        }
    
    }else if(temp->Child->Left!=NULL){
        if(temp->Root!=NULL){
         if(temp->Root->Right==temp->Child){
            temp->Root->Right=temp->Child->Left;
            free(temp->Child);
            temp->Child=NULL;
            }else{
            temp->Root->Left=temp->Child->Left;
            free(temp->Child);
            temp->Child=NULL;
            }
        }else{
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Left;
             *(temp->Child)=*(temp->Child->Left);
            free(ttRight->Root);
            free(ttRight);
        }
    }
    (ptree->size)--;
    free(temp);
    return 1;
}
