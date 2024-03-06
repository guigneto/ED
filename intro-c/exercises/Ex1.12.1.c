#include <stdio.h>
#include <stdlib.h>

int main() {
  int continua = 0,idade = 0,soma = 0,media = 0,count = 0;

  while(continua==0){
    printf("Digite uma idade: ");
    scanf("%d",&idade);
    soma+=idade;
    if(idade == 0){
      continua++;
    }
    count++;
  }
  
  media = soma/(count-1);
  printf("Media das idades: %d\n",media);
  
  return 0;
}
