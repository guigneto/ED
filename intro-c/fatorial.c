#include <stdio.h>

int fat(int n){
  if(n==1){
    return 1;
  } else{
    return n*(fat(n-1));
  }
}

long int fat2(int n){
  long int fat = 1;
  if((n==1) || (n==0)){
    return 1;
  }
  for(long int i=1;i<=n;i++){
    fat = fat * i;
  }
  return fat;
}

int main(void) {
  for(int i=1;i<=20;i++){
    printf("Fatorial de %2d = %20ld\n",i,fat2(i));
  }
  return 0;
}