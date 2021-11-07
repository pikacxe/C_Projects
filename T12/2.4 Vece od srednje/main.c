#include <stdio.h>

#define MAX_SIZE 30


void main(){
    int x[MAX_SIZE];
    int n,i,sum=0;
    double sr = 0;
    
    do{
        printf("Unesite duzinu niza:\n");
        scanf("%d",&n);
    }while(n<=1 || n>= MAX_SIZE);

    printf("Unesite niz: ");
    for(i = 0;i<n;i++)
    scanf("%d",&x[i]);

    for(i = 0;i<n;i++){
        sum+=x[i];
    }
    sr = (double)sum/n;

    puts("Elementi veci od srednje vrednosti su:\n");
    for(i = 0;i<n;i++){
        if(x[i]>sr)
        printf("%d ",x[i]);
    }
    printf("\nSrednja vrednost niza je %.2lf",sr);
    puts("\n");
    for(i=0;i<n;i++)
    printf("%d ",x[i]);
}