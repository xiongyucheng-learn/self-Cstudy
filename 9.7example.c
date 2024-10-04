#include<stdio.h>
#define Nmiddle(a,c,d) _Generic(a,float*:Fmiddle,default:Imiddle)(a,c,d)
int Imiddle(int *, int, int);
int Fmiddle(float *, int, int);
int main(void){
    int I[]={1,2,3,4,5,2,20,6,7,8};
    int i=1;
    float F[]={1,2,3,4,5,2,20,6,7,8};
    printf("%d",_Generic(++i,float*:Fmiddle,default:Imiddle)(I,0,9) );
    printf("\n%d",i++);
    printf("\n%d",i);
    return 0; 
}//该处理为预处理阶段，不会计算表达式的值比如++i不会进行计算，只会获取类型
int Fmiddle( float *nums, int i, int j) {
  float t = nums[i];
  short BOOL = 1;
  while (BOOL) {
    while (BOOL)
    {
      if (i == j) {
        BOOL = 0;
        break;
      } else {
        if (nums[j] < t) {
          int b = nums[i];
          nums[i] = nums[j];
          nums[j] = b;
          break;
        }else{
            j--;
        }
      }
    }
    while (BOOL)
    {
      if (i == j) {
        BOOL = 0;
        break;
      }else{
        if (nums[i] > t) {
        int b = nums[i];
        nums[i] = nums[j];
        nums[j] = b;
        break;
      }else{
        i++;
      }
      }
    }
  }
nums[i]=t;
return i;
}

int Imiddle( int *nums, int i, int j) {
  int t = nums[i];
  short BOOL = 1;
  while (BOOL) {
    while (BOOL)
    {
      if (i == j) {
        BOOL = 0;
        break;
      } else {
        if (nums[j] < t) {
          int b = nums[i];
          nums[i] = nums[j];
          nums[j] = b;
          break;
        }else{
            j--;
        }
      }
    }
    while (BOOL)
    {
      if (i == j) {
        BOOL = 0;
        break;
      }else{
        if (nums[i] > t) {
        int b = nums[i];
        nums[i] = nums[j];
        nums[j] = b;
        break;
      }else{
        i++;
      }
      }
    }
  }
nums[i]=t;
return 1;
}