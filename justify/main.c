#include"line.h"
#include"read_says.h"
#include<stdio.h>

int main(void){
    int t=0;
    do
    {   
        t=line();
        printf("%s",Line_Justified);
        update();
        /* code */
    }while (!t);
    
    scanf(" ");
}