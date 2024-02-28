 
#include <stdio.h>
#include <math.h>

long int fatorial(int n){
    long int fat = 1;
    if((n==1) || (n==0)){
    return 1;
    }
    for(long int i=1;i<=n;i++){
        fat = fat * i;
    }
    return fat;
}

int main(){

    

    return 0;
}