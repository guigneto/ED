#include <stdio.h>
#include <stdlib.h>

int main(){

  int x = 15, *px = &x;
  //*px/5 <==> x/5
  printf("%d",*px/5);

  return 0;
}
