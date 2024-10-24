
#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*函数之间最好用一个空行分隔开，这样便于阅读。*/

void InitializeTree(Tree * ptree){
    ptree->Root=NULL;
    ptree->size=0;
}

bool is_TreeEmpty(const Tree * ptree){
#if 0
    return ptree->size; /*结果反了*/
#else
    return ptree->size==0;
#endif
}

bool is_TreeFull(const Tree * ptree){
    return ptree->size==TREE_MAX?1:0;
}

int TreeItemCount(const Tree * ptree){
    return ptree->size;
}

static bool SeekItem( Trpoint * ptree,const Item *item){
     bool BOOL=0;
#if 0
    /*if的条件永远为假，其真分支根本执行不到，因此这段代码多余*/
    if(BOOL){
        return 1;
    }else{
#endif
        if(ptree==NULL){
            return 0;
        }else{
            if(ptree->item->ID==item->ID){
                /*BOOL=1;*//*代码多余*/
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
#if 0
    }
#endif
}

/*请再仔细学习与自动局部变量的生存周期相关的知识*/

#if 0
/* 这个函数设计得不好，需要频繁地动态分配和释放存储空间。*/
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
#else
/*请看我的设计，完全不需要使用动态存储分配，而且代码更简洁。*/
int SeekItemARoot(const struct TreeARoot *p_data_in,
const Item *p_item, struct TreeARoot *p_data_out)
/*在p_data_in->Child指向的子树中寻找包含p_item指向的物品的节点。
找到则返回1，并把p_data_out->Child设置为指向该节点的指针，
把p_data_out->Root设置为指向该节点的父节点的指针。
找不到则返回0。
函数调用时，p_data_in->Root指向p_data_in->Child指向的节点的父节点。*/
{
    struct TreeARoot temp;
    if (p_data_in->Child->item==p_item)
    {
        *p_data_out=*p_data_in;
        return 1;
    }
    temp.Root=p_data_in->Child;
    if (p_data_in->Child->Left!=NULL)
    {
        temp.Child=p_data_in->Child->Left;
        if (SeekItemARoot(&temp, p_item, p_data_out))
            return 1;
    }
    if (p_data_in->Child->Right!=NULL)
    {
        temp.Child=p_data_in->Child->Right;
        if (SeekItemARoot(&temp, p_item, p_data_out))
            return 1;
    }
    return 0;
}
#endif

/*Tree_Add_point的返回值无意义，建议改为void*/
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
/*参数point的名字改为p_item更合理*/
{
    Trpoint *new_point;
    if(is_TreeFull(ptree)){
        fprintf(stderr,"Tree -s full\n");
        return 0;
    }
    if(SeekItem(ptree->Root,point)){
        fprintf(stderr,"This Item is already exist\n");
        /*英文语法错误，应改为This Item already exists*/
        return 0;
    }
    new_point=malloc(sizeof (struct tree_point));
    if(new_point==NULL){
            fprintf(stderr,"Fall to malloc\n"); /*Fall应改为Fail*/
            return 0;
        }
    new_point->item=point;
    new_point->Left=NULL;
    new_point->Right=NULL;
    if(/*is_TreeEmpty(ptree)==1*/!is_TreeEmpty(ptree)){
        Tree_Add_point(ptree->Root,new_point);
    }else{

            ptree->Root=new_point;
        }

    ptree->size++;
    return 1;
}

/*如果要使用bool类型，请使用true和false常量，不要把他们和1,0混合使用。
混合使用虽然没有问题，但不合理。否则就不要使用bool类型，因为C89中没有该类型*/

#if 0
bool  is_inTree(const Tree *ptree, const Item *point){
    struct TreeARoot temp;
    temp.BOOL=0;
    temp.Child=ptree->Root;
    temp.Root=NULL;
   if (SeekItemARoot(&temp,point)==NULL)return false;
   else return 1;
}
#else
/*使用新版的SeekItemARoot*/
bool  is_inTree(const Tree *ptree, const Item *point){
    struct TreeARoot temp_in, temp_out;
    temp_in.Child=ptree->Root;
    temp_in.Root=NULL;
   if (SeekItemARoot(&temp_in, point, &temp_out)) return true;
   else return false;
}
#endif

void TreeTraverse(const Trpoint * ptree,void(*pfun)(Item item)){
    if(ptree!=NULL){
        pfun(*(ptree->item));
        if (ptree->Left) {
            TreeTraverse(ptree->Left, pfun);
        }
        if (ptree->Right) {
            TreeTraverse(ptree->Right, pfun);
        }
        return; /*多余*/
    }else{
        fprintf(stderr,"ptree is emtpy");
        return; /*多余*/
    }

}

/*
TreeDelItem()在要删除节点的左右子节点均不为空情况下的
处理方法好像不能保持优先树的结构
*/

bool TreeDelItem(Tree * ptree,const Item * point){
#if 0
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
#else
    /*改为使用新版的SeekItemARoot。*/
    struct TreeARoot *temp;
    /*为了保持与下面的代码兼容，指针变量temp保留，但不再使用动态存储分配*/
    struct TreeARoot temp_in, temp_out;
    temp_in.Child=ptree->Root;
    temp_in.Root=NULL;
    if (!SeekItemARoot(&temp_in, point, &temp_out))
    {
        fprintf(stderr,"Not Found\n");
        return 0;
    }
    temp=&temp_out;
#endif

    if((temp->Child->Left==NULL)&&(temp->Child->Right==NULL))
    {
        /*左右均为空，叶子节点*/
        if(temp->Root!=NULL){
            /*不是根节点*/
            if(temp->Root->Right==temp->Child){
                /*是父节点的右分支*/
                temp->Root->Right=NULL;
                free(temp->Child); /*象这样所有分支都执行的语句可以提到if之外以简化代码*/
                //temp->Child=NULL; /*多余*////////////////Xiong.不多于
            }else{
                /*是父节点的左分支*/
                temp->Root->Left=NULL;
                free(temp->Child);
                //temp->Child=NULL; /*多余*///////////////Xiong.不多于
            }
        }else{
            /*是根节点*/
            free(temp->Child);
            ptree->Root=NULL;
        }
    }else if((temp->Child->Left!=NULL)&&(temp->Child->Right!=NULL)){
        /*左右均不为空*/
#if 0
        /*这个tRight只用了Root成员，完全没有存在的必要，
        也没必要使用动态存储分配*/
        Tree *tRight;
        tRight=malloc(sizeof(struct Tree));
#else
        Trpoint *p_temp_node; /*指向节点的临时指针变量*/
        /*以下代码中tRight->Root均改为p_temp_node*/
#endif
        /*tRight->Root*/p_temp_node=temp->Child->Right;
        if(temp->Root!=NULL){
            /*不是根节点*/
            if(temp->Root->Right==temp->Child){
                /*是父节点的右分支*/
                temp->Root->Right=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }else{
                /*是父节点的左分支*/
                temp->Root->Left=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }
            Tree_Add_point(temp->Root,/*tRight->Root*/p_temp_node);
        }else{
            /*是根节点*/
            Trpoint *tt;
            tt=temp->Child->Left;
            *(temp->Child)=*(temp->Child->Left);
            free(tt);
            Tree_Add_point(temp->Child,/*tRight->Root*/p_temp_node);
        }

        //free(tRight); /*tRight变量已经删除*/
    }else if(temp->Child->Right!=NULL){
        /*左为空，右不为空*/
        if(temp->Root!=NULL){
            /*不是根节点*/
            if(temp->Root->Right==temp->Child){
                /*是父节点的右分支*/
                temp->Root->Right=temp->Child->Right;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }else{
                /*是父节点的左分支*/
                temp->Root->Left=temp->Child->Right;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }
        }else {
            /*是根节点*/
#if 0
            /*没有必要使用动态存储分配*/
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Right;
            *(temp->Child)=*(temp->Child->Right);
            free(ttRight->Root);
            free(ttRight);
#else
            /*使用前面在左右均不为空并且要删除节点是根节点情况下的方法就可以了*/
            Trpoint *tt;
            tt=temp->Child->Right;
            *(temp->Child)=*(temp->Child->Right);
            free(tt);
#endif
        }

    }else /*if(temp->Child->Left!=NULL)*/{ /*if多余*/
        /*左不为空，右为空*/
        if(temp->Root!=NULL){
            /*不是根节点*/
            if(temp->Root->Right==temp->Child){
                /*是父节点的右分支*/
                temp->Root->Right=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }else{
                /*是父节点的左分支*/
                temp->Root->Left=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*多余*/
            }
        }else{
            /*是根节点*/
#if 0
            /*没有必要使用动态存储分配*/
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Left;
             *(temp->Child)=*(temp->Child->Left);
            free(ttRight->Root);
            free(ttRight);
#else
            /*使用前面在左右均不为空并且要删除节点是根节点情况下的方法就可以了*/
            Trpoint *tt;
            tt=temp->Child->Left;
            *(temp->Child)=*(temp->Child->Left);
            free(tt);
#endif
        }
    }
    (ptree->size)--;
    //free(temp); /*temp现在不再指向动态分配的存储空间*/
    return 1;
}

/*
动态存储分配的使用原则：
(1) 能不用就不用
(2) 尽量不要频繁使用
(3) 不要滥用
*/
