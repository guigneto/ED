#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char placa[12];
    char modelo[50];
    char marca[50];
    int quilometragem;
} veiculo;

<<<<<<< HEAD
void filtro(veiculo *ptr_veic, char *marca_veiculo) {
    
    for (int i = 0; i < 150; i++) {
        if (strcmp(ptr_veic[i].marca, marca_veiculo) == 0) { // strcmp para comparar strings
            char nome[50];
            strcpy(nome, ptr_veic[i].modelo);
            strcat(nome, ".txt"); // Concatenar sufixo
            
            // Criar um path
            char filepath[100]; 
            snprintf(filepath, sizeof(filepath), "./txt/%s", nome); //  "./txt/" eh o local desejado
            FILE *arq = fopen(filepath, "wt");
            if (arq != NULL) {
                fprintf(arq, "%s,%s,%s,%d\n", 
                        ptr_veic[i].placa, 
                        ptr_veic[i].modelo, 
                        ptr_veic[i].marca, 
                        ptr_veic[i].quilometragem);
                fclose(arq);
            } else {
                printf("Erro ao abrir arquivo: %s\n", filepath);
            }
        }
    }
=======
void filtro(veiculo *ptr_veic,char *marca_veiculo){ 
    for(int i=0;i<150;i++){
        char nome[50] = ptr_veic[i].modelo;
        strcat(nome,".txt");
        FILE * arq = fopen("./005-malloc/exFix/txt/"nome,"wt");
        fprintf(arq,"%s,%s,%s,%d",ptr_veic[i].placa,ptr_veic[i].modelo,ptr_veic[i].marca,ptr_veic.quilometragem);
        fclose(arq);
    }
   
>>>>>>> 7ef4224846a8e1db722fc9060bcf3dcd10e44f9b
}

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
    char nomearq[50] = "./txt/bdveiculos.txt";
    veiculo *vect = loadbdveics(nomearq);
<<<<<<< HEAD
    
=======
>>>>>>> 7ef4224846a8e1db722fc9060bcf3dcd10e44f9b
    for (int i=0;i<150;i++){
        printf("Placa: %s\n",vect[i].placa);
        printf("Modelo: %s\n",vect[i].modelo);
        printf("Marca: %s\n",vect[i].marca);
        printf("Quilometragem: %d\n",vect[i].quilometragem);
    }

    filtro(vect, "MarcaF");
    
    free(vect);
    return 0;
}