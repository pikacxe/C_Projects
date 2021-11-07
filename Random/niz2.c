#include <stdio.h>
#include <ctype.h>



void main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int pom = 0,br=0;
    for(int i = m;i<=k/2;i++){
        pom = a[i];
        a[i] = a[k-br];
        a[k-br] = pom;
        br++;
    }
    for(int i = 0;i<n;i++){
        printf("%d",a[i]);
    }

}