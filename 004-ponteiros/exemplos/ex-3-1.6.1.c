#include <stdio.h>
#include <stdlib.h>


int main(){

    int a = 2, *ptr1 = NULL;
    float r = 3.25, *ptr2 = NULL;

    printf("Antes de apontar\n");
    printf("a = %d\n",a);
    printf("r = %f\n",r);
    printf("ptr1 = %p (hexadecimal), %lu (decimal)\n",ptr1,(unsigned long)ptr2);
    printf("ptr2 = %p (hexadecimal), %lu (decimal)\n",ptr2, (unsigned long)ptr2);

    ptr1 = &a;
    ptr2 = &r;

    printf("Depois de apontar\n");
    printf("a = %d\n",a);
    printf("r = %f\n",r);

    printf("ptr1 = endereco de a = %p (hexadecima), %lu (decimal)\n",ptr1, (unsigned long)ptr1);
    printf("ptr2 = endereco de r = %p (hexadecimal), %lu (decimal)\n",ptr2,(unsigned long)ptr2);

    return 0;
}