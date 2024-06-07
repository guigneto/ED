 
#include <stdio.h>
#include <stdlib.h>

int main(){

  int idade;
  float altura;
  char nome[30];

  FILE * arq = fopen("./arquivos/txt/bd01.txt","rt");

  fscanf(arq,"%s",nome);
  fscanf(arq,"%d",&idade);
  fscanf(arq,"%f",&altura);

  printf("Nome: %s\nIdade: %d\nAltura: %.2f\n",nome,idade,altura);
  
  fclose(arq);

  return 0;
}