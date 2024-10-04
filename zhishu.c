// #include <stdio.h>
// #include <stdlib.h>
// int NumsN=0;short Nums[1000000];

// int nextZhiShu(int a){
//     int b;int BOOL=0;
//     for(int i=1;BOOL==0;i++){
//         b=a+i;
//         BOOL=1;
//         for(int j=0;j<NumsN;j++){
//         if(b%Nums[j]==0){
//             BOOL=0;
//             break;
//         }
//         for(int k=Nums[NumsN];k*k<=b;k++){
//             if(b%k==0){
//             BOOL=0;
//             break;
//         }
//         }
//         }
//     }
//     NumsN++;
//     Nums[NumsN]=b;
//     return b;
// }
// int main(void)
// {
//   int n;int sum;int i=2;
//   scanf(" %d",&n);
//   int num=n;
//   /* code */
//     Nums[0]=2;
//     Nums[1]=3;
//     NumsN=1;
//     for(;num!=1;){
//         if(num%i==0){
//             num=num/i;
//             sum+=i;
//         }else{
//             i=nextZhiShu(i);
//         }
//     }
//     int t=NumsN;
//      for(int i=0;i<NumsN;i++)
//     {
//         printf("%d ",Nums[i]);
//     }
//     printf("\n");
//   printf("%d", sum);
//   return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// // 定义全局变量，NumsN用于记录当前质数的数量，Nums用于存储质数
// int NumsN = 0;
// int Nums[10000];
// int Nums2[10000];
// // 函数nextZhiShu用于寻找下一个质数
// int nextZhiShu(int a) {
//     int b;
//     int BOOL = 0; // BOOL用于标记是否找到质数
//     for (int i = 1; BOOL == 0; i++) {
//         b = a + i; // 从当前质数a开始，逐个尝试下一个数
//         BOOL = 1; // 假设b是质数
//         for (int j = 0; j <= NumsN; j++) {
//             if (b % Nums[j] == 0) { // 如果b能被已知的质数整除，则b不是质数
//                 BOOL = 0;
//                 break;
//             }
//         }
//         // 进一步检查b是否是质数
//         for (int k = Nums[NumsN]+1; k * k <= b; k++) {
//             if (b % k == 0) { // 如果b能被某个数整除，则b不是质数
//                 BOOL = 0;
//                 break;
//             }
//         }
//     }
//     NumsN++; // 增加质数数量
//     Nums[NumsN] = b; // 将找到的质数存入数组
//     return b; // 返回找到的质数
// }
// int main(void) {
//     // 获取当前时间戳
//     int n;
//     int sum = 0; // 用于记录消耗的热量
//     // 从2开始寻找质因数
//     scanf(" %d", &n); // 输入目标面积n
//     time_t tim1;
//     time(&tim1); 
//     int num = n; // 复制n的值，用于操作
//     // 初始化数组
//     for(int j=0;j<100;j++){
//     //         for(int i=0;i<10000;i++){
//     //         Nums[i] = 0;
//     //     }
//         memcpy(Nums,Nums2,sizeof(Nums));

//         int i = 2; 
//         num = n;
//         Nums[0] = 2;
//         NumsN = 0; // 当前质数数量为1

//         // 循环进行质因数分解，直到num变为1
//         for (; num != 1;) {
//             if (num % i == 0) { // 如果num能被当前质数i整除
//                 num = num / i; // 将num除以i
//                 sum += i; // 增加消耗的热量
//             } else {
//                 i = nextZhiShu(i); // 否则寻找下一个质数
//             }
//         }
//     }
//     // 输出所有找到的质数
//     for (int i = 0; i <= NumsN; i++) {
//         printf("%d ", Nums[i]);
//     }
//     printf("\n");
//     // 输出总消耗的热量
//     printf("%d", sum);
//     time_t tim2;
//     time(&tim2); // 获取当前时间戳
//     printf("time:%d\n", tim2 - tim1); // 输出运行时间
//     return 0;
// }


// #include <stdio.h>
// #include <math.h>
// #include <time.h>
// int min_heat_to_reach_area(int n) {
//     int heat_consumed = 0;
    
//     for (int k = 2; k * k <= n; k++) {
//         while (n % k == 0) {
//             n /= k;
//             heat_consumed += k;
//         }
//     }
    
//     if (n > 1) {
//         heat_consumed += n;
//     }
    
//     return heat_consumed;
// }

// int main() {
//     int n;int result ;
//     scanf("%d", &n);
//     time_t tim1;
//   time(&tim1); 
//     for(int j=0;j<10000;j++){
//          result=min_heat_to_reach_area(n);
//     }
//     printf("%d\n", result);
//      time_t tim2;
//     time(&tim2); // 获取当前时间戳
//     printf("time:%d\n", tim2 - tim1); // 输出运行时间
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// // 定义全局变量，NumsN用于记录当前质数的数量，Nums用于存储质数
// int NumsN = 0;
// int Nums[10000];
// // 函数nextZhiShu用于寻找下一个质数
// int nextZhiShu(int a) {
//     int b;
//     int BOOL = 0; // BOOL用于标记是否找到质数
//     for (int i = 1; BOOL == 0; i++) {
//         b = a + i; // 从当前质数a开始，逐个尝试下一个数
//         BOOL = 1; // 假设b是质数
//         for (int j = 0; j <= NumsN&&Nums[j]*Nums[j]<=b; j++) {
//             if (b % Nums[j] == 0) { // 如果b能被已知的质数整除，则b不是质数
//                 BOOL = 0;
//                 break;
//             }
//             }
    
//     }
//     NumsN++; // 增加质数数量
//     Nums[NumsN] = b; // 将找到的质数存入数组
//     return b; // 返回找到的质数
// }
// int main(void) {
//     // 获取当前时间戳
//     int n;
//     int sum = 0; // 用于记录消耗的热量
//     // 从2开始寻找质因数
//     scanf(" %d", &n); // 输入目标面积n
//     time_t tim1;
//     time(&tim1); 
//     int num = n; // 复制n的值，用于操作
//     // 初始化数组
//     for(int j=0;j<10000;j++){
//     //         for(int i=0;i<10000;i++){
//     //         Nums[i] = 0;
//     //     }
//         memset(Nums,0,sizeof(Nums));
//         int i = 2; 
//         num = n;
//         Nums[0] = 2;
//         NumsN = 0; // 当前质数数量为1

//         // 循环进行质因数分解，直到num变为1
//         for (; num != 1;) {
//             if (num % i == 0) { // 如果num能被当前质数i整除
//                 num = num / i; // 将num除以i
//                 sum += i; // 增加消耗的热量
//             } else {
//                 i = nextZhiShu(i); // 否则寻找下一个质数
//             }
//         }
//     }
//     // 输出所有找到的质数
//     // for (int i = 0; i <= NumsN; i++) {
//     //     printf("%d ", Nums[i]);
//     // }
//     printf("\n");
//     // 输出总消耗的热量
//     printf("%d", sum);
//     time_t tim2;
//     time(&tim2); // 获取当前时间戳
//     printf("time:%d\n", tim2 - tim1); // 输出运行时间
//     return 0;
// }