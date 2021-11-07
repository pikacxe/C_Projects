#include <stdio.h>




int main(){
    int n,pom;
    puts("Unesite dimenzije matrice:");
    scanf("%d",&n);
    int **mat;


    for(int i=0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int i=0;i<n;i++)
        for(int j = i;j<n;j++)
            {
                pom  = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = pom;
            }

    puts("\n");
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++)
        printf("%d ",mat[i][j]);
        puts("\n");
    }
    return 0;
}