#include <stdio.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i,j;
    
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

    puts("\n\n");

    int count = 0;
    for(i=0;i<n-1;i++)
        for(j = i+1;j<n;j++)
            if(x[i]%10 == x[j]%10){
                printf("last(A[%d]) == last(A[%d]) == %d\n",i,j,x[i]%10);
                count++;
        }
    
    printf("\ncount  = %d\n",count);
}