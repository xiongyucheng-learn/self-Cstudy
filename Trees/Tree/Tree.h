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
    Trpoint *Root;
    Trpoint *Child;
    bool BOOL;
};

void InitializeTree(Tree * ptree);

bool is_TreeEmpty(const Tree * ptree);

bool is_TreeFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool TreeADDItem(Tree * ptree,const Item *point );  

bool  is_inTree(const Tree *ptree, const Item *point);

bool TreeDelItem(Tree * ptree,const Item * point);

void TreeTraverse(const Trpoint * ptree,void(*pfun)(Item item));

struct TreeARoot* SeekItemARoot( struct TreeARoot * ptree,const Item *item);

#endif
