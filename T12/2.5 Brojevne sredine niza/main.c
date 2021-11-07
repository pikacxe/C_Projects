#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i,as_br=0;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    puts("\n");
    for(i=n-1;i>=0;i--)
    printf("A[%d] = %d \n",i,x[i]);

    double ks=0,as=0,pom=0;
    for(i=0;i<n;i++){
        pom+= x[i]*x[i];
    }
    ks = sqrt(pom/n);
    pom=0;
    for(i=1;i<n;i+=2){
        pom+= x[i];
        as_br++;
    }
    as = pom/as_br;
    printf("KS = %.2lf\nAS = %.2lf",ks,as);
}