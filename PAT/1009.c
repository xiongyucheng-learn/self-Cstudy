#include<stdio.h>
#include<windows.h>
int main(void){
    char chars[81]={};int char_num=0;
    scanf(" ");
    while ((chars[char_num++]=getchar())!='\n');
    chars[char_num-1]='\0';
    int temps[80]={0},temp_num=1;
    for(int i=0;chars[i]!='\0'&&i<81;i++){
        if(chars[i]==' '){
            temps[temp_num++]=i+1;
            chars[i]='\0';
            }

    }
    for(int i=temp_num-1;i>=0;i--){
        printf("%s",chars+temps[i]);
        if(i>=1)
            printf(" ");
        
    }
    Sleep(100);
}