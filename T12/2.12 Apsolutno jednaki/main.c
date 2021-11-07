#include <stdio.h>
#include <math.h>

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

    int count = 0;
    for(i=0;i<n-1;i++)
        for(j = i+1;j<n;j++)
            if(abs(x[i]) == abs(x[j])){
                printf("abs(A[%d]) == abs(A[%d]) == %d\n",i,j1,abs(x[i]));
                count++;
        }
    
    printf("\ncount  = %d\n",count);
}