#include<stdio.h>
#include<string.h>
int Yes_NO(char * chars,int num ){
    int np,na,nt;//PAT
            np=na=nt=0;
        int jp,jt;
        jp=jt=0;
        if (num<=2) return 0;
        for(int k=0;k<num;k++){
           
            if ((chars[k]=='P'||chars[k]=='A'||chars[k]=='T')&&np<=1&&nt<=1){
                if(chars[k]=='P')jp=k,np++;
                if(chars[k]=='A')na++;
                if(chars[k]=='T')jt=k,nt++;

            }else{
                jp=jt=0;
                return 0;
            }
        }
        if(np==1&&nt==1){
            if(jt-jp==2&&(jp==num-1-jt)) return 1;
            else if(jt-jp<2) return 0;
            else
            {
                int a,b,c;
                a=b=c=0;
                a=jp;
                b=jt-jp-2;
                c=num-a-b-1-1-1-a;
                int new_mun=a+b+c+2;
                char tempchar[new_mun];
                if(jt<jp)return 0;
                if(a<0||b<0||c<0) return 0;
                if(a)memset(tempchar,'A',(sizeof (char))*a);
                tempchar[a]='P';
                if(b)memset(tempchar+a+1,'A',sizeof(char)*(b));
                tempchar[a+b+1]='T';
                if(c)memset(tempchar+a+b+2,'A',sizeof (char)*(c));
                if(Yes_NO(tempchar,new_mun)){
                    return 1;
                }else{
                    return 0;
                }
                }
        }
        else return 0;
}
int main(void){
    int NUM=0;
    scanf("%d",&NUM);
    char chars[NUM][100];
    memset(chars,'\0',(sizeof (char))*NUM*(100));
     for(int i=0;i<NUM;i++){
        scanf("%s",chars[i]);
     }
    for(int i=0;i<NUM;i++){
        int j=0;
        for (; j <= 100&&chars[i][j]!='\0'; j++);
        if(Yes_NO(chars[i],j)){
            printf("YES\n");
        }else printf("NO\n");
        
    }
}