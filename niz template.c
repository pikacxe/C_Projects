#include <stdio.h>

#define MAX_SIZE 30


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
}