#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define DEBUG 0
#define MAX_SIZE 1000000
struct Line_List{
    short ID;
    char*Name;
    char*Group;
    short score;

};
struct Line_List * Line_List_Create();
struct Line_List ** File_Read(int*,int*);
int Line_List_Printf(struct Line_List**,int);
struct Line_List ** Line_List_Found(struct Line_List **,void *,int,int,int*,int*);
struct Line_List** Line_List_Del(struct Line_List**,struct Line_List*,int*,int*);
int Line_List_instert(struct Line_List*,struct Line_List *);
//int File_Printf(struct Line_List*);
struct Line_List ** Line_List_realloc(struct Line_List**,int ,int*);
struct Line_List ** Line_List_realloc_no_Create(struct Line_List**,int ,int*);
struct Line_List** Line_List_Del_quick(struct Line_List**,struct Line_List**,int*,int*,int);

int main(char argv,char *arg[]){
    time_t time1;
    time(&time1);
    int SIZE=0;
    int Contexts=0;
    int ttSize=0;
    freopen("linear.in","r",stdin);
    struct  Line_List **list=File_Read(&SIZE,&Contexts);
   // Line_List_Printf(list,Contexts);
    printf("Hello");
    int fc=0;
    struct Line_List **temp;
    time_t time2;
    time(&time2);
    temp=Line_List_Found(list,(char *){"Grp_D"},2,Contexts,NULL,&fc);
    
    //for(int i=0;i<fc;i++)list=Line_List_Del(list,temp[i],&Contexts,&SIZE);

    time_t time3;
    time(&time3);
    list=Line_List_Del_quick(list,temp,&Contexts,&SIZE,fc);
    time_t time4;
    time(&time4);
     freopen("linear.out","w",stdout);
    Line_List_Printf(list,Contexts);
    freopen("CON","w",stdout);

     time_t time5;
    time(&time5);
    printf("  %f  %f  %f  %f %f",difftime(time2,time1),difftime(time3,time2),difftime(time4,time3),difftime(time5,time4),difftime(time5,time1));
    _sleep(100000);
    return 0;
}
struct Line_List * Line_List_Create(){
    struct Line_List *temp;
    temp=(struct Line_List*)malloc(sizeof(struct Line_List));
    return temp;
}
struct Line_List ** File_Read(int * SIZE,int * Context){
    int ID,score;
    char*Name,*Group;
    struct Line_List **temp=NULL;
    int i=0;int j=0;
     while (Name=(char*)malloc(10),Group=(char*)malloc(10),scanf("%d %s %s %d",&ID,Name,Group,&score)!=EOF)
     {
        if(i>=*SIZE-1)
        {   
            if((temp=Line_List_realloc(temp,MAX_SIZE,SIZE))==NULL){
            temp[i]=NULL;
            return temp;
           }
        }
        temp[i]->ID=ID;
        temp[i]->Name=Name;
        temp[i]->Group=Group;
        temp[i]->score=score;
        #if DEBUG
        if(i%1000==0){
            printf("第%d个千次扩容\n",i%1000+1);
        }
        #endif
        i++;
    }
    *Context=i-1;
    return temp;
}
struct Line_List ** Line_List_realloc(struct Line_List** lists,int n,int *SIZE ){
    struct Line_List **temp;
    temp=(struct Line_List **)malloc(sizeof (struct Line_List *)*(*SIZE+n));
    if(temp==NULL){
        return NULL;
    }
    for(int i=0;i<*SIZE;i++){
        temp[i]=lists[i];
    }
    if(lists!=NULL)
        free(lists);
    for(int i=*SIZE;i<(*SIZE+n);i++)
        temp[i]=Line_List_Create();
    *SIZE=*SIZE+n;
    return temp;
}


int Line_List_Printf(struct Line_List** lists,const int context){
    int i=0;
    for(;i<context;i++){
        
        printf("%d %s %s %d \n",lists[i]->ID,lists[i]->Name,lists[i]->Group,lists[i]->score);
        #if DEBUG
        if(i%30==0){
            printf("%d\n",i);
        }
        #endif
    }
    return 0;
}
struct Line_List ** Line_List_Found(struct Line_List ** list,void * value,int mod,int List_Contexts,int *tSZIE,int *tContexts){
    int j=0;int size=0; 
    struct Line_List **temp=Line_List_realloc_no_Create(NULL,MAX_SIZE,&size);
    for(int i=0;i<List_Contexts;i++){
        int  BOOLI=1;
        switch (mod)
        {
        case 0://(short)(*(short*)(value))
            if(list[i]->ID == (short)(*((short *)value)))
                temp[j++]=list[i];
            /* code */
            break;
        case 1:
        for(int k=0;((char*)value)[k]!='\0';k++){
            if(list[i]->Group[k]!=((char*)value)[k])BOOLI=0;
        }
        if(BOOLI)temp[j++]=list[i];
            /* code */
            break;
        case 2:
        
        for(int k=0;((char*)value)[k]!='\0';k++){
            if(list[i]->Group[k]!=((char*)value)[k])BOOLI=0;
        }
        if(BOOLI)temp[j++]=list[i];
            /* code */
            break;
        case 3:
        if(list[i]->ID == (short)(*((short *)value)))
                temp[j++]=list[i];
            /* code */
            break;
        default:
            free(temp);
            temp=NULL;
            return temp;
            break;
        }
        if(j>=size-1){
           if((temp=Line_List_realloc_no_Create(temp,MAX_SIZE,&size))==NULL){
                temp[j]=NULL;
                return list;
           }
        }
    }
    if(tSZIE)*tSZIE=size;
    if(tContexts)*tContexts=j;
    return temp;
}


struct Line_List ** Line_List_realloc_no_Create(struct Line_List** lists,int n,int *SIZE ){

    struct Line_List **temp;
    temp=(struct Line_List **)malloc((sizeof (struct Line_List *))*(*SIZE+n));
    if(temp==NULL){
        printf("WARROY");
        exit(0);
        return NULL;
    }
    if(lists)
        for(int i=0;i<*SIZE;i++){
            temp[i]=lists[i];
        }
    if(lists!=NULL);
        free(lists);
    *SIZE=*SIZE+n;
    //temp=(struct Line_List **)malloc((sizeof (struct Line_List *))*(*SIZE+n));
    return temp;
}
struct Line_List** Line_List_Del(struct Line_List** list,struct Line_List*To_Del,int *List_Context,int *tSIZE){
    struct Line_List **temp;
    int i=0;int j=0;int ttSize=0;
    temp=Line_List_realloc_no_Create(NULL,MAX_SIZE,&ttSize);
    //temp[119]=list[117];
    while (i<*List_Context)
    {
        #if DEBUG
        printf(" %d  %d \n",i,List_Context);
        #endif
       if(list[i]!=To_Del){
         #if DEBUG
        printf("%p %p",list[i],To_Del);
        #endif
        temp[j++]=list[i];}
       else {
           //free(list[i]);
        }
    //     if(list[i]!=To_Del)
    //    else {
    //        free(list[i]);
    //     }
        if(j>=ttSize-1){
           if((temp=Line_List_realloc_no_Create(temp,MAX_SIZE,&ttSize))==NULL){
            temp[j]=NULL;
            return list;
           }
        }
        i++;
        /* code */
    }
    if(list!=NULL)
        free(list);
    *List_Context=j;
    if(tSIZE)*tSIZE=ttSize;
    return temp;
   // return list;
}

struct Line_List** Line_List_Del_quick(struct Line_List** list,struct Line_List**To_Dels,int *List_Context,int *tSIZE,int dSIZE){
      struct Line_List **temp;
    int i=0;int j=0;int ttSize=0;
    temp=Line_List_realloc_no_Create(NULL,*List_Context,&ttSize);
    int  b;
    int del_num=0;
    for(int i=0;i<*List_Context;i++){
        b=0;
            if(list[i]==To_Dels[del_num]){
                #if DEBUG
                printf("%p %p",list[i],To_Del);
                #endif
                    b=1;
                }
        if(b){
            del_num++;
            free(list[i]);
        }else {
            temp[j++]=list[i];
        }
    }
    if(list!=NULL)
        free(list);
    *List_Context=j;
    if(tSIZE)*tSIZE=ttSize;
    return temp;
}


