#include <stdio.h>
#include <stdlib.h>

//doing with "bd02.txt"

int main(){

  int idade;
  float altura;
  char nome[30];
  char linhaA[512];

  FILE * arq = fopen("./arquivos/txt/bd02.txt","rt");

  fscanf(arq,"%s ,%d,%f",nome,&idade,&altura);
  
  printf("Nome: %s\nIdade: %d\nAltura: %.2f\n",nome,idade,altura);

  fclose(arq);

  return 0;
}