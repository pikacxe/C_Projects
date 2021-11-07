#include <stdlib.h>
#include <stdio.h>


int main(){

    int n,m;
    printf("Unesite dimenzije matrice:\n");
    scanf("%d %d",&m,&n);

    int mat[m][n];

    int i,j,sum=0;
    printf("Unesite matricu:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
            if(i % 2==0 && j%2==1){
                sum+= mat[i][j];
            }
        }
    }
    printf("Sume elemenata sa parnim redovima i neparnim kolonama je: %d",sum);

    return 0;
}