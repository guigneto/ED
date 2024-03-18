#include <stdio.h>
#include <stdlib.h>

/*
-abrir: fopen()
-fechar: fclose()
-checar fim: feof()
-escrever: fprintf()
-ler: fscanf()
      fgets()
*/

int main(){

  FILE * arq;
  arq = fopen("./arquivos/txt/dados01.txt","wt");

  int i = 250;
  float f = 23.7865;
  char s[10] = "Hello";

  fprintf(arq,"%d\n%.4f\n%s\n",i,f,s);
  fputs("MAIS UMA STRING",arq);
  
  fclose(arq);
  
  return 0;
}