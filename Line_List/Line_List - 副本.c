#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10
int SIZE=0;
int Contexts=0;
struct Line_List{
    short ID;
    char*Name;
    char*Group;
    short score;
};
struct Line_List * Line_List_Create();
struct Line_List ** File_Read(struct Line_List**);
int Line_List_Printf(struct Line_List**,int);
struct Line_List ** Line_List_Found(struct Line_List **,void *,int,int*,int*);
struct Line_List** Line_List_Del(struct Line_List**,struct Line_List*,int*,int*);
int Line_List_instert(struct Line_List*,struct Line_List *);
//int File_Printf(struct Line_List*);
struct Line_List ** Line_List_realloc(struct Line_List**,int ,int*);
struct Line_List ** Line_List_realloc_no_Create(struct Line_List**,int ,int*);
int Line_List_Del_quick(struct Line_List*,int);

int main(char argv,char *arg[]){
    freopen("linear.in","r",stdin);
    struct Line_List **Lists=Line_List_realloc(NULL,MAX_SIZE,&SIZE);
    Lists=File_Read(Lists);
   // freopen("linear.out","w",stdout);
    //Line_List_Printf(Lists,Contexts);
    //printf("*********************************************************\n");
//     struct Line_List **FLists=NULL;
//        FLists= Line_List_Found(Lists,(void *)(char []){"Grp_D"},2,&Contexts,&tSIZE);
//         Line_List_Printf(FLists,tSIZE);
//        free(FLists);
    
    
//     printf("*********************************************************\n");
//        FLists= Line_List_Found(Lists,(void *)(char []){"Grp_C"},2,&Contexts,&tSIZE);
//         Line_List_Printf(FLists,tSIZE);
//        free(FLists);
    

// printf("*********************************************************\n");
//        FLists= Line_List_Found(Lists,(void *)(char []){"Grp_A"},2,&Contexts,&tSIZE);
//         Line_List_Printf(FLists,tSIZE);
//        free(FLists);
    

// printf("*********************************************************\n");
//        FLists= Line_List_Found(Lists,(void *)(char []){"Name_177"},1,&Contexts,&tSIZE);
//         Line_List_Printf(FLists,tSIZE);
//        free(FLists);
    
    int tSIZE1=0;
    
    int tSIZE=0;
    int tc=0;
    struct Line_List **temp2=Line_List_Found(Lists,(void *)(char []){"Grp_D"},2,&Contexts,&tSIZE);
    //for(int i=0;i<tSIZE;i++)
    Lists=Line_List_Del(Lists,temp2[0],&Contexts,&tSIZE1);
    //Line_List_Printf(Lists,Contexts);
    //system("pause");
    // _sleep(100000);
}
struct Line_List * Line_List_Create(){
    struct Line_List *temp;
    temp=malloc(sizeof(struct Line_List));
    return temp;
}
struct Line_List ** File_Read(struct Line_List** list){
    int ID,score;
    char*Name,*Group;
    
    int i=0;int j=0;
     while (Name=malloc(10),Group=malloc(10),scanf("%d %s %s %d",&ID,Name,Group,&score)!=EOF)
     {
        if(i<SIZE-1);
        else{
           if((list=Line_List_realloc(list,MAX_SIZE,&SIZE))==NULL){
            list[i]=NULL;
            return list;
           }
        }
        list[i]->ID=ID;
        list[i]->Name=Name;
        list[i]->Group=Group;
        list[i]->score=score;
        if(i%1000==0){
            printf("wda");
        }
        i++;
    }
    Contexts=i;
    return list;
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

struct Line_List ** Line_List_realloc_no_Create(struct Line_List** lists,int n,int *SIZE ){
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
    // for(int i=*SIZE;i<(*SIZE+n);i++)
    //     temp[i]=Line_List_Create();
    *SIZE=*SIZE+n;
    return temp;
}
int Line_List_Printf(struct Line_List** lists,int context){
    for(int i=0;i<context;i++){
        printf("%d %s %s %d \n",lists[i]->ID,lists[i]->Name,lists[i]->Group,lists[i]->score);
    }
    
}
struct Line_List ** Line_List_Found(struct Line_List ** list,void * value,int mod,int *Contexts,int *tSZIE){
   
    int j=0;int size=0; 
    struct Line_List **temp=Line_List_realloc_no_Create(NULL,MAX_SIZE,&size);
    for(int i=0;i<*Contexts;i++){
        int  BOOLI=1;
        switch (mod)
        {
        case 0://(short)(*(short*)(value))
            if(list[i]->ID == (short)(*((short *)value)))
                temp[j++]=list[i];
            /* code */
            break;
        case 1:
        if(list[i]->Name==(char*)value)
                temp[j++]=list[i];
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
        for(int k=0;((char*)value)[k]!='\0';k++){
            if(list[i]->Group[k]!=((char*)value)[k])BOOLI=0;
        }
        if(BOOLI)temp[j++]=list[i];
            /* code */
            break;
        default:
            free(temp);
            temp=NULL;
            return temp;
            break;
        }
        if(j<size-1);
        else{
           if((temp=Line_List_realloc_no_Create(temp,MAX_SIZE,&size))==NULL){
            temp[j]=NULL;
            return list;
           }
        }
    }
    *tSZIE=j;
        return temp;
}
struct Line_List** Line_List_Del(struct Line_List** list,struct Line_List*To_Del,int *Context,int *tSIZE){
    struct Line_List **temp;
    int i=0;int j=0;int ttSize=0;
    temp=Line_List_realloc_no_Create(NULL,MAX_SIZE,&ttSize);
    while (i<*Context)
    {
        printf(" %d  %d \n",i,Context);
        if(list[i]!=To_Del)temp[j++]=list[i];
        else{
            free(list[i]);
        }
        if(j<*tSIZE-1);
        else{
           if((printf("SSS\n"),temp=Line_List_realloc_no_Create(temp,MAX_SIZE,&ttSize))==NULL){
            temp[j]=NULL;
            return list;
           }
        }
        i++;
        /* code */
    }
    free(list);
    *Context=j;
    return temp;
}