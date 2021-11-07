#include <stdio.h>

#define MAX_SIZE 10


void main(){
    int x[MAX_SIZE];
    int n,i,a;
    
    do{
        printf("Unesite duzinu niza (MAX:%d):\n",MAX_SIZE);
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    puts("x = ");
    scanf("%d",&a);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    puts("\n");
    for(i=0;i<n;i++)
    printf("A[%d] = %d \n",i,x[i]);

    puts("\n\n");
    int sum = 0,count = 0,check = 1;
    for(i=n-1;i>=0;i--){
        sum +=x[i];
        printf("sum(A[%d]) = %d\n",i,sum);
        if(sum>a && check){
            count = n-i;
            check = 0;
        }
    }
    printf("count  = %d",count);
}