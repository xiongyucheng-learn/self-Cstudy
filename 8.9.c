#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<windows.h>
#define N 10
int main(void) {
  char a[N][N];
  char Chars[26];
  int c[4] ;
  const int d[4] = {-1,-1,-1,-1};
  int n = 0;
  const int move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  time_t time1;
  time(&time1);
  srand(time1);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) a[i][j] = '.';
  for (int i = 0; i < 26; i++) Chars[i] = 'A' + i;
  int t;
  int i = 0;
  int j = 0;
  int k=0;
  memcpy(c,d,sizeof(c));
  /*88888888888888888888888*/
  for (;n<26;) {
    t = rand()%4;
    a[i][j]=Chars[n++];
    switch(t){
    case 1: if(i-1<0||a[i-1][j]!='.'){
            n--;
            c[0]=1;
        }
            else{
                i--;
                memcpy(c,d,sizeof(c));

            }
            break;
    case 2: if(j+1>N-1||a[i][j+1]!='.')
               {
            n--;
            c[1]=1;
        }
            else{
                j++;
                 memcpy(c,d,sizeof(c));
            }
            break;
    case 3: if(i+1>N-1||a[i+1][j]!='.')
               {
            n--;
            c[2]=1;
        }
            else{
                i++;
                 memcpy(c,d,sizeof(c));
            }
            break;
    case 0: if(j-1<0||a[i][j-1]!='.')
               {
            n--;
            c[3]=1;
        }
            else{
                j--;
                 memcpy(c,d,sizeof(c));
            }
            break;
    }

    if(c[0]+c[1]+c[2]+c[3]==4)break;
  }


  /*88888888888888888888888*/
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) printf("%3c", a[i][j]);
    putchar('\n');
  }
  return 0;
}
// switch(t){
//     case 1: if(i-1<0||a[i-1][j]!='.'){
//             n--;
//             c[0]=1;
//         }
//             else{
//                 i--;
//                 memcpy(c,d,sizeof(c));

//             }
//             break;
//     case 2: if(j+1>N-1||a[i][j+1]!='.')
//                {
//             n--;
//             c[1]=1;
//         }
//             else{
//                 j++;
//                  memcpy(c,d,sizeof(c));
//             }
//             break;
//     case 3: if(i+1>N-1||a[i+1][j]!='.')
//                {
//             n--;
//             c[2]=1;
//         }
//             else{
//                 i++;
//                  memcpy(c,d,sizeof(c));
//             }
//             break;
//     case 0: if(j-1<0||a[i][j-1]!='.')
//                {
//             n--;
//             c[3]=1;
//         }
//             else{
//                 j--;
//                  memcpy(c,d,sizeof(c));
//             }
//             break;
// }