#include<stdio.h>
int zs[10000];
int zs_num;
int is_zs(int);
int main (void){
    int N;
    scanf("%d",&N);
    zs[zs_num++]=1;
    for(int i=2;i<=N;i++){
        is_zs(i);
    }
    int sum=0;
    for(int i=1;i<zs_num;i++){
        if(zs[i]-zs[i-1]==2){
            sum++;
        }
    }
    printf("%d",sum);
}
int is_zs(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    zs[zs_num++]=num;
    return 1;
}