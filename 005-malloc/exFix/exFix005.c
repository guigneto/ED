#include <stdio.h>
#include <stdlib.h>

typedef struct VEICULO {
    char placa[10];
    char modelo[50];
    char marca[50];
    float quilometragem;
} veiculo;

veiculo * loadbdveics(char *nomearq){

    veiculo *ptr_veic = malloc(sizeof(veiculo));
    veiculo veic_vect[150];
    ptr_veic = &veic_vect;
    
    FILE * arq = fopen(nomearq,"rt");

    for (int i=0;i<150;i++){
        veiculo carro;
        fscanf(arq,"%s",carro.placa);
        fscanf(arq,"%s",carro.modelo);
        fscanf(arq,"%s",carro.marca);
        fscanf(arq,"%f",&carro.quilometragem);

    }

    fclose(arq);
}

int main(void){
    char nomearq[32] = "./txt/bdveiculos.txt";
    veiculo vect[] = loadbdveics(nomearq);

    return 0;
}