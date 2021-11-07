#include <stdio.h>


void main(){
    int n,i;
    do{
        printf("Unesite broj clanova reda: ");
        scanf("%d",&n);
    }while(n<=0);

    double sum=0;
    for(i = 0;i<n;i++)
    {
        double pom = 0;
        printf("clan[i=%d] = ",i);
        scanf("%lf",&pom);
        sum+= (double)1/((i+1)*(i+2));
    }

    printf("sum = %lf",sum);

}