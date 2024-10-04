//快排,改进
#include <stdio.h>
#include <stdlib.h>
int middle(int *, int, int);
int middleAIchange(int *, int, int);
void sort( int *, int, int);
int main(void) {
    int a[] = {9,10,7,15,3,6,16,12,13};
   sort(a,0,(sizeof a / sizeof a[0]) - 1);
    for(int i=0;i<(sizeof a / sizeof a[0]);i++){
      printf("%d ",a[i]);
    }
  return 0;
}
void sort( int *nums, int i, int j){
    int t=middleAIchange(nums,i,j);
    if(t-i>=2){
      sort(nums,i,t-1);
    }
    if(j-t>=2){
      sort(nums,t+1,j);
    }
    if(t-i<2&&j-t<2) return;
}
int middleAIchange(int *nums,int i,int j){
   int pivot = nums[i];
    short shouldContinue = 1;
    while (shouldContinue) {
        while (i < j && nums[j] >= pivot) {
            j--;
        }
        if (i < j) {
            nums[i++] = nums[j];
        } else {
            shouldContinue = 0;
            break;
        }

        while (i < j && nums[i] <= pivot) {
            i++;
        }
        if (i < j) {
            nums[j--] = nums[i];
        } else {
            shouldContinue = 0; 
        }
    } 
    nums[i] = pivot;
    return i;
}
int middle( int *nums, int i, int j) {
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
return i;
}
int split(int *num,int i,int j)
{
  int t=num[i];
  for(;;){
    while(i<j&&t<=num[j]){
      j--;
    }
    if(i>=j)break;
    num[i++]=num[j];
    while (i<j&&num[i]<=t)
    {
      i++;
      /* code */
    }
    if(i>=j)break;
    num[j--]=num[i];
  }
  num[j]=t;
  return j;
}
/*  
  1.送礼要把价格撕掉，特产
  2.在确定是真心朋友前不要说秘密
  3.长辈先动筷
  4，转盘顺时针
  5.座位次序  面门最大，被门其次，最大左右为重要客人，十字区域为次要客人，四角为可坐位置
  6.不能喝酒就不喝，在外第一次就要假装喝醉
*/
