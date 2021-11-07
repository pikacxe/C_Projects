#include <stdio.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i,j;
    
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

    int count = 0;
    puts("\n\n");
    for(i=0;i<n-1;i++)
        if((x[i]%2==1) && (x[i+1]%2==1)){
                printf("odd(A[%d]) == odd(A[%d]) == 1 \n",i,i+1);
                count++;
            }
    printf("count  = %d",count);
}