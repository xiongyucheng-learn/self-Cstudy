#ifndef _TREE_
#define _TREE_
#include<stdbool.h>
#define CHAR_LEN 10
#define TREE_MAX 100000000
#define DEBUG 1
typedef struct item{
    char name[CHAR_LEN];
    int ID;
    int score;
    char class_name[CHAR_LEN];
}Item;

typedef struct tree_point{
    struct tree_point * Left;
    struct tree_point * Right;
    Item *item;
}Trpoint;

typedef struct Tree {
    Trpoint *Root;
    int size;
}Tree;

struct TreeARoot{
    Trpoint *Root; /*�ñ�������ΪParent������*/
    Trpoint *Child;
    //bool BOOL; /*�ñ�������*/
};

void InitializeTree(Tree * ptree);

bool is_TreeEmpty(const Tree * ptree);

bool is_TreeFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool TreeADDItem(Tree * ptree,const Item *point );

bool  is_inTree(const Tree *ptree, const Item *point);

bool TreeDelItem(Tree * ptree,const Item * point);

void TreeTraverse(const Trpoint * ptree,void(*pfun)(Item item));

#if 0
/* ���������Ƶò��ã���ҪƵ���ض�̬������ͷŴ洢�ռ䡣*/
struct TreeARoot* SeekItemARoot( struct TreeARoot * ptree,const Item *item);
#else
/*�뿴�ҵ���ƣ���ȫ����Ҫʹ�ö�̬�洢���䡣*/
int SeekItemARoot(const struct TreeARoot *p_data_in,
const Item *p_item, struct TreeARoot *p_data_out);
/*��p_data_in->Childָ���������Ѱ�Ұ���p_itemָ�����Ʒ�Ľڵ㡣
�ҵ��򷵻�1������p_data_out->Child����Ϊָ��ýڵ��ָ�룬
��p_data_out->Root����Ϊָ��ýڵ�ĸ��ڵ��ָ�롣
�Ҳ����򷵻�0��
��������ʱ��p_data_in->Rootָ��p_data_in->Childָ��Ľڵ�ĸ��ڵ㡣*/
#endif

#endif
