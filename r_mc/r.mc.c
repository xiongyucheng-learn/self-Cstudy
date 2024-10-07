#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define Xlength 21
#define Ylength 12

const int l_index[][2]={{0,0},{0,1},{0,2},{0,3}};
const int rL_index[][2]={{-1,0},{0,0},{1,0},{2,0}};
const int lL_index[][2]={{0,0},{0,1},{0,2},{-1,3}};
const int mc_index[][2]={{-1,0},{-1,1},{0,0},{0,1}};
const int lS_index[][2]={{0,0},{0,1},{-1,1},{-1,2}};
const int T_index[][2]={{0,0},{0,1},{-1,1},{0,2}};
const int rS_index[][2]={{-1,0},{-1,1},{0,1},{0,2}};
char preDraws[Xlength][Ylength+1];
char Draws[Xlength][Ylength+1];
char Draws_mc[Xlength][Ylength+1];
char Save_mcs[Xlength][Ylength+1];
void Rands(int *);
int preDraw();
int Draw();
int mc_create();
int control();
int move(int **);
int main(void){
    ;
}

int preDraw(){
    memset(Draws,' ',sizeof Draws);
    for(int i=0;i<Xlength;i++){
        Draws[i][0]='#';
        Draws[i][Ylength-1]='#';
        Draws[i][Ylength]='\n';
    }
     for(int j=0;j<Ylength;j++){
        Draws[Xlength-1][j]='#';   
     }
    Draws[Xlength-1][Ylength]='\000';
}

int Draw(){
    memcpy(Draws,preDraws,sizeof Draws);

    for(int i=0;i<Xlength-1;i++)
        for(int j=1;j<Ylength-1;j++)
        {
            if(Save_mcs[i][j]=='0')temp[i][j]=Save_mcs[i][j];
        }



     printf("%s" ,temp);
}

int control(){ 
    static movec=1;
    if(_kbhit()){
        char ch = getch();
        switch(ch){
            case 'a':
            case 'A':
                return movec=0;
                break;
            case's':
            case 'S':
                return movec=1;
                break;
            case 'd':
            case 'D':
                return movec=3;
                break;
            case ' ':
                return movec=4;
                break;
            default :
             return movec;
        }
    }
    return movec;

}
void Rands(int *mcs){
    int sum=0;
    int t=0;
    int BOOL1=1;
    while (1)
    {  
        BOOL1=1;
        t=rand()%7;
        for(int i=0;i<sum;i++)
        {
            if(t==mcs[i]){
                BOOL1=0;
                break;
            }
        }
        if(BOOL1)mcs[sum++]=t;
        if(sum==7)break;
    }
    
}
int move(int ** mcs_index){
    int is_coutiune=1;
    int mcs[7]={0};
    while (1)
    {
        Rands(mcs);

        for(int i=0;i<7;i++){
            





        }
        /* code */
    }
    

}