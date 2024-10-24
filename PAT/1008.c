#include<stdio.h>
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int nums[N];
    for(int i=0;i<N;i++)
        scanf("%d",&nums[i]);
    for(int j=0;j<M;j++){
        int t=nums[N-1];
        for(int i=N-1;i>=0;i--){
            if(i-1>=0){
                nums[i]=nums[i-1];
            }else{
                nums[i]=t;
            }
        }

    }

    for(int i=0;i<N;i++){
        printf("%d",nums[i]);
        if(i<N-1)
            printf(" ");
    }
}