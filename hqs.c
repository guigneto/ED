#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

    // needle -> haystack
bool naLista(int item, int *lista, int lista_size){
    for(int i = 0; i < lista_size; i++){
        //printf("\n%d == %d", item, lista[i]);
        if(item == lista[i]){
            return 1;
        }
    }
    return 0;
}

int contarDuplicados(int *colecao_herois_hq, int *colecao_acao_comics, int tamanho_herois_hq, int tamanho_acao_comics){
    int duplicados = 0;
    
    for(int i = 0; i < tamanho_herois_hq; i++){
        
        for(int j = 0; j < tamanho_acao_comics; j++){
            //printf("\n%d == %d",colecao_herois_hq[i], colecao_acao_comics[j]);
            
            if(colecao_herois_hq[i] == colecao_acao_comics[j]){
                duplicados++;
            }
        }
    }
    return duplicados;
}

int* unir_colecoes(int *colecao_herois_hq, int *colecao_acao_comics, int tamanho_herois_hq, int tamanho_acao_comics, int *tamanho_final){
    // Checar duplicadas
    int qtd_duplicados = contarDuplicados(colecao_herois_hq, colecao_acao_comics, tamanho_herois_hq, tamanho_acao_comics);
    
    // colecao_herois_hq[] + colecao_acao_comics[]
    int tamanho_colecao = tamanho_herois_hq + tamanho_acao_comics - qtd_duplicados;

    // printf("\ntamanho_colecao = %d + %d - %d", tamanho_herois_hq, tamanho_acao_comics, qtd_duplicados);

    // Alocação dinâmica de memória
    int *colecao = (int *)malloc(tamanho_colecao * sizeof(int));

    //printf("Colecao %d", colecao);
    
    // Add herois_hq

    int j = 0;
    for(int i = 0; i < tamanho_herois_hq; i++){
        // needle -> haystack
        if(!naLista(colecao_herois_hq[i], colecao, tamanho_colecao)){
            colecao[j] = colecao_herois_hq[i];
            //printf("\nAdded %d", colecao_herois_hq[i]);
            j++;
        } else {
            //printf("Not added %d", colecao_herois_hq[i]);
        }

        //printf("\n%d__%d", i, colecao[i]);

        //printf("\ntamanho: %d", tamanho_herois_hq);
    }
    
    //Add acao_comics
    // For começa da posição 4 (tamanho_herois_hq)
    // i < tamanho_herois_hq + tamanho_acao_comics = Ter certeza que percorre todas posicoes
    j = tamanho_herois_hq;
    for(int i = tamanho_herois_hq; i < tamanho_herois_hq + tamanho_acao_comics; i++){
        // i - tamanho_herois_hq = Pois colecao_acao_comics é tamanho 3...
        // needle -> haystack
        if(!naLista(colecao_acao_comics[i-tamanho_herois_hq], colecao, tamanho_colecao)){
            colecao[j] = colecao_acao_comics[i-tamanho_herois_hq];
            //printf("\nAdded %d", colecao_acao_comics[i-tamanho_herois_hq]);
            j++;
        } else {
            //printf("\nNot added %d", colecao_acao_comics[i-tamanho_herois_hq]);
        }

        //printf("\n%d__%d", i, colecao_acao_comics[i-tamanho_herois_hq]);
    }

    // Nao funciona: *tamanho_final = sizeof(colecao)/sizeof(colecao[0]);
    *tamanho_final = tamanho_colecao;
    return colecao;
}

int main(void) {
    
    int colecao_herois_hq[] = {101, 102, 103, 104}; // IDs das edições da Heróis HQ
    int colecao_acao_comics[] = {201, 202, 203}; // IDs das edições da Ação Comics
    
    //int colecao_herois_hq[] = {101, 102, 103, 104}; // IDs das edições da Heróis HQ
    //int colecao_acao_comics[] = {201, 104, 203}; // IDs das edições da Ação Comics

    int tamanho_herois_hq = 4;
    int tamanho_acao_comics = 3;
    int tamanho_final;
    
    int *colecao_unificada = unir_colecoes(colecao_herois_hq, colecao_acao_comics, tamanho_herois_hq, tamanho_acao_comics, &tamanho_final);
    

    printf("Colecao unificada: ");
    for(int k = 0; k < tamanho_final; k++){
        printf("%d ", colecao_unificada[k]);
    }

    printf("\nTamanho da colecao unificada: %d", tamanho_final);
    
    // Saída esperada:
    // Colecao unificada: 101 102 103 104 201 202 203
    // Tamanho da colecao unificada: 7

    free(colecao_unificada);
    return 0;
}