#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_STACK 100
char contents[MAX_STACK];
int top;
bool is_empty(void);
bool is_full(void);
void Stack_empty(void);
void Stack_overflow();
void Stack_underflow();
void push(char);
char pull();
int main(void) {
    char t;
    scanf(" %c",&t);
    for(;t!='\n';t=getchar()) 
    {
        if(t==')'||t==']'||t=='}'){
            char h;
            h=pull();
            if((t==')'&&h!='(')||(t==']'&&h!='[')||(t=='}'&&h!='{')){
                printf("WARRY\n");
                return 0;
            }
        }else{
           push(t); 
        }
    }
    if(is_empty()){
         printf("TRUE");
    }else  printf("WARRY\n");
   
    return 0;
}

bool is_empty(void){
    return top==0;
}
bool is_full(){
    return top==MAX_STACK-1;
}
void Stack_overflow(){
    printf("WARROY,STACK_OVERFLOW\n");
    exit(-1);
    }
void Stack_underflow(){
    printf("WARROY,STACK_UNDERFLOW\n");
    exit(-1);
}
void Stack_empty(){
    top=0;
}
void push(char n){
    if(is_full())
    {
        Stack_overflow();
    }else{
        contents[top++]=n;
    }
}
char pull(){
    if(is_empty())
    Stack_underflow();
    else
    return contents[--top];
}