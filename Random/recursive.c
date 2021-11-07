#include <stdio.h>

#define RANGE 50

int f(int n){
    if(n <= 1){
        return n;
    }
    return n+ f(n-1);

}

void main(){
    printf("%d",f(5));
}