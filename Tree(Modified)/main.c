#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#define MAX_NUM 10000
void funprintf(Item item){
        printf("item: %d \n",item.ID);
    }
int main(void){
    freopen("temp.log","w",stderr);
    
    // Tree *tree;
    // tree=malloc(sizeof(struct Tree));
    // InitializeTree(tree);
    // Item *items=NULL;
    // items=malloc(sizeof(struct item)*MAX_NUM);
    // for(long i=MAX_NUM/2;i<MAX_NUM;i++){
    //     items[i].ID=i+2;
    //     TreeADDItem(tree,&items[i]);
    // }
    // for(long i=0;i<MAX_NUM/2;i++){
    //     items[i].ID=i+2;
    //     TreeADDItem(tree,&items[i]);
    // }
    // system("pause");
    // freopen("out.txt","w",stdout);
    // TreeTraverse(tree->Root,funprintf);
    // freopen("CON","w",stdout);
    // for(long i=0;i<MAX_NUM;i++)
    //     if(tree->Root)
    //         TreeDelItem(tree,tree->Root->item);
    // system("pause");
    // _sleep(10);

    Tree **tree;
    tree=(struct Tree **)malloc((sizeof(struct Tree*))*25);
    for(int i=0;i<25;i++){
        tree[i]=malloc(sizeof(struct Tree));
    }
    system("pause");
    for(int i=0;i<25;i++)
        InitializeTree(tree[i]);
    Item *items=NULL;
    items=malloc(sizeof(struct item)*MAX_NUM);
    for(int j=0;j<25;j++){

        for(long i=MAX_NUM/2;i<MAX_NUM;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
    }
    for(long i=0;i<MAX_NUM/2;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
     }

    
    }
    
    system("pause");
    for(int j=0;j<25;j++){
     for(int i=0;i<MAX_NUM;i++){
        TreeDelItem(tree[j],&items[i]);
        // struct  TreeARoot *temp,*temp1;
        
        // temp=malloc(sizeof  (struct TreeARoot));
        // temp->BOOL=0;
        // temp->Child=tree[j]->Root;
        // temp->Root=NULL;
        // temp1=SeekItemARoot(temp,&items[i]);
        // temp1->BOOL=0;
        
       if(i%1000==0){
        //printf("%d %d \n",j,i);
        // printf("%d",temp1->Child->item->ID);
       } 
    //    free(temp);
    //    free(temp1);
        //system("pause");
     }
    }
    system("pause");
    for(int i=0;i<25;i++)
        InitializeTree(tree[i]);
    for(int j=0;j<25;j++){

        for(long i=MAX_NUM/2;i<MAX_NUM;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
    }
    for(long i=0;i<MAX_NUM/2;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
     }

    
    }
    
    system("pause");
    for(int j=0;j<25;j++){
     for(int i=0;i<MAX_NUM;i++){
        TreeDelItem(tree[j],&items[i]);
        // struct  TreeARoot *temp,*temp1;
        
        // temp=malloc(sizeof  (struct TreeARoot));
        // temp->BOOL=0;
        // temp->Child=tree[j]->Root;
        // temp->Root=NULL;
        // temp1=SeekItemARoot(temp,&items[i]);
        // temp1->BOOL=0;
        
       if(i%1000==0){
        //printf("%d %d \n",j,i);
        // printf("%d",temp1->Child->item->ID);
       } 
    //    free(temp);
    //    free(temp1);
        //system("pause");
     }
    }
    system("pause");
    for(int i=0;i<25;i++)
        InitializeTree(tree[i]);
    for(int j=0;j<25;j++){

        for(long i=MAX_NUM/2;i<MAX_NUM;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
    }
    for(long i=0;i<MAX_NUM/2;i++){
        items[i].ID=i+2;
        TreeADDItem(tree[j],&items[i]);
     }

    
    }
    
    system("pause");
    for(int j=0;j<25;j++){
     for(int i=0;i<MAX_NUM;i++){
        TreeDelItem(tree[j],&items[i]);
        // struct  TreeARoot *temp,*temp1;
        
        // temp=malloc(sizeof  (struct TreeARoot));
        // temp->BOOL=0;
        // temp->Child=tree[j]->Root;
        // temp->Root=NULL;
        // temp1=SeekItemARoot(temp,&items[i]);
        // temp1->BOOL=0;
        
       if(i%1000==0){
        //printf("%d %d \n",j,i);
        // printf("%d",temp1->Child->item->ID);
       } 
    //    free(temp);
    //    free(temp1);
        //system("pause");
     }
    }
    system("pause");





    // Tree *tree;
    // tree=malloc(sizeof(struct Tree));
    // InitializeTree(tree);
    // Item items[6]={[0].ID=5,[1].ID=6,[2].ID=7,[3].ID=4,[4].ID=2,[5].ID=8};
    // for(int i=0;i<6;i++){
    //     TreeADDItem(tree,&items[i]);
    // }
    // system("pause");
    // TreeTraverse(tree->Root,funprintf);
    // printf("????????????????????/\n");
    // TreeDelItem(tree,&items[0]);
    // TreeTraverse(tree->Root,funprintf);
    //  printf("??????????????????/\n");
    // TreeDelItem(tree,&items[5]);
    // TreeTraverse(tree->Root,funprintf);
    //  printf("?????????????????/\n");
    // TreeDelItem(tree,&items[3]);
    // TreeTraverse(tree->Root,funprintf);
    // printf("??????????????????/\n");
    // TreeDelItem(tree,&items[2]);
    // TreeTraverse(tree->Root,funprintf);
    //  printf("?????????????????/\n");
    // TreeDelItem(tree,&items[1]);
    // TreeTraverse(tree->Root,funprintf);
    // system("pause");
    // TreeDelItem(tree,&items[4]);
    // TreeTraverse(tree->Root,funprintf);
    //  system("pause");
}
// // int main() {
// //   float a, b;
// //   for (int i = 1; i <= 100; i++){
//          b += (2 * (i % 2) - 1) * (float)1 / (2 * i - 1);
//  }
// //   printf("%f", b);
// // }