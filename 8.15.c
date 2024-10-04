#include<stdio.h>
int main(void){
    char says[80];
    int i=0;
    int n;
    while ((says[i]=getchar())!='\n')i++;
    scanf("%d",&n);
    
    for(int j=0;j<=i;j++){
        if((says[j]>='a')&&(says[j]<='z')){
            says[j]=(says[j]-'a'+n)%26+'a';
            
        }else if(says[j]>='A'&&says[j]<='Z'){
                says[j]=(says[j]-'A'+n)%26+'A';
        }
    }
    for(int k=0;k<=i;k++)
        putchar(says[k]);
}