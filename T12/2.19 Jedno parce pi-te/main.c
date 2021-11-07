#include <stdio.h>
#include <math.h>

void main(){
    int n,i;
    do{
        printf("Unesite broj clanova reda: ");
        scanf("%d",&n);
    }while(n<1);

    double sum=0;
    for(i = 1;i<=n;i++)
    {
        double clan = (double)1/pow(2*i - 1, 2);
        printf("clan[i=%d] = %lf\n",i,clan);
        sum +=clan;
    }
    double pi = sqrt(8*sum);
    printf("sum = %lf \npi = %lf",sum,pi);
}