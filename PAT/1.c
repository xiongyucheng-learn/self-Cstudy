#include<stdio.h>
int main(void){
    int a,b;
    float c,d;
    double e,f;
    scanf("%d %d",&a,&b);
    scanf("%f %f",&c,&d);
    scanf("%lf %lf",&e,&f);
    printf("%d \n",a+b);
    printf("%f \n",c+d);
    printf("%lf \n",e+f);
}