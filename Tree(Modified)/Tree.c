
#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*����֮�������һ�����зָ��������������Ķ���*/

void InitializeTree(Tree * ptree){
    ptree->Root=NULL;
    ptree->size=0;
}

bool is_TreeEmpty(const Tree * ptree){
#if 0
    return ptree->size; /*�������*/
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
    /*if��������ԶΪ�٣������֧����ִ�в����������δ������*/
    if(BOOL){
        return 1;
    }else{
#endif
        if(ptree==NULL){
            return 0;
        }else{
            if(ptree->item->ID==item->ID){
                /*BOOL=1;*//*�������*/
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

/*������ϸѧϰ���Զ��ֲ�����������������ص�֪ʶ*/

#if 0
/* ���������Ƶò��ã���ҪƵ���ض�̬������ͷŴ洢�ռ䡣*/
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
/*�뿴�ҵ���ƣ���ȫ����Ҫʹ�ö�̬�洢���䣬���Ҵ������ࡣ*/
int SeekItemARoot(const struct TreeARoot *p_data_in,
const Item *p_item, struct TreeARoot *p_data_out)
/*��p_data_in->Childָ���������Ѱ�Ұ���p_itemָ�����Ʒ�Ľڵ㡣
�ҵ��򷵻�1������p_data_out->Child����Ϊָ��ýڵ��ָ�룬
��p_data_out->Root����Ϊָ��ýڵ�ĸ��ڵ��ָ�롣
�Ҳ����򷵻�0��
��������ʱ��p_data_in->Rootָ��p_data_in->Childָ��Ľڵ�ĸ��ڵ㡣*/
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

/*Tree_Add_point�ķ���ֵ�����壬�����Ϊvoid*/
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
/*����point�����ָ�Ϊp_item������*/
{
    Trpoint *new_point;
    if(is_TreeFull(ptree)){
        fprintf(stderr,"Tree -s full\n");
        return 0;
    }
    if(SeekItem(ptree->Root,point)){
        fprintf(stderr,"This Item is already exist\n");
        /*Ӣ���﷨����Ӧ��ΪThis Item already exists*/
        return 0;
    }
    new_point=malloc(sizeof (struct tree_point));
    if(new_point==NULL){
            fprintf(stderr,"Fall to malloc\n"); /*FallӦ��ΪFail*/
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

/*���Ҫʹ��bool���ͣ���ʹ��true��false��������Ҫ�����Ǻ�1,0���ʹ�á�
���ʹ����Ȼû�����⣬������������Ͳ�Ҫʹ��bool���ͣ���ΪC89��û�и�����*/

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
/*ʹ���°��SeekItemARoot*/
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
        return; /*����*/
    }else{
        fprintf(stderr,"ptree is emtpy");
        return; /*����*/
    }

}

/*
TreeDelItem()��Ҫɾ���ڵ�������ӽڵ����Ϊ������µ�
�����������ܱ����������Ľṹ
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
    /*��Ϊʹ���°��SeekItemARoot��*/
    struct TreeARoot *temp;
    /*Ϊ�˱���������Ĵ�����ݣ�ָ�����temp������������ʹ�ö�̬�洢����*/
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
        /*���Ҿ�Ϊ�գ�Ҷ�ӽڵ�*/
        if(temp->Root!=NULL){
            /*���Ǹ��ڵ�*/
            if(temp->Root->Right==temp->Child){
                /*�Ǹ��ڵ���ҷ�֧*/
                temp->Root->Right=NULL;
                free(temp->Child); /*���������з�֧��ִ�е��������ᵽif֮���Լ򻯴���*/
                //temp->Child=NULL; /*����*////////////////Xiong.������
            }else{
                /*�Ǹ��ڵ�����֧*/
                temp->Root->Left=NULL;
                free(temp->Child);
                //temp->Child=NULL; /*����*///////////////Xiong.������
            }
        }else{
            /*�Ǹ��ڵ�*/
            free(temp->Child);
            ptree->Root=NULL;
        }
    }else if((temp->Child->Left!=NULL)&&(temp->Child->Right!=NULL)){
        /*���Ҿ���Ϊ��*/
#if 0
        /*���tRightֻ����Root��Ա����ȫû�д��ڵı�Ҫ��
        Ҳû��Ҫʹ�ö�̬�洢����*/
        Tree *tRight;
        tRight=malloc(sizeof(struct Tree));
#else
        Trpoint *p_temp_node; /*ָ��ڵ����ʱָ�����*/
        /*���´�����tRight->Root����Ϊp_temp_node*/
#endif
        /*tRight->Root*/p_temp_node=temp->Child->Right;
        if(temp->Root!=NULL){
            /*���Ǹ��ڵ�*/
            if(temp->Root->Right==temp->Child){
                /*�Ǹ��ڵ���ҷ�֧*/
                temp->Root->Right=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }else{
                /*�Ǹ��ڵ�����֧*/
                temp->Root->Left=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }
            Tree_Add_point(temp->Root,/*tRight->Root*/p_temp_node);
        }else{
            /*�Ǹ��ڵ�*/
            Trpoint *tt;
            tt=temp->Child->Left;
            *(temp->Child)=*(temp->Child->Left);
            free(tt);
            Tree_Add_point(temp->Child,/*tRight->Root*/p_temp_node);
        }

        //free(tRight); /*tRight�����Ѿ�ɾ��*/
    }else if(temp->Child->Right!=NULL){
        /*��Ϊ�գ��Ҳ�Ϊ��*/
        if(temp->Root!=NULL){
            /*���Ǹ��ڵ�*/
            if(temp->Root->Right==temp->Child){
                /*�Ǹ��ڵ���ҷ�֧*/
                temp->Root->Right=temp->Child->Right;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }else{
                /*�Ǹ��ڵ�����֧*/
                temp->Root->Left=temp->Child->Right;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }
        }else {
            /*�Ǹ��ڵ�*/
#if 0
            /*û�б�Ҫʹ�ö�̬�洢����*/
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Right;
            *(temp->Child)=*(temp->Child->Right);
            free(ttRight->Root);
            free(ttRight);
#else
            /*ʹ��ǰ�������Ҿ���Ϊ�ղ���Ҫɾ���ڵ��Ǹ��ڵ�����µķ����Ϳ�����*/
            Trpoint *tt;
            tt=temp->Child->Right;
            *(temp->Child)=*(temp->Child->Right);
            free(tt);
#endif
        }

    }else /*if(temp->Child->Left!=NULL)*/{ /*if����*/
        /*��Ϊ�գ���Ϊ��*/
        if(temp->Root!=NULL){
            /*���Ǹ��ڵ�*/
            if(temp->Root->Right==temp->Child){
                /*�Ǹ��ڵ���ҷ�֧*/
                temp->Root->Right=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }else{
                /*�Ǹ��ڵ�����֧*/
                temp->Root->Left=temp->Child->Left;
                free(temp->Child);
                //temp->Child=NULL; /*����*/
            }
        }else{
            /*�Ǹ��ڵ�*/
#if 0
            /*û�б�Ҫʹ�ö�̬�洢����*/
            Tree *ttRight;
            ttRight=malloc(sizeof(struct Tree));
            ttRight->Root=temp->Child->Left;
             *(temp->Child)=*(temp->Child->Left);
            free(ttRight->Root);
            free(ttRight);
#else
            /*ʹ��ǰ�������Ҿ���Ϊ�ղ���Ҫɾ���ڵ��Ǹ��ڵ�����µķ����Ϳ�����*/
            Trpoint *tt;
            tt=temp->Child->Left;
            *(temp->Child)=*(temp->Child->Left);
            free(tt);
#endif
        }
    }
    (ptree->size)--;
    //free(temp); /*temp���ڲ���ָ��̬����Ĵ洢�ռ�*/
    return 1;
}

/*
��̬�洢�����ʹ��ԭ��
(1) �ܲ��þͲ���
(2) ������ҪƵ��ʹ��
(3) ��Ҫ����
*/
