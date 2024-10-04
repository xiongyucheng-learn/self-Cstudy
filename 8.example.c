//快排

#include <stdio.h>
#include <stdlib.h>
int middle(int *, int, int);
void sort( int *, int, int);
int main(void) {
    int a[] = {1,2,3,4,5,6,7,8,9,0};
   sort(a,0,(sizeof a / sizeof a[0]) - 1);
    for(int i=0;i<(sizeof a / sizeof a[0]);i++){
      printf("%d ",a[i]);
    }
  return 0;
}
void sort( int *nums, int i, int j){
  // if(j-i>=2){
  //   int t=middle( nums, i, j);
  //   if(t-i<2&&j-t<2) return;
  //   if(t-i>=2){
  //     sort(nums,i,t);
  //   }
  //   if(j-t>=2){
  //     sort(nums,t,j);
  //   }
    
  // }else{
  //   return;
  // }
    int t=middle(nums,i,j);
    if(t-i>=2){
      sort(nums,i,t-1);
    }
    if(j-t>=2){
      sort(nums,t+1,j);
    }
    if(t-i<2&&j-t<2) return;
}
int middle( int *nums, int i, int j) {
  int t = nums[i];
  short BOOL = 1;
  while (BOOL) {
    for (; BOOL!=0;) {
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
    for (; BOOL!=0;) {
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

/*  
  1.送礼要把价格撕掉
  2.在确定是真心朋友前不要说秘密
  3.长辈先动筷
  4，转盘顺时针
  5.座位次序  面门最大，被门其次，最大左右为重要客人，十字区域为次要客人，四角为可坐位置
  6.不能喝酒就不喝，在外第一次就要假装喝醉
*/
