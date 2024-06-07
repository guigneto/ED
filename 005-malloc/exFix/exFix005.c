#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char placa[12];
    char modelo[50];
    char marca[50];
    int quilometragem;
} veiculo;

veiculo* loadbdveics(char *nomearq){

    veiculo *ptr_veic = malloc(150 * sizeof(veiculo));
    
    FILE * arq = fopen(nomearq,"rt");

    for (int i=0;i<150;i++){

        fscanf(arq,"%s",ptr_veic[i].placa);
        fscanf(arq,"%s",ptr_veic[i].modelo);
        fscanf(arq,"%s",ptr_veic[i].marca);
        fscanf(arq,"%d",&ptr_veic[i].quilometragem);

    }

    fclose(arq);

    return ptr_veic;
}

int main(void){
    char nomearq[50] = "./005-malloc/exFix/txt/bdveiculos.txt";
    veiculo *vect = loadbdveics(nomearq);
    for (int i=0;i,150;i++){
        printf("Placa: %s\n",vect[i].placa);
        printf("Modelo: %s\n",vect[i].modelo);
        printf("Marca: %s\n",vect[i].marca);
        printf("Quilometragem: %d\n",vect[i].quilometragem);
    }
    free(vect);
    return 0;
}