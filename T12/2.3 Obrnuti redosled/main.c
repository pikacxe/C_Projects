#include <stdio.h>

#define MAX_SIZE 30


void main(){
    int x[MAX_SIZE];
    int n,i,br;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz:");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    br=n-1;
    for(i = 0;i<n/2;i++){
        int pom = x[i];
        x[i] = x[br];
        x[br--] = pom;
    }

    puts("\n");
    for(i=0;i<n;i++)
    printf("%d ",x[i]);
}