#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEFT 0
#define RIGHT 1
#define DEBUG 1
struct Tree{
    struct Tree *Left;
    struct Tree *right;
    int value;
};
struct TreeARoot{
    struct Tree * Child;
    struct Tree * Root;
};
struct Tree_Stack{
    struct Tree_Stack * next;
    struct Tree * point;
};
///////////////////////////////////////
struct Tree *Tree_Create(int);
int Tree_list(struct  Tree *,struct Tree *);
struct Tree *Tree_Find(struct Tree*,int);
struct TreeARoot * Tree_Find_HEAD(struct Tree *,int);
struct TreeARoot * Tree_Find_HEAD_Min(struct Tree *);
int Tree_Del(int,struct Tree *);
////////////////////////////////////////

struct Tree_Stack *Tree_Stack_head=NULL;
struct Tree_Stack *Tree_Stack_pull(struct Tree * point);
struct Tree_Stack *Tree_Stack_push(); 
int Tree_Stack_rm();
///////////////////////////////////////
int main(void){

    int a[]={6,4,7,3,5,10,8,9,11};
    struct Tree * Root=Tree_Create(a[0]);
    for(int i=1;i<(sizeof a)/(sizeof a[0]);i++){
        Tree_list(Tree_Create(a[i]),Root);
    }
    struct Tree *temp=Root;
    //Tree_Find_HEAD(Root,11);
     Tree_Del(7,Root);
    Tree_Find_HEAD(Root,12);
    //struct TreeARoot * temp2=Tree_Find_HEAD_Min(Root);
   // printf("\n %d\n",temp2->Child->value);
    Tree_Del(10,Root);
    for(int i=0;i<11;i++)
    Tree_Find_HEAD(Root,i);
  // printf("\n %d\n",temp2->Child->value);

//    int a[]={2,5,3,10,8,9,11,4,6,7};
//     struct Tree * Root=Tree_Create(a[0]);
//     for(int i=1;i<(sizeof a/sizeof a[0]);i++){
//        Tree_list(Tree_Create(a[i]),Root);
//     }
//     struct TreeARoot * rtemp=Tree_Find_HEAD(Root,15);
//     if(rtemp)
//     printf(" %d ",rtemp->Root->value);
//     else{
//         printf("WARN");
//     }
//     ;
}

struct Tree *Tree_Create(int value){
    struct Tree * temp=malloc(sizeof (struct Tree));
    temp->value=value;
    temp->Left=NULL;
    temp->right=NULL;
}
int Tree_list(struct  Tree * leaf,struct Tree * Root){
    struct Tree *temp=Root;
    for(;;)
    {
        if(leaf->value>temp->value)
        {
            if(temp->right)
                temp=temp->right;
            else{
                temp->right=leaf;
                break;
            }   
        }else
        {
            if(temp->Left)
                temp=temp->Left;
            else{
                temp->Left=leaf;
                break;
            }    
        }
        /* code */
    }
    
}
struct Tree *Tree_Find(struct Tree * Root,int value){
     struct Tree *temp=Root;
    for(;;)
    {
        if(value>temp->value)
        {
            if(temp->right)
                temp=temp->right;
            else{
                return NULL;
            }   
        }else if(value==temp->value){
            return temp;
        }else
        {
            if(temp->Left)
                temp=temp->Left;
            else{
              return NULL;
            }    
        }
        /* code */
    }
      return NULL;
}

struct TreeARoot * Tree_Find_HEAD(struct Tree * Root,int value){
    //  struct Tree * temp=Root;
    // struct Tree * temp_head=NULL;
    //  for(;;)//前序排列
    // {
    //     if(temp->value==value) break;
    //     if(temp->right){
    //          Tree_Stack_pull(temp->right);
    //     }
        
    //     if((temp->Left==NULL)){
    //         struct Tree_Stack *stemp=Tree_Stack_push();
    //         if(stemp){
    //             temp_head=temp;
    //             temp=stemp->point;
    //            // printf("%d  ",temp->value);
    //             free( stemp);;
    //         }else{
    //             break;
    //         }
    //     }else{
    //         temp_head=temp;
    //          temp=temp->Left;
    //     } 
    //     if(temp==NULL)
    //         break;
    //     printf(" %d  ",temp->value);
    // }

    struct Tree * temp=Root;
    struct Tree * temp_root=Root;
    #if DEBUG
    printf("\nadasadadadsadad\n");
    #endif
     for(;;)//前序排列
    { 
        #if DEBUG
        
        printf(" %d  ",temp->value);
        if(temp_root) printf(" %d ",temp_root->value);
       
        printf("\n");
        #endif
        
        if(temp->value==value) {
                struct  TreeARoot * finetemp;
                finetemp=malloc(sizeof (struct TreeARoot));
                finetemp->Child=temp;
                finetemp->Root=temp_root;
                Tree_Stack_rm();

                #if DEBUG
                printf("\nadasadadadsadad\n");
                #endif
                return finetemp;
        }
        if(temp->right){
             Tree_Stack_pull(temp);
        }
        
        if((temp->Left==NULL)){
            struct Tree_Stack *stemp=Tree_Stack_push();
            if(stemp){
              temp_root=stemp->point;
                temp=stemp->point->right;
               // printf("%d  ",temp->value);
                free( stemp);;
            }else{
                break;
            }
        }else{
            temp_root=temp;
             temp=temp->Left;
        } 
       
    }
    Tree_Stack_rm();

    return NULL;
}
int Tree_Del(int value,struct Tree * Root){
    printf(" \n ");
   struct TreeARoot * temp= Tree_Find_HEAD(Root,value);
   if(temp){
            struct Tree *child=temp->Child;
            struct Tree *root=temp->Root;
            if((child->Left==NULL)&&(child->right==NULL))
            {
                if(root->Left==child){
                    root->Left=NULL;
                }else root->right=NULL;
                free(child);
                free (temp);
            }else if(!child->Left){
                if(root->Left==child){
                    root->Left=child->right;
                }else root->right=child->right;
                free(child);
                free (temp);
                ;
            }else if(!child->right){
                if(root->Left==child){
                    root->Left=child->Left;
                }else root->right=child->Left;
                free(child);
                free (temp);
                ;
            }else if(child->Left&&child->right){
                struct TreeARoot * atemp=Tree_Find_HEAD_Min(child->right);
                child->value=atemp->Child->value;
                if(atemp->Child==child->right)
                    child->right=NULL;
                else if(atemp->Child==child->Left)
                    child->Left=NULL;
                Tree_Del(atemp->Child->value,atemp->Root);
                free(temp);
            }
       }else{
    printf("WARN");
    return -1;
   }

   return 0;
}



struct Tree_Stack *Tree_Stack_pull(struct Tree * point){
    if(Tree_Stack_head==NULL){
        Tree_Stack_head=malloc(sizeof (struct Tree_Stack));
        Tree_Stack_head->point=point;
        Tree_Stack_head->next=NULL;
    }else{
        struct Tree_Stack *temp;
        temp=malloc(sizeof (struct Tree_Stack));
        temp->point=point;
        temp->next=Tree_Stack_head;
        Tree_Stack_head=temp;
    }
    ;
}
struct Tree_Stack *Tree_Stack_push(){
    struct Tree_Stack * temp;
    temp=Tree_Stack_head;
    
    if(temp){ 
        Tree_Stack_head=Tree_Stack_head->next; 
        return temp;
    }else{
        Tree_Stack_head=NULL;
        return NULL;
    }
}
int Tree_Stack_rm(){

    while (Tree_Stack_push());
    return 0;
}

struct TreeARoot * Tree_Find_HEAD_Min(struct Tree * Root){

    struct Tree * temp=Root;
    struct Tree * temp_root=Root;
    struct TreeARoot * temp_min;
    temp_min=malloc(sizeof(struct TreeARoot));
    temp_min->Child=temp;
    temp_min->Root=temp_root;
     for(;;)//前序排列
    { 
        if(temp->value) {
                if(temp->value<temp_min->Child->value)
                {
                temp_min->Child=temp;
                temp_min->Root=temp_root;
                Tree_Stack_rm();
                
                }
                
        }
        if(temp->right){
             Tree_Stack_pull(temp);
        }
        
        if((temp->Left==NULL)){
            struct Tree_Stack *stemp=Tree_Stack_push();
            if(stemp){
              temp_root=stemp->point;
                temp=stemp->point->right;
                free( stemp);;
            }else{
                break;
            }
        }else{
            temp_root=temp;
             temp=temp->Left;
        } 
        if(temp==NULL)
            break;
    }
    Tree_Stack_rm();
    return temp_min;
}