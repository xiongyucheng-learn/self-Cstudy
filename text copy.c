/*真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天*/

#include<stdio.h>
#include<stdlib.h>
long long tobe(int ,long long ,int);
int main(void){
  int is_coutiune=1;
          long long  a;
          long long b;
          long long c;
          scanf("%lld %lld %lld",&a,&b,&c);
          long long tens=1;
          for(int i=1;i<=c;i++)
          tens*=10;
          int j=0;
          const int A=a;
         if(b==1){
          a=tobe(1,a,c);
         }else{
          while (j++<b-2)
          {
            if(a<tens){
              a*=A;
            }else{
              a=tobe(A,a,c);
            }
          }
          a=tobe(A,a,c);
         } 
          printf("%d\n",a);
        return 0;
}

long long  tobe(int A,long long  a,int c){
  long long temp; 
  
  temp=a;int nums[c];
  /*                */
  for(int i=0;i<c;i++){
    nums[i]=temp-(temp/10)*10;
    temp/=10;
  }
  temp=0;
  for(int i=c-1;i>=0;i--){
    temp+=nums[i];
    temp*=10;
  }
  temp/=10;
  /*                */
  temp*=A;
  for(int i=0;i<c;i++){
    nums[i]=temp-(temp/10)*10;
    temp/=10;
  }
  temp=0;
  for(int i=c-1;i>=0;i--){
    temp+=nums[i];
    temp*=10;
  }
  return temp/10;
}