#include "line.h"
#include "read_says.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char Line[MAX_LINE+1];
char Line_Justified[MAX_LINE+1];
int line(){
    char *p;
    p=Line;
    int y=0;
    int is_coutinue=1;
    int t;
    for(;is_coutinue;){
        if(!(t=read_word()))
        {
            is_coutinue=0;
        }
            if(p+word_len<=Line+MAX_LINE){
            for(int i=0;i<word_len;i++){
                *(p+i)=*(words+i);
            }
            p+=word_len;
            *p++=' ';
            y++;
        }else{
            break;
        }if (t==2)
        {
             is_coutinue=0;
        }
    }
    *--p='\n';
    int j=Line+MAX_LINE-p;
    if(y-1){
        justify((j+y-1)/(y-1));
    }else{
        justify(j);
    }
    if (t==2)
        {
            return 1;
        }
    return 0;
}

int justify(int n){
    char *ip=Line;
    char *q=Line_Justified;
    for(;ip<Line+MAX_LINE&&*ip!='\0';){
            for(;*ip!=' '&&*ip!='\n';ip++){
            *q++=*ip;
        }
        ip++;
        for( int i=0;i<n&&q+i<Line_Justified+MAX_LINE;i++){
            *q++=' ';
        }
    }
    *q='\n';
}

int update(){
    memset(Line,'\0',sizeof Line);
    memset(Line_Justified,'\0',sizeof Line_Justified);
}