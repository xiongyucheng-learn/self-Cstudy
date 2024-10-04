#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#define MAX_STACK 100
typedef struct Content
{
    char Ca;
    int Ib;
    bool i;
} Stack;
Stack contents[MAX_STACK];
int top;
/*********************************/
bool is_empty();
bool is_full();
void empty();
void pushC(char);
void pushI(int);                    //STACK
Stack pull(void);
void STACK_OVERFLOW();
void STACK_UNDERFLOW();
/********************************/
int to_int(char *,int );
void Stack_read();
/********************************/  
int main(void){
    Stack_read();
    for(int i=0;i<top;i++){
        if(contents[i].i){
            printf("%d ",contents[i].Ib);
        }else{
            printf("%c ",contents[i].Ca);
        }
    }
   return 0;
}
bool is_empty(){
    return top==0;
}
bool is_full(){
    return top==MAX_STACK;
}
void empty(){
    top=0;
}
void pushC(char n){
    if(is_full()){
        STACK_OVERFLOW();
    }else{
        contents[top].Ca=n;
        contents[top].i=0;
        top++;
    }
}
void pushI(int n){
    if(is_full()){
        STACK_OVERFLOW();
    }else{
        contents[top].Ib=n;
        contents[top].i=1;
        top++;
    }
}
Stack pull(){
    if(is_empty()){
        STACK_UNDERFLOW();
    }else{
        return contents[--top];
    }
}
void STACK_OVERFLOW(){
    printf("WARROY,STACK_OVERFLOW\n");
    exit(-1);
    }
void STACK_UNDERFLOW(){
    printf("WARROY,STACK_UNDERFLOW\n");
    exit(-1);
}

int to_int(char *chars,int n ){
    // int t=0;
    // for(int k=0;k<n;k++){
    //     int x=1;
    //     for(int j=n-k;j>1;j--)
    //     x*=10;
    //     t+=(chars[k]-48)*x;
    // }
    // return t;
    int t = 0;
    for (int k = 0; k < n; k++) {
        t = t * 10 + (chars[k] - '0'); // 使用乘法直接构建整数
    }
    return t;
}  

void Stack_read(){
    char chars[1000];int charI=0;
    char temps[7];int j=0;
    memset(chars,'\0',sizeof chars);
    do{
        chars[charI]=getchar();
          if(chars[charI]!=' '&&chars[charI]!='\n'){
           temps[j++]=chars[charI]; 
        }else{
            bool b=1;
            for(int k=0;k<j;k++){
                if(temps[k]<='0'||temps[k]>='9')b=0;
            }
            if(b==1){
               pushI(to_int(temps,j));
            }else if(j>=2){
                printf("WORRY !!!\n");
                exit(-1);
            }else{
                //pushC(temps[0]);
                switch (temps[0]){
                    case '+':
                    {
                        int i=pull().Ib;
                        int j=pull().Ib;
                        pushI(i+j);
                        break;
                    }
                    case '-':{
                        
                        int i=pull().Ib;
                        int j=pull().Ib;
                        pushI(i-j);
                        break;
                    }
                    case '/':{
                        
                        int i=pull().Ib;
                        int j=pull().Ib;
                        pushI(i/j);
                        break;
                    }
                    case '*':{
                        
                        int i=pull().Ib;
                        int j=pull().Ib;
                        pushI(i*j);
                        break;
                    }
                    case '=':{
                        printf("%d ",pull().Ib);
                    }
                    default :break;
                }
            }
            j=0;
        } 
        charI++;
    } while(chars[charI-1]!='\n');  
}