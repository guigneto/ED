 #include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arq = fopen("./arquivos/txt/dados01.txt","at");

  fputs("\nESTRUTURA DE DADOS",arq);

  fclose(arq);

  return 0;
}
