/*真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天
真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天真的逆天*/

#include<stdio.h>
#include<stdlib.h>
int tobe(int ,long long ,int);

long long mod_exp(int a, int b, int mod);
int main(void){
  int is_coutiune=1;
  //srand(time(NULL));
  //do{
        long long a;
           long long b;
           long long c;
         // int b,c;
          scanf("%lld",&a);
          scanf("%lld",&b);
          scanf("%lld",&c);
          long long tens=1;
          //printf("%ld\n",a);
          //printf("%ld\n",b);
          //printf("%ld\n",c);
          // a=rand();
          // b=rand();
          // c=rand()%5+1;
          // printf("%d %d %d\n",a,b,c);
          for(int i=1;i<=c;i++)
          tens*=10;
          int j=0;
          const int A=a;
          
          //b=10000;
          long long result = mod_exp(a, b, tens); 
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
          //printf("%d\n",result);


        return 0;
          //if(a!=result){
          //  is_coutiune=0;
          //}
          //Sleep(100);
 // }while(is_coutiune);
  
  

}

int tobe(int A,long long  a,int c){
  long long temp; 
  
  temp=a;int nums[c];
 // printf("%ld\n",temp);
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
 // printf("%ld\n",temp);
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



long long mod_exp(int a, int b, int mod) {
    long long result = 1;
    a = a % mod; // 先对 a 取模
    while (b > 0) {
        // 如果 b 是奇数，乘以 a
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        // b 右移一位，即 b = b / 2
        b = b >> 1;
        // a 自身平方并对 mod 取模
        a = (a * a) % mod;
    }
    return result;
}

