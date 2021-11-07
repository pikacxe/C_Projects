#include <stdio.h>


int faktoriel(int n){
    if(n <=1){
        return n;
    }
    return n*faktoriel(n-1);
}

void main(){

    printf("%d", faktoriel(3));
}