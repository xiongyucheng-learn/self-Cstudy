#include <stdio.h>
int main(){
    int x,y,n,sum;
    scanf("%d",&n);
    sum=0;
    for(x=1;x<n;x++){
        y=n-x;
            if(!(y&x)){
                sum++;
            }
    }
    printf("%d",sum);
}