#include <stdio.h>


void main(){
   int n;
   printf("n >> ");
   scanf("%d",&n);
   int m[n][n];
   int col1 = 0,col2 = n-1,row1 = 0,row2 = n-1,br = 1;
   while(br<= n*n){

        for(int i=col1;i<=col2;i++)
        {m[row1][i]=br++;}
        for(int j=row1+1;j<=row2;j++)
        {m[j][col2]=br++;}
        for(int i=col2-1;i>=col1;i--)
        {
            m[row2][i]=br++;
        }
        for(int j=row2-1;j>=row1+1;j--)
        {
            m[j][col1]=br++;
        }
        row1++;row2--;col1++;col2--;
   }
   for(int i=0; i<n; i++)
    {
      for(int j=0;j<n;j++)
      {
         printf("%d \t", m[i][j]);
      }
            printf("\n");
         }
}