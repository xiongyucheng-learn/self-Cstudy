#include"read_says.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char words[MAX_WORD+1];
int word_len;
int read_word(void){
    char *p=words;
   // words[MAX_WORD]='\0';
    // while ((*p=getchar())==' ')
    // {
    //     ;
    //     /* code */
    // }
    word_len=0;
    memset(words,'\0',sizeof words);
   scanf(" ");
    while (p<words+MAX_WORD)
    {
        *p=getchar();
        if(*p==' ')return 1;
        else if(*p=='|') return 2;
        else if(*p=='\n')return 0;
        p++;
        word_len++;
        /* code */
    }
    *p='*';
    exit(0);
}
