 #include <stdio.h>

 void troca(int* a,int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
 }

 int main(){

    int x = 5;
    int y = 3;
    printf("x = %d\ny = %d\n",x,y);
    int *px = &x;
    int *py = &y;
    troca(px,py);
    printf("TROCA\n");
    printf("x = %d\ny = %d",x,y);

    return 0;
 }