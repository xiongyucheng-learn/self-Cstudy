#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    int numbers;
    int score;
    int jige,youxiu;
    jige=youxiu=0;

    scanf("%d",&numbers);
    for(int i=0;i<numbers;i++){
        scanf("%d",&score);
        if(score>=60){
            jige++;
            if(score>=85)
            youxiu++;
        }
    }
    float jigeff=(float)jige/numbers;
     float youxiuff=(float)youxiu/numbers;
   int jigef=(int)(jigeff*1000)-(int)(jigeff*1000)/10*10>=5?(int)(jigeff*100)+1 :(int)(jigeff*100);
      int youxiuf=(int)(youxiuff*1000)-(int)(youxiuff*1000)/10*10>=5?(int)(youxiuff*100)+1 :(int)(youxiuff*100);
 
    printf("%d%%\n",jigef);
    printf("%d%%",youxiuf);
}   