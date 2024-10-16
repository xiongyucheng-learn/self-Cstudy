#include<stdio.h>
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int nums[N];
    for(int i=0;i<N;i++)scanf("%d",nums[i]);
    for(int i=M;i<N-M;i++){
        nums[i]=nums[i-M];
    }
    for(int i=0,i<M;i++){
        
    }
}