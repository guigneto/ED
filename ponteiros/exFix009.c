#include <stdio.h>

int main(){

  int i = 3, j=5;
  int *p = &i, *q = &j;

  printf("a) %d\n", p==&i);
  printf("b) %d\n",*p-*q); // *p é i
  printf("c) %d\n",**&p); // dir -> esq, &p = endereço de p; *&p = p; **&p = i
  

  return 0;
}