// C program to generate a random integer between two numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int sup, int inf){
  int result;
  result = inf + rand() % ((sup+1)-inf);

  return result;
  }

int main(){
  srand(time(NULL));
  for(int i=0;i<20;i++){
    printf("%d\n",randint(2,16));
  }

  return 0;
}