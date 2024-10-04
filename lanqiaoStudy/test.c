#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnum(char *,char);
int main(void){
    char chars[101];
    memset(chars,'\0',sizeof chars);
    scanf("%s",chars);
    int oit,nit;char oct,nct;
    oit=nit=0;
    oct=nct=' ';
    for(int i='a';i<='z';i++){
        nit=cnum(chars,i);
        if(nit>oit){
            oit=nit;
            nct=i;
        }
    }
    printf("%c\n%d",nct,oit);
}
int cnum(char *chars,char char1){
    char Char1=char1+('A'-'a');
    int sum=0;
    for(;*chars!='\0';chars++){
        if(*chars==Char1||*chars==char1)sum++;
    }
    return sum;
}