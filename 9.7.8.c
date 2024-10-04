#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define bool short
int roll_dice(void);
bool playgame(void);
int main(void){
    time_t time1;
    time(&time1);
    srand(time1);
    int Wi,Li;
    Wi=Li=0;
    int i = roll_dice();
    int j = roll_dice();
    if(i+j==7||i+j==11)Wi++;
    else{
        if(i+j==2||i+j==3||i+j==12)Li++;
            else{
                int goal;
                goal=i+j;
                bool Shouldcoutinue=1;
                while (Shouldcoutinue)
                {
                    i = roll_dice();
                    printf("your roll is %d\n",i);
                    printf("sum is %d\n",i);
                    j = roll_dice();
                    printf("your roll is %d\n",j);
                    printf("sum is %d\n",i+j);
                    if (i+j==goal){
                         Wi++;
                         printf("You win!!!\n");
                    }
                    else if(i+j==7){
                         Li++;
                         printf("You lose!!!\n");
                    }else printf("nothing happend\n");
                           
                    char t;
                    printf("Are you want to coutinue? y/n\n");
                    while ((t=getchar())!='\n')
                    {
                        if(t=='y'||t=='Y');
                            else{
                                Shouldcoutinue=0;
                                break;
                                 }
                    }
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                printf("WIN %d\n LOSO %d \n",Wi,Li);
                }
    }
}

int roll_dice(void){
    return rand()%6;
}
bool playgame(void){

}