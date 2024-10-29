

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int to_int(char *chars,int size){
    int temp=0;
    bool fu=0;
    for(int i=0;i<size;i++){
        if(chars[i]=='-')fu=1;
        else{
             temp+=(chars[i]-'0')*pow(10,size-i-1);
        }
       
    }
    
    return fu?-temp:temp;
}
int main(void){
    int zhishu1,dishu1,zhishu2,dishu2;
    int t;bool BOOL=0;bool is_coutiune=1;
    char num_temp[5];int num_temp_j=0;
    bool is_first=0;
    char chars[1000]={};int chars_j=0;
    fgets(chars,1000,stdin);//
    int temp_num=0;

     while (t=chars[chars_j++])
    {   
            if(t==' '){
                if(BOOL==0)
                {
                    dishu1=to_int(num_temp,num_temp_j);
                    BOOL=1;
                }
                else{
                    zhishu1=to_int(num_temp,num_temp_j);
                    dishu2=dishu1*zhishu1;
                    zhishu2=zhishu1-1;
                    if(dishu2!=0){
                        if(is_coutiune!=0&&is_first)printf(" ");
                        is_first=1;
                        printf("%d %d",dishu2,zhishu2);
                        }
                    BOOL=0;
                }
                num_temp_j=0;
            }else{
                if(t=='\0'){
                    break;
                }
                num_temp[num_temp_j++]=t;
            }
            
        /* code */
    }
    
    if(is_first==0)printf("0 0");
    return 0;
}

// while (scanf("%d",&temp_num)!=0)
//     {
//                 if(BOOL==0)
//                 {
//                     dishu1=temp_num;
//                     BOOL=1;
//                 }
//                 else{
//                     zhishu1=temp_num;
//                     dishu2=dishu1*zhishu1;
//                     zhishu2=zhishu1-1;
//                     if(dishu2!=0){
//                         if(is_coutiune!=0&&is_first)printf(" ");
//                         is_first=1;
//                         printf("%d %d",dishu2,zhishu2);
//                         }
//                     BOOL=0;
//                 }
//         /* code */
//     }
    

 