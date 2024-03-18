#include <stdio.h>
#include <stdlib.h>

//doing with "bd02.txt"
//gets --> uma linha
//

int main(){

  int idade;
  float altura;
  char nome[30];
  char linhaA[512];

  FILE * arq = fopen("./arquivos/txt/bd02.txt","rt");

  fgets(linhaA,100,arq);
  sscanf(linhaA,"%s ,%d,%f",nome,&idade,&altura);

  puts(linhaA);
  printf("%s\n%d\n%.2f\n",nome,idade,altura);

  fclose(arq);

  return 0;
}