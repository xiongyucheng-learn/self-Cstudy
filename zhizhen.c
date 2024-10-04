#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBUG 1
#ifdef DEBUG
#define XLENGTH 10
#define YLENGTH 15

#endif
int main(void){
    // int *a;
    // a=(int *)malloc((sizeof (int))*LENGTH );
    // for(int i=0;i<LENGTH;i++){
    //     a[i]=i;
    // }12d
    // for(int i=0;i<LENGTH;i++){
    //     printf("%d ",a[i]);
    // }



    //  int a[LENGTH][LENGTH];
    //     memset(a,-1,sizeof a );


    // int *b;
    // b=a[0];
    // for(;b<=&a[LENGTH-1][LENGTH-1];b++)
    //     *b=0;
    
    



    //    for(int i=0;i<LENGTH;i++){
    //     for(int j=0; j<LENGTH;j++)
    //      printf("%d ",a[i][j]);

    //     printf("\n");
    //     }

//      int a[XLENGTH][YLENGTH];
//          memset(a,-1,sizeof a );
//     int *p;
//    // p=*(a+3)+3;
//     int (*d)[15][20];
//     for(p=*a+3;p<&a[XLENGTH-1][YLENGTH];p++){
//         *p=0;
//     }
//     memset(a,-1,sizeof a );
//     int (*c)[YLENGTH];

//     c=&a[0];
//     for(;c<&a[XLENGTH];c++){
//         (*c)[3]=6;
//     }
//     int f[XLENGTH][YLENGTH][20];
//     d=f;
//     //d[8][9]==*(d[8]+9)==*(*(d+8)+9)
//     (*d)[8][9]=0;
    
/*
    int a[0][j];
    &*(a[0]+j)=&*(*(a+0)+j)=*(a+0)+j
    &a[i][0]=&*(a[i]+0)=&*(*(a+i)+0)=*(a+i)+0
    a[0]==*(a+0)
    &a[0][0]==&*(a[0]+0)==&*(*(a+0)+0)=




*/



//   for(int i=0;i<XLENGTH;i++){
//         for(int j=0; j<YLENGTH;j++)
//          printf("%d ",a[i][j]);
//         printf("\n");
//         }

int a[XLENGTH][YLENGTH];
memset(a,-1,sizeof a);


int (*p)[YLENGTH];
for(p=a;p<a+YLENGTH;p++){
    (*p)[2]=0;
}
// p=a;
// while (p<a+XLENGTH)
// {
//     *(p++)[2]=0;
//     /* code */
// }
/*
    (*p)[2]==*((*p)+2)

    *p[2]==*(*(p+2))

*/

  for(int i=0;i<XLENGTH;i++){
        for(int j=0; j<YLENGTH;j++)
         printf("%d ",a[i][j]);
        printf("\n");
        }

}