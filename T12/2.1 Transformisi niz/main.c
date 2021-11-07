#include <stdio.h>

#define MAX_SIZE 30


void main(){
    int a[MAX_SIZE];
    int n,i,j;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz:");
    for(i = 0;i<n;i++)
    scanf("%d",&a[i]);

    for(i = 0;i<n-1;i++)
    for(j= i+1;j<n;j++)
    if(a[i]==a[j])
    {
        --n;
        for(int k =j;k<n;k++)
        a[k] = a[k+1];
        --j;

    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}