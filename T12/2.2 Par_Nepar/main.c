#include <stdio.h>

#define MAX_SIZE 50


void main(){
    int x[MAX_SIZE],a[MAX_SIZE],b[MAX_SIZE/2];
    int n,i,br1=0,br2=0;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz:");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    for(i = 0;i<n;i++)
        if(a[i] %2==0){
            a[br1++] = x[i];
        }
        if(i % 2 ==0){
            a[br2++] = x[i];
        }


    for(i=0;i<br1;i++)
    printf("%d ",a[i]);
    for(i=0;i<br2;i++)
    printf("%d ",b[i]);
}