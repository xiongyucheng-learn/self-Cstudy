#include<stdio.h>
int main(void){
    char chars[100];
    int sum,i;
    i=0;
    sum=0;
    while((chars[i++]=getchar())!='\n');

    for(int k=0;k<=i&&chars[k]!='\n';k++){
        sum+=chars[k]-'0';
    }

    int ints2[4];
  //  memset(ints2,0,sizeof );
    int j=3;
    for(;j>=0;j--){
        ints2[j]=(sum-(sum/10)*10);
        sum/=10;
    }
    int BOOL=0;
    for(int l=0;l<=3;l++){
        switch(ints2[l]){
            case 0:
                if(BOOL){
                printf("ling");
                }
                break;
            case 1:
                printf("yi");
                BOOL=1;
                break;
            case 2:
                printf("er");
                  BOOL=1;
                break;
            case 3:printf("san");
                  BOOL=1;
                break;
            case 4: printf("si");
                  BOOL=1;
                break;
            case 5: printf("wu");
                  BOOL=1;
                break;
            case 6: printf("liu");
                  BOOL=1;
                break;
            case 7 : printf("qi");
                  BOOL=1;
                break;
            case 8: printf("ba");
                  BOOL=1;
                break;
            case 9: printf("jiu");
                  BOOL=1;
                break;
                
        }
        if(l<3&&l!=0&&BOOL) printf(" ");
    }


}