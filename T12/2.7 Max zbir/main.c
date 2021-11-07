#include <stdio.h>

#define MAX_SIZE 15


void main(){
    int x[MAX_SIZE];
    int n,i,j,max=0;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    puts("\n");
    for(i=0;i<n;i++)
    printf("A[%d] = %d \n",i,x[i]);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            max = (x[i]+x[j]) > max ? x[i]+x[j] : max;

    printf("%d",max);
}