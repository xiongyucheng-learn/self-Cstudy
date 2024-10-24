#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define DEBUG 0
struct Tree{
    struct Tree * Left;
    struct Tree * Right;
    int value;
};

struct TreeARoot{
    struct Tree * Root;
    struct Tree * Child;
};

struct Tree_Stack{
    struct Tree * point;
    struct Tree_Stack * next;
};

struct Tree_Stack * Tree_Stack_head=NULL;
struct Tree_Stack * Tree_Stack_push();
int Tree_Stack_pull(struct Tree *);
int Tree_Stack_rm();
struct Tree * Tree_point_Create(int);
int Tree_point_add(struct Tree *,struct Tree *);
struct TreeARoot * Tree_find(struct Tree *,int);
struct TreeARoot * Tree_find_min(struct Tree *);
int Tree_del(struct Tree *,int);
int Tree_print(struct Tree *);
struct Tree * temRoot=NULL;
int main(void){
   
    int a[]={4,6,8,2,5,9,1,3};
    struct Tree * Root=Tree_point_Create(a[0]);
    system("pause");
    for(int i=1;i<sizeof(a)/sizeof(a[0]);i++){
        Tree_point_add(Root,Tree_point_Create(a[i]));
    }
    for(int j=0;j<sizeof(a)/sizeof(a[0]);j++){
        if(Tree_del(Root,a[j])){
            Root=NULL;
        }else{
            Tree_print(Root);
        }
        _sleep(10);
        
    }
    system("pause");
}

struct Tree * Tree_point_Create(int value){
    struct Tree * temp=malloc(sizeof (struct Tree));
    temp->Left=NULL;
    temp->Right=NULL;
    temp->value=value;
    return  temp;
}

int Tree_point_add(struct Tree * Root,struct Tree * child){

    struct Tree * temp=Root;
    for(;;){
        if(child->value>temp->value){
                if(!temp->Right){
                    temp->Right=child;
                    return 0;
                }else{
                    temp=temp->Right;
                }
            }else{
                if(!temp->Left){
                    temp->Left=child;
                    return 0;
                }else{
                    temp=temp->Left;
                }
            }
    }
    return 0;
}

struct TreeARoot * Tree_find(struct Tree * Root,int value){
    struct TreeARoot * fineTemp=malloc(sizeof(struct TreeARoot));
    #if DEBUG
    printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
    #endif
    fineTemp->Child=Root;
    fineTemp->Root=Root;
    for(;;){
         #if DEBUG
        printf("%d   %d \n",fineTemp->Child->value,fineTemp->Root->value);
         #endif
        if(fineTemp->Child->value==value){
            break;
        }
        if(fineTemp->Child->Right){
                Tree_Stack_pull(fineTemp->Child);
            }
        if(fineTemp->Child->Left==NULL){
            fineTemp->Root=fineTemp->Child;
            struct Tree_Stack * stemp=Tree_Stack_push();
            if(stemp){
                fineTemp->Root=stemp->point;
                fineTemp->Child=stemp->point->Right;
                free(stemp);
            }else{
                free(fineTemp);
                return NULL;
            }
        }else{
                fineTemp->Root=fineTemp->Child;
                fineTemp->Child=fineTemp->Child->Left;
            }
    }
    Tree_Stack_rm();
    #if DEBUG
    printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
    #endif
     return fineTemp;
}
struct TreeARoot * Tree_find_min(struct Tree * Root){
     struct TreeARoot * fineTemp=malloc(sizeof(struct TreeARoot));
      struct TreeARoot * ffineTemp=malloc(sizeof(struct TreeARoot));
    #if DEBUG
    printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
    #endif
    fineTemp->Child=Root;
    fineTemp->Root=Root;
    ffineTemp->Child=fineTemp->Child;
    ffineTemp->Root=fineTemp->Root;
    for(;;){
         #if DEBUG
        printf("%d   %d \n",fineTemp->Child->value,fineTemp->Root->value);
         #endif

        if(fineTemp->Child->value<ffineTemp->Child->value){
           ffineTemp->Child=fineTemp->Child;
         ffineTemp->Root=fineTemp->Root;
        }
        if(fineTemp->Child->Right){
                Tree_Stack_pull(fineTemp->Child);
            }
        if(fineTemp->Child->Left==NULL){
            fineTemp->Root=fineTemp->Child;
            struct Tree_Stack * stemp=Tree_Stack_push();
            if(stemp){
                fineTemp->Root=stemp->point;
                fineTemp->Child=stemp->point->Right;
                free(stemp);
            }else{
                free(fineTemp);
            #if DEBUG
                printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
                #endif
                return ffineTemp;
            }
        }else{
                fineTemp->Root=fineTemp->Child;
                fineTemp->Child=fineTemp->Child->Left;
            }
       
    }
}
int Tree_Stack_pull(struct Tree * point){
    if(!Tree_Stack_head){
        Tree_Stack_head=malloc(sizeof(struct Tree_Stack));
        Tree_Stack_head->point=point;
        Tree_Stack_head->next=NULL;
    }else{
        struct Tree_Stack *temp;
        temp=malloc(sizeof(struct Tree_Stack));
        temp->point=point;
        temp->next=Tree_Stack_head;
        Tree_Stack_head=temp;
    }
}

struct Tree_Stack * Tree_Stack_push(){

    struct Tree_Stack *temp=malloc(sizeof (struct Tree_Stack));
    if(Tree_Stack_head){
        Tree_Stack_head=Tree_Stack_head->next;
    }else{
        free (temp);
        return NULL;
    }
    return temp;
}

int Tree_Stack_rm(){
    for(;Tree_Stack_push()!=NULL;);
}


int Tree_del(struct Tree * Root,int value){
    struct TreeARoot * temp=Tree_find(Root,value);
    if(temp){
        if(temp->Child==temp->Root){
            if(temp->Root->Left&&temp->Root->Right){
                struct TreeARoot *mintemp=Tree_find_min(temp->Child->Right);
                if(mintemp->Child==mintemp->Root){
                    if(mintemp->Child->Right){
                        temp->Child->value=mintemp->Child->value;
                        temp->Child->Right=mintemp->Child->Right;
                        free(mintemp->Child);
                    }
                    else if (mintemp->Child->Left){
                        temp->Child->value=mintemp->Child->value;
                        free(mintemp->Child);
                    }else{
                       temp->Child->value=mintemp->Child->value;
                       Tree_del(temp->Child->Right,mintemp->Child->value);
                       temp->Child->Right=NULL;
                    }  
                }else{
                    if((mintemp->Child->Left==NULL)&&(mintemp->Child->Right==NULL)){
                        if(mintemp->Root->Left==mintemp->Child){
                            mintemp->Root->Left=NULL;
                        }else {
                            mintemp->Root->Right=NULL;
                        }
                            temp->Child->value=mintemp->Child->value;
                            free(mintemp->Child);
                    }else if(mintemp->Child->Right){
                            temp->Child->Right=mintemp->Child->Right;
                            temp->Child->value=mintemp->Child->value;
                            free(mintemp->Child);
                        }
                    }
            }else if(temp->Root->Left){
                struct Tree * del_temp=temp->Root->Left;
                *(temp->Root)=*(temp->Root->Left);
                free(del_temp);
                
            }else if(temp->Root->Right){
                struct Tree * del_temp=temp->Root;
                *(temp->Root)=*(temp->Root->Right);
                free(del_temp);
            }else if((temp->Root->Left==NULL)&&(temp->Root->Left==NULL)){
                free(temp->Root);
                return 1;
            }
        }
        else{
            if((temp->Child->Left==NULL&&temp->Child->Right==NULL)){
                if(temp->Root->Left==temp->Child){
                    temp->Root->Left=NULL;
                    free(temp->Child);
                }else if(temp->Root->Right==temp->Child){
                    temp->Root->Right=NULL;
                    free(temp->Child);
                }else printf("0");
                
            }else if(temp->Child->Left==NULL){
                if(temp->Root->Right==temp->Child){
                    temp->Root->Right=temp->Child->Right;
                    free(temp->Child);
                }else{
                    temp->Root->Left=temp->Child->Right;
                    free(temp->Child);
                }
            }else if(temp->Child->Right==NULL){
                if(temp->Root->Right==temp->Child){
                    temp->Root->Right=temp->Child->Left;
                    free(temp->Child);
                }else{
                    temp->Root->Left=temp->Child->Left;
                    free(temp->Child);
                }
            }else if(temp->Child->Right&&temp->Child->Left){
                struct TreeARoot *mintemp=Tree_find_min(temp->Child->Right);
                if(mintemp->Child==mintemp->Root){
                    if(mintemp->Child->Right){
                        temp->Child->value=mintemp->Child->value;
                        temp->Child->Right=mintemp->Child->Right;
                        free(mintemp->Child);
                    }
                    else{
                        temp->Child->value=mintemp->Child->value;
                        temp->Child->Right=NULL;
                        free(mintemp->Child);
                    }
                }else{
                    //temp->Child=mintemp->Child;
                    if((mintemp->Child->Left==NULL)&&(mintemp->Child->Right==NULL)){
                        if(mintemp->Root->Left==mintemp->Child){
                            mintemp->Root->Left=NULL;
                        }else {
                            mintemp->Root->Right=NULL;
                        }
                        temp->Child->value=mintemp->Child->value;
                        Tree_del(mintemp->Child,mintemp->Child->value);
                    }else if(mintemp->Child->Right){
                        temp->Child->Right=mintemp->Child->Right;
                        temp->Child->value=mintemp->Child->value;
                        free(mintemp->Child);
                    }
                   
                }
            }else printf("1");
        }
    }
    return 0;
}
int  Tree_print(struct Tree * Root){
   struct TreeARoot * fineTemp=malloc(sizeof(struct TreeARoot));
    printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
    fineTemp->Child=Root;
    fineTemp->Root=Root;
    for(;;){
        printf("%d   %d \n",fineTemp->Child->value,fineTemp->Root->value);
        if(fineTemp->Child->Right){
                Tree_Stack_pull(fineTemp->Child);
            }
        if(fineTemp->Child->Left==NULL){
            fineTemp->Root=fineTemp->Child;
            struct Tree_Stack * stemp=Tree_Stack_push();
            if(stemp){
                fineTemp->Root=stemp->point;
                fineTemp->Child=stemp->point->Right;
                free(stemp);
            }else{
                free(fineTemp);
                printf("ADADSDADFASFAFAFAFFAFAFAFF\n");
                return 0;
            }
        }else{
                fineTemp->Root=fineTemp->Child;
                fineTemp->Child=fineTemp->Child->Left;
            }
       
    }
}
//int Tree_del(struct Tree * Root,int value){
// struct TreeARoot * temp= Tree_find(Root,value);
//    if(temp){
//             struct Tree *child=temp->Child;
//             struct Tree *root=temp->Root;
//             if((child->Left==NULL)&&(child->Right==NULL))
//             {
//                 if(root->Left==child){
//                     root->Left=NULL;
//                 }else root->Right=NULL;
//                 free(child);
//                 free (temp);
//             }else if(!child->Left){
//                 if(root==child){
//                     struct Tree * temp1=root->Right;
//                     *Root=*(root->Right);
//                     free(temp1);

//                 }else{
//                         if(root->Left==child){
//                         root->Left=child->Right;
//                         }else root->Right=child->Right;
//                         free(child);
//                         free (temp);
//                 }
                
//             }else if(!child->Right){
//                  if(root==child){
//                      struct Tree * temp1=root->Left;
//                     *root=*(root->Left);
//                     free(temp1);
//                 }else{
//                     if(root->Left==child){
//                     root->Left=child->Left;
//                     }else root->Right=child->Left;
//                     free(child);
//                     free (temp);
//                     ;
//                 }
//             }else if(child->Left&&child->Right){
//                 // struct TreeARoot * atemp=Tree_find_min(child->Right);
//                 // child->value=atemp->Child->value;
//                 // if(atemp->Child==child->Right)
//                 //     child->Right=NULL;
//                 // Tree_del(atemp->Child,atemp->Child->value);
//                 // free(atemp->Child);
//                 // free(temp);

//                 struct TreeARoot * atemp=Tree_find_min(child->Right);
//                 temp->Child->value=atemp->Child->value;
//                 if(atemp->Child==atemp->Root){
//                     if(temp->Child->Left==atemp->Child){
//                         temp->Child->Left=atemp->Child->Left;
//                     }else{
//                         temp->Child->Right=atemp->Child->Right;
//                     }
//                 }
//                 Tree_del(atemp->Child,atemp->Child->value);
//                 return 0;
//             }
//        }
//        else{
//     printf("WARN");
//     return -1;
//    }

//    return 0;

//    }