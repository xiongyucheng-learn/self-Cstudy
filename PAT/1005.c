#include <stdio.h>
int fg[1000];
int fg_sum;
int is_cx(int);
int main(void){
    int num;int no_fg[100];
    int no_fg_sum=0;int temp[100];int temp_num=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int t;
        scanf("%d",&t);
        is_cx(t);
        temp[temp_num++]=t;
    }
    for(int i=0;i<temp_num;i++){
        int BOOL=1;
        for(int j=0;j<fg_sum;j++){
            if(temp[i]==fg[j]){
                BOOL=0;
            }
            
        }
        if(BOOL){
                no_fg[no_fg_sum++]=temp[i];
            }
    }
    for(int j=0;j<no_fg_sum;j++){
        for(int k=0;k<no_fg_sum;k++){
            if(no_fg[k]<no_fg[j]){
                int t=no_fg[k];
                no_fg[k]=no_fg[j];
                no_fg[j]=t;
            }
        }
    }

    for(int j=0;j<no_fg_sum;j++){
        printf("%d",no_fg[j]);
        if(j<no_fg_sum-1)printf(" ");
    }
    return 0;
}
int is_cx(int num){
    int BOOL=1;
    int num_cp=num;
    for(int sum=0;num!=1;sum++){
        if(num%2==0){
            num/=2;
        }else{
            num=(3*num+1)/2;
        }
        for(int j=0;j<=fg_sum;j++){
            if(num==fg[j])
                BOOL=0;
        }
        if(BOOL){
            fg[fg_sum++]=num;
        }
        
        BOOL=1;
    }
    return 0;
}