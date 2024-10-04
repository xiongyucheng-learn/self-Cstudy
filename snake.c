#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define Xlength 30
#define Ylength 25
#define DEBUG 0

char chars[Xlength][Ylength+1];
int snakeL[Xlength*Ylength][2];
int len;int Fx,Fy;
int mx,my;
short moves[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void control(int *,int *);
void fruit(int *,int *);
void draw(); 
short move(short*);
short Check(short *);
int main(void){
    srand(time(NULL));
    short is_coutiune=1;
    short goal=0;
    fruit(&snakeL[0][0],&snakeL[len++][1]);
    
    
    fruit(&Fx,&Fy);
    while (is_coutiune)
    {
    //     #ifdef DEBUG
    //     static int j=0;
    //         if(j++<20){
    //     len++;
    //      }
      
    // #endif
        draw();
        is_coutiune=move(&goal);
        Sleep(200);
    }
    printf("Game over your score is %d",goal);
    scanf("%s");
}
void control(int *x,int *y){ 
    if(_kbhit()){
        char ch = getch();
        switch(ch){
            case 'w':
            case 'W':
                *x=moves[0][0];
                *y=moves[0][1];
                break;
            case 'a':
            case 'A':
                *x=moves[3][0];
                *y=moves[3][1];
                break;
            case's':
            case 'S':
                *x=moves[1][0];
                *y=moves[1][1];
                break;
            case 'd':
            case 'D':
                *x=moves[2][0];
                *y=moves[2][1];
                break;
        }
        
    }
}

void fruit(int *Tx,int *Ty){
    int x,y;
    short is_coutinue=1;
    while (is_coutinue)
    {
            x=rand()%Xlength-1;
            y=rand()%Ylength-1;
            is_coutinue=0;
            if(x<1||y<1)is_coutinue=1;
        for(int i=0;i<len;i++){
            if(x==snakeL[i][0]&&y==snakeL[i][1])
                {
                    is_coutinue=1;
                    }
        }

        /* code */
    }
    *Tx=x;
    *Ty=y;
}
void draw(){
    system("cls");
  
    memset(chars,' ',sizeof chars);
    for(int i=0;i<Xlength;i++){
        chars[i][0]='#';
        chars[i][Ylength-1]='#';
        chars[i][Ylength]='\n';
    }
     for(int j=0;j<Ylength;j++){
        chars[0][j]='#';
        chars[Xlength-1][j]='#';
        
     }
    chars[Xlength-1][Ylength]='\000';
    chars[Fx][Fy]='6';
    chars[snakeL[0][0]][snakeL[0][1]]='D';
     for(int i=1;i<len;i++){
             chars[snakeL[i][0]][snakeL[i][1]]='0';
        }

    if(chars[0][0]=='.'){
        printf("warry!!!");
        exit(-1);
    }
    printf("%s \n",chars);    
}

short move(short *goal){
    control(&mx,&my);
     int t=Check(goal);
    for(int i=len-1;i>0;i--){
        snakeL[i][0]=snakeL[i-1][0];
        snakeL[i][1]=snakeL[i-1][1];
    }
    snakeL[0][0]+=mx;
    snakeL[0][1]+=my;        
    return t;
}
short Check(short *goal){
    if(snakeL[0][0]+mx==Fx&&snakeL[0][1]+my==Fy){
        (*goal)++;
        len++;
        if(len==(Xlength-2)*(Ylength-2))
        {
             printf("you win!!!");
            exit(1);
        }
        fruit(&Fx,&Fy);
    }
    for(int i=1;i<len;i++){
        if(snakeL[0][0]+mx==snakeL[i][0]&&snakeL[0][1]+my==snakeL[i][1])
        return 0;
    }
    if(snakeL[0][0]+mx<1||snakeL[0][0]+mx>Xlength-2||snakeL[0][1]+my<1||snakeL[0][1]+my>Ylength-2)
    return 0;
    
    return 1;
}