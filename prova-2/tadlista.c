/*
Instituto Federal do Espírito Santo
Bacharelado em Sistemas de Informação
Estrutura de dados 2024/1 - Prova 2
Aluno: Guilherme Gomes de Faria Neto
*/

#include "./tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_no newNo(t_dado data){
    t_no no = (t_no)malloc(sizeof(struct tipo_no));
    no->dado = data;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}

void anulaNo(t_no no){
    no->proximo = NULL;
    no->anterior = NULL;
    no->dado = NULL;
    free(no);
}

t_no percorreLista(Lista l,int pos){
    t_no aux = l->primeiro;
    for(int i=0;i<pos;i++){
        aux = aux->proximo;
    }

    return aux;
}

Lista new_lista(){
    Lista l = (Lista)malloc(sizeof(struct tipo_lista));
    l->tamanho = 0;
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

int lenLista(Lista l){
    return l->tamanho;
}

Lista appendLista(Lista l, t_dado d){
    t_no no = newNo(d);

    if(l->tamanho > 0){
        l->ultimo->proximo = no;
        no->anterior = l->ultimo;
        l->ultimo = no;
    }
    else{
        l->primeiro = no;
        l->ultimo = no;
    }
    l->tamanho++;

    return l;
}

t_dado elemLista(Lista l, int pos){
    if((pos>=0)&&(pos<l->tamanho)&&(l->tamanho>0)){
        t_no aux = percorreLista(l,pos);
        return aux->dado;
    }
    else{
        return NULL;
    }
}

Lista insereLista(Lista l, t_dado dado, int pos){
    if((pos>=0)&&(pos<=l->tamanho)){
        if((pos == l->tamanho)||(l->tamanho == 0)){
            appendLista(l,dado);
        }
        else{ 
            t_no novo_no = newNo(dado);
            l->tamanho++;
            if(pos==0){
                novo_no->proximo = l->primeiro;
                l->primeiro->anterior = novo_no;
                l->primeiro = novo_no;
            }
            else{
                t_no aux = percorreLista(l,pos);

                novo_no->proximo = aux;
                novo_no->anterior = aux->anterior;
                aux->anterior->proximo = novo_no;
                aux->anterior = novo_no;

            }
        }
    }
    return l;
}
t_dado removeLista(Lista l, int pos){
    if((pos>=0)&&(l->tamanho>0)&&(pos<l->tamanho)){ //checa se pos valida
        t_no aux = percorreLista(l,pos);
        t_dado auxDado = aux->dado;
        if(pos==0){//se for a primeira
            if(l->tamanho==1){ //lista com 1 elemento
                l->primeiro = NULL;
                l->ultimo = NULL;
            }
            else{
                l->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
            }
        }
        else{ //pos nao e a primeira 
            if(pos==l->tamanho-1){ //se for a ultima
                l->ultimo = aux->anterior;
                aux->anterior->proximo = NULL;
            }
            else{ //pos esta no meio
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
            }
        }

        l->tamanho--;
        anulaNo(aux);
        return auxDado;
    }
    else{
        return NULL;
    }
}