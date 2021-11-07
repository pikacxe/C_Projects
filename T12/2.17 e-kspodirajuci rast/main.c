#include <stdio.h>

double fakt(double n){
    if(n<1)return 1;
    return n*fakt(n-1);
}


void main(){
    int n,i;
    do{
        printf("Unesite broj clanova reda: ");
        scanf("%d",&n);
    }while(n<1);

    double sum=0;
    for(i = 0;i<n;i++)
    {
        double clan= 1/fakt(i);
        printf("clan[i=%d] = %lf\n",i,clan);
        sum+=clan;
    }

    printf("e = %lf",sum);
}