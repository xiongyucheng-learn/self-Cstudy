#include<stdio.h>
#include<string.h>
int main(void){
    int max,min,NUM;
    char max_Name[11],min_Name[11],min_ID[11],max_ID[11];
    memset(max_ID,'\0',sizeof max_ID);
    memset(min_ID,'\0',sizeof min_ID);
    memset(max_Name,'\0',sizeof max_Name);
    memset(min_Name,'\0',sizeof min_Name);
    scanf("%d",&NUM);
    char temp_Name[11],temp_ID[11];
    int temp;
     memset(temp_Name,'\0',sizeof temp_Name);
    memset(temp_ID,'\0',sizeof temp_ID);
    temp=0;
    scanf("%s %s %d",temp_Name,temp_ID,&temp);
    max=temp;
    memcpy(max_Name,temp_Name,sizeof temp_Name);
    memcpy(max_ID,temp_ID,sizeof temp_ID);
    min=temp;
            memcpy(min_Name,temp_Name,sizeof temp_Name);
            memcpy(min_ID,temp_ID,sizeof temp_ID);
    for(int i=1;i<NUM;i++){

        scanf("%s %s %d",temp_Name,temp_ID,&temp);
        if(temp>max){
            max=temp;
            memcpy(max_Name,temp_Name,sizeof temp_Name);
            memcpy(max_ID,temp_ID,sizeof temp_ID);
        }else if(temp<min){
            min=temp;
            memcpy(min_Name,temp_Name,sizeof temp_Name);
            memcpy(min_ID,temp_ID,sizeof temp_ID);
        }
    }

    printf("%s %s\n",max_Name,max_ID);
    printf("%s %s\n",min_Name,min_ID);
    
}