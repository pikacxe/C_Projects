#include <stdio.h>

#define MAX_SIZE 15


int zbir(int a){
    int prva = a / 10;
    int druga = a % 10;
    return (prva * prva) + (druga * druga);
}

void main(){
    int x[MAX_SIZE];
    int n,i,j;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%2d",&x[i]);

    puts("\n");
    for(i=0;i<n;i++)
    printf("A[%d] = %d \n",i,x[i]);
    for(i=0;i<n;i++)
    printf("zbir(A[%d]) = %d \n",i,zbir(x[i]));

    int count = 0;
    puts("\n");
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(zbir(x[i])==zbir(x[j])){
                printf("zbir(A[%d]) == zbir(A[%d]) = %d \n",i,j,zbir(x[i]));
                count++;
            }
            printf("\ncount = %d",count);
}