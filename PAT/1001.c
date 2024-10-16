#include <stdio.h>
int main(void){
    int a;
    scanf("%d",&a);
    int sum=0;
    for(;a!=1;sum++){
        if(!(a%2)){
            a/=2;
        }else{
            a=(3*a+1)/2;//m=((3a+1)/2-1)/3;
        }
    }
    printf("%d",sum);
    return 0;
}