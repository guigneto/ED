#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_data{ //struct auto referenciada
  int dia;
  int mes;
  int ano;
  struct tipo_data* proximo;
} t_data;

typedef struct {
  t_data* primeiro;
  t_data* ultimo;
  int tamanho;
}t_lista;

t_data* cria_data(int d, int m, int a){
  t_data *p = (t_data*)malloc(sizeof(t_data));
  p->dia = d;
  p->mes = m;
  p->ano = a;

  return p;
}

int len(t_lista l){
  return l.tamanho;
}

t_lista append(t_lista l, t_data* d){
  t_data* aux;
  if(l.tamanho == 0){
    l.primeiro=d;
    l.ultimo=d;
  }
  else {
    l.ultimo->proximo = d; 
    l.ultimo=d;
  }
  l.tamanho++;
  
  return l;
}

t_lista newLista(){
  t_lista lst;
  lst.primeiro=NULL;
  lst.ultimo=NULL;
  lst.tamanho=0;
  return lst;
}

int main(void){

  t_lista l;
  l = newLista();

  t_data *dt;

  return 0;
}
