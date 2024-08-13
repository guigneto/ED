/*
Instituto Federal do Espírito Santo
Bacharelado em Sistemas de Informação
Estrutura de dados 2024/1 - Prova 2 
Aluno: Guilherme Gomes de Faria Neto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tadlista.h"

typedef struct {
  char cep[32];
  char numero[32];
  char familia[32];
} t_endereco1;

typedef struct {
    char cep[32];
    Lista l;
} t_endereco2;

t_endereco1 *linhaPRAstruct(char *str){
  t_endereco1 *p = (t_endereco1 *)malloc(sizeof(t_endereco1));
  const char s[2] = ",";
  char *token;

  token = strtok(str, s);
  strcpy(p->cep,token);

  token = strtok(NULL, s);
  strcpy(p->numero,token);  

  token = strtok(NULL,s);
  strcpy(p->familia,token);

  return p;
}

char *strip(char *s){
  int ultimo = strlen(s) - 1;

  if(s[ultimo]=='\n') 
    s[ultimo] = '\0';

  return s;  
}

Lista loadbdceps(char *nomearq) {
    Lista l = new_lista();
    FILE *arq = fopen(nomearq, "rt");
    t_endereco1 *ptr;
    char linha[64];

    while (fgets(linha, sizeof(linha), arq)!=NULL) {
        ptr = linhaPRAstruct(strip(linha));
        appendLista(l, ptr);
    }
    fclose(arq);
    return l;
}

int in(Lista l, char *s){
  for(int i=0; i < lenLista(l); i++){
    t_endereco2 *dado = elemLista(l,i);
    char aux[32];
    strcpy(aux,dado->cep);
    if(strcmp(aux,s) == 0) return 1;
  }
  return 0;  
}

Lista filtraCep(Lista l1, char *s){
    Lista lstaux = new_lista();

    for(int i=0;i<lenLista(l1);i++){
        t_endereco1 *dado = elemLista(l1,i);
        if(strcmp(dado->cep, s) == 0){
            appendLista(lstaux,dado);
        }
    }

    return lstaux;
}

Lista converte(Lista lst1){
    Lista lstaux = new_lista();
    for(int i=0;i<lenLista(lst1);i++){
        t_endereco1 *dado = elemLista(lst1,i);
        char auxcep[32];
        strcpy(auxcep,dado->cep);
        if(in(lstaux,auxcep)==0){ //chave nao cadastrada
            t_endereco2 *ptr = (t_endereco2 *)malloc(sizeof(t_endereco2));
            strcpy(ptr->cep,auxcep);
            ptr->l = filtraCep(lst1,auxcep);
            appendLista(lstaux,ptr);
        }
    }
    
    return lstaux;
}

void print_lista(Lista l){
    t_endereco1 *dado;
    for(int i=0;i<lenLista(l);i++){
        dado = (t_endereco1 *)elemLista(l,i);
        printf("%s, %s, %s\n",dado->cep,dado->numero,dado->familia);
    }
}

void print_enderecos_2(Lista lst){
    t_endereco2 *dado;
    for(int i=0;i<lenLista(lst);i++){
        dado = (t_endereco2 *)elemLista(lst,i);
        printf("%s\n",dado->cep);
        print_lista(dado->l);
        printf("\n");
    }
}

int main(void){

    Lista lst = loadbdceps("bdceps.txt");
    Lista lst2 = converte(lst);
    print_enderecos_2(lst2);

    return 0;
}