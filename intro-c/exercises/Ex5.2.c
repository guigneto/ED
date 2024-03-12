#include <stdio.h>

int main(){

    int w[9];
    int i = 5;

    w[0] = 17; //0 - 17
    w[i/2] = 9; // 2.5 -- Error
    w[2*i-2] = 95; // 8 - 95
    w[i-1] = w[8]/2;// 4 - 47
    w[i] = w[2]; // 5 - 0 ??
    w[i+1] = w[i]+w[-1];// 6 - 47 ??
    w[w[2]-2] = 78; //???
    w[w[i]-1] = w[1]*w[i]; // ?!!!?!

    for(int j=0;j<10;j++){
        printf("%d - %d\n",j,w[j]);
    }

    return 0;
}