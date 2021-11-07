#include <stdio.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i;
    
    do{
        printf("Unesite duzinu niza (MAX:%d): ",MAX_SIZE);
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    puts("\n");
    for(i=0;i<n;i++)
    printf("A[%d] = %d \n",i,x[i]);
    puts("\n");

    double sr = 0;
    int br = 0;
    for(i=0;i<n;i+=2){
        sr+=x[i];
        br++;
    }
    sr = sr/br;
    printf("AS = %.2lf",sr);
}