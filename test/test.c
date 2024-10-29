#include <stdio.h>
#include<stdlib.h>    
#include<time.h>
#include<stdarg.h>
    int num[5];

int find_MAX(int num,...){
    va_list ap;va_list copy;
    va_start(ap,num);va_copy(copy,ap);
    int t=va_arg(ap,int);
    for(int current=0,i=1;i<num;i++){
        current=va_arg(ap,int);
        if(current>t){
            t=current;
        }
    }
    vfprintf(stderr,"%d %d %d %d %d",copy);
    va_end(copy);
    va_end(ap);
    return t;
}
void fun(){
    printf("%d",find_MAX(5,num[0],num[1],num[2],num[3],num[4]));
    time_t time1=time(NULL);
    printf("\n%s",ctime(&time1));
}
int main(void){
    for (int i=0;i<5;i++)scanf("%d",&num[i]);
    atexit(fun);
    for(int i=0;i<22;i++)printf("11");
    return 0;
}