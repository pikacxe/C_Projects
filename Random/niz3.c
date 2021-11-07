#include <stdio.h>
#include <ctype.h>


void main(){

    int n,m,k;
    char c;
    scanf("%d %d %d %c",&n,&m,&k,&c);
    fflush(stdin);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i =m;i<k-1;i++ )
    for(int j = i+1;j<k;j++){
        if(c == 'o'){
            if(a[i] < a[j]){
                int pom  = a[i];
                a[i] = a[j];
                a[j] = pom;
            }
        }
        else if(c == 'r')
        {
            if(a[i] > a[j]){
                int pom  = a[i];
                a[i] = a[j];
                a[j] = pom;
            }
        }
        
    }

    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}