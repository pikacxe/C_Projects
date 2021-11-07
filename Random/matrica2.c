#include <stdio.h>
#include <stdlib.h>

#define d 3
 
void Unos_second(int a[][d],int i,int j){
    if(j>d)return;
    scanf("%d",&a[i][j]);
    Unos_second(a,i+1,j+1);

}

void Unos(int a[][d]){
    int j = 0,i=0;
    Unos_second(a,i,j);
}



void main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][d];
    /*for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
        scanf("%d",&a[i][j]);
    }*/
    Unos(a);
    printf("\n\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }


}