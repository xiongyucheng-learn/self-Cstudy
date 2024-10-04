#include<stdio.h>
void sort(int,int[*]);
int main(void){
    int nums[]={2,4,6,78,8,6,45,6,78,9,7,6,4};
    int n=sizeof nums/sizeof nums[0];
    sort(n,nums);
    for (int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
}
void sort(int n,int *nums){
    if(n!=1){
        int t=nums[0];int j=0;
        for(int i=0;i<n;i++){
            if(t<nums[i]){
                t=nums[i];
                j=i;
            }
        }
        int nums2[n];
        for(int i=0;i<n;i++){
            if(i!=j){
                nums2[i]=nums[i];
            }else break;
        }
        for(int i=j+1;i<n;i++){
                nums2[i-1]=nums[i];
        }
        nums2[n-1]=t;
        for(int i=0;i<n;i++){
            nums[i]=nums2[i];
        }
        sort(n-1,nums);
    }

    
}