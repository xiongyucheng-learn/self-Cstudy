#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Tree.h"
int main(void){
    //freopen("error.log","w",stderr);
    Tree tree1;
    InitializeTree(&tree1);
    Item *items;
    items=malloc((sizeof (Item))*10);
    //for(int i=0;i<10;i++){
        memcpy(items[0].petname,(char*)("A"),2);
         memcpy(items[1].petname,(char*)("B"),2);
          memcpy(items[2].petname,(char*)("C"),2);
           memcpy(items[3].petname,(char*)("D"),2);
            memcpy(items[4].petname,(char*)("E"),2);
             memcpy(items[5].petname,(char*)("F"),2);
              memcpy(items[6].petname,(char*)("B"),2);
    //}
    for(int i=0;i<7;i++){
        AddItem(&items[i],&tree1);
    }
   
    printf("ww");
}