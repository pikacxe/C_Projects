#include <stdio.h>
#include <ctype.h>

void main(){

    int n,b,m,k,j=0;
    scanf("%d %d %d %d",&n,&b,&m,&k);
    int a[n],c[n+m];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        if(i ==k){
            for(j =0;j<m;j++)
                c[i+j] = b;
            j--;
        }
        else
        {
           c[i+j] = a[i]; 
        }
        
    }
    for(int i = 0;i<n+m;i++){
        printf("%d",c[i]);
    }
}