/*
Instituto Federal do Espírito Santo
Bacharelado em Sistemas de Informação
Estrutura de dados 2024/1 - Prova 1 
Aluno: Guilherme Gomes de Faria Neto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char placa[12];
  char modelo[50];
  char marca[50];
  int quilometragem;
} t_veiculo;

void strip(char s[]){
  if(s[strlen(s)-1] == '\n')
    s[strlen(s)-1] = '\0';
}

t_veiculo *loadbdveics(char *nomearq){

  t_veiculo* ptr_veiculo = malloc(150 * sizeof(t_veiculo));

  FILE *arq = fopen("bdveiculos.txt","rt");

  char quilom[20];
  for(int i=0;i<150;i++){
    
    fgets(ptr_veiculo[i].placa,12,arq);
    strip(ptr_veiculo[i].placa);

    fgets(ptr_veiculo[i].modelo,50,arq);
    strip(ptr_veiculo[i].modelo);

    fgets(ptr_veiculo[i].marca,50,arq);
    strip(ptr_veiculo[i].marca);
    
    
    fgets(quilom,12,arq);
    strip(quilom);
    ptr_veiculo[i].quilometragem = atoi(quilom);
  }

  fclose(arq);

  return ptr_veiculo;
}

void filtro(t_veiculo *vet, char *marca_veiculo, int tam_vet){

  char nomearq[128];
  strcpy(nomearq,marca_veiculo);
  strcat(nomearq,".txt");

  FILE *arq = fopen(nomearq,"at");

  for(int i=0;i<tam_vet;i++){
    if(strcmp(marca_veiculo,vet[i].marca)==0){
      fprintf(arq,"%s, %s, %s, %d\n",
      vet[i].placa,
      vet[i].modelo,
      vet[i].marca,
      vet[i].quilometragem);
    }
  }
  
  fclose(arq);
}

int main(void){

  char nomearq[18] = "bdveiculos.txt";
  t_veiculo *vet = loadbdveics(nomearq);

  filtro(vet,"FIAT",150);
  filtro(vet,"TOYOTA",150);
  filtro(vet,"FORD",150);
  filtro(vet, "RENAULT",150);

  free(vet);

  return 0;
}