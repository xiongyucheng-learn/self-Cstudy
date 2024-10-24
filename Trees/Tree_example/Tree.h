#ifndef __TREE__
#define __TREE__

#define SLEN 20
#include <stdbool.h>
typedef struct item{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEMS 10

typedef struct trnode{
    Item item;
    struct trnode * Left;
    struct trnode * Right;
} Trnode;

typedef struct tree{
    Trnode * Root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCout(const Tree * ptree);

bool AddItem(const Item * pi,Tree * ptree);

bool InTree(const Item * pi,const Tree * ptree);

bool DeleteItem(const Item * pi,Tree * ptree);

void Traverse(const Tree * ptree,void (*pfun)(Item item));

#endif