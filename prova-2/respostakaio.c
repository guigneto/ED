#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char cep[9];
  char nmr_casa[4];
  char nome_familia[15];
} t_endereco1;

typedef struct {
  char cep[9];
  Lista endereco;
} t_endereco2;

t_endereco1 *linhaPRAstruct(char *str) {
  t_endereco1 *p = (t_endereco1 *)malloc(sizeof(t_endereco1));
  const char s[2] = ",";
  char *token;

  token = strtok(str, s);
  strcpy(p->cep, token);

  token = strtok(NULL, s);
  strcpy(p->nmr_casa, token);

  token = strtok(NULL, s);
  strcpy(p->nome_familia, token);

  return p;
}

char *strip(char *s) {
  int ultimo = strlen(s) - 1;
  s[ultimo] = '\0';
  return s;
}

int in(Lista l, char *s) {
  char aux[9];
  for (int i = 0; i < lenLista(l); i++) {
    t_endereco1 *elemento = elemLista(l, i);
    strcpy(aux, elemento->cep);
    if (strcmp(aux, s) == 0)
      return 1;
  }
  return 0;
}

Lista loadbdceps(char *nomearq) {
  char linha[64];
  t_endereco1 *ptr_item;
  Lista lst = new_lista();

  FILE *arq = fopen(nomearq, "rt");

  while (fgets(linha, 64, arq) != NULL) {
    
    ptr_item = linhaPRAstruct(strip(linha));
    appendLista(lst, ptr_item);
  }

  fclose(arq);

  return lst;
}

Lista converte(Lista lst1) {
  Lista lst;
  Lista lst_aux;
  char cep[9];

  for (int i = 0; i < lenLista(lst1); i++) {
    t_endereco1 *elemento = elemLista(lst1, i);
    strcpy(cep, elemento->cep);

    if (in(lst, cep) == 0) {
      t_endereco2 *p = (t_endereco2 *)malloc(sizeof(t_endereco2));
      strcpy(p->cep, elemento->cep);
      for (int j = 0; i < lenLista(lst1); j++) {
        t_endereco1 *dado = elemLista(lst1, j);

        if (strcmp(dado->cep, cep) == 0) {
          appendLista(lst_aux, dado);
        }
      }

      p->endereco = lst_aux;
      appendLista(lst, p);
    }
  }

  return lst;
}

void print_enderecos_2(Lista lst) {
  for (int i = 0; i < lenLista(lst); i++) {
    t_endereco2 *elemento = elemLista(lst, i);
    printf("%s\n", elemento->cep);

    for (int j = 0; j < lenLista(elemento->endereco); j++) {
      t_endereco1 *elemento2 = elemLista(elemento->endereco, j);
      printf("%s %s %s\n", elemento2->cep, elemento2->nmr_casa,
             elemento2->nome_familia);
    }
  }
}

int main(void) {
  printf("Oi!");

  Lista lstEndereco1;
  Lista lstEndereco2;

  printf("Oi!");

  lstEndereco1 = loadbdceps("./bdceps.txt");

  printf("Ola!");

  lstEndereco2 = converte(lstEndereco1);

  printf("Hello!");

  print_enderecos_2(lstEndereco2);

  printf("Hola!");

  return 0;
}