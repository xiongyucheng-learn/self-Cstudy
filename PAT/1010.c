#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void){
    int nums[100];
    int nums_j=0;int chars_num=0;char chars[1000]={};
    while ((chars[chars_num++]=getchar())!='\n');
    chars[chars_num-1]='\0';
    int t=0;int n=0;
    for(int i=0;chars[i]!='\0'&&i<1000;i++){
        if(chars[i]!=' '){
            t+=(chars[i]-'0')*pow(10,n);
        }else{
            nums[nums_j++]=t;
            t=0;
            n=0;
        }
    }
    printf("h");

    return 0;
}