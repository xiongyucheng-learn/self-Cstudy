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
    Trpoint *Root; /*该变量名改为Parent更合适*/
    Trpoint *Child;
    //bool BOOL; /*该变量多余*/
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
/* 这个函数设计得不好，需要频繁地动态分配和释放存储空间。*/
struct TreeARoot* SeekItemARoot( struct TreeARoot * ptree,const Item *item);
#else
/*请看我的设计，完全不需要使用动态存储分配。*/
int SeekItemARoot(const struct TreeARoot *p_data_in,
const Item *p_item, struct TreeARoot *p_data_out);
/*在p_data_in->Child指向的子树中寻找包含p_item指向的物品的节点。
找到则返回1，并把p_data_out->Child设置为指向该节点的指针，
把p_data_out->Root设置为指向该节点的父节点的指针。
找不到则返回0。
函数调用时，p_data_in->Root指向p_data_in->Child指向的节点的父节点。*/
#endif

#endif
