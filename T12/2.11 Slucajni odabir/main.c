#include <stdio.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i,a;
    
    do{
        printf("Unesite duzinu niza (MAX:%d): ",MAX_SIZE);
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("x = ");
    scanf("%d",&a);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    puts("\n");
    for(i=0;i<n;i++)
    printf("A[%d] = %d \n",i,x[i]);

    puts("\n\n");
    double chance = 0;
    int br = 0;
    for(i = 0;i<n;i++)
        if(x[i]==a){
            printf("found(A[%d]) == %d\n",i,x[i]);
            br++;
        }
    chance = (double)br/n;

    printf("chance  = %.3lf",chance);
}