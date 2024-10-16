#include<stdio.h>
#include<stdlib.h>
int main(void){
    char num[4];
    int num_j=0;
      while ((num[num_j++]=getchar())!='\n'&&num_j<4);
    num[--num_j]='\0';
    for(int i=0;i<num_j;i++){
        switch (num_j-i)
        {
        case 3:
            for(int k=0;k<num[i]-'0';k++)printf("B");
            break;
        case 2:
            for(int k=0;k<num[i]-'0';k++)printf("S");
            break;
        case 1:for(int k=0;k<num[i]-'0';k++)printf("%d",k+1);
            break;
        default:
            break;
        }
    }
    return 0;
}