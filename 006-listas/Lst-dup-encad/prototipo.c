//Implementar um tipo lista duplamente encadeada
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *t_dado;

typedef struct tipo_no {
    t_dado dado;
    struct tipo_no *anterior;
    struct tipo_no *proximo;
} *t_no;

typedef struct tipo_lista {
    int tamanho;
    t_no primeiro;
    t_no ultimo;
} *Lista;

t_no newNo(t_dado data){
    t_no no = (t_no)malloc(sizeof(struct tipo_no));
    no->dado = data;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}

Lista newList(){
    Lista l = (Lista)malloc(sizeof(struct tipo_lista));
    l->tamanho = 0;
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

void anulaNo(t_no no){
    no->proximo = NULL;
    no->anterior = NULL;
    no->dado = NULL;
    free(no);
}

int len(Lista list){
    return list->tamanho;
}

Lista appendElem(Lista list, t_dado data){

    t_no no = newNo(data);

    if(list->tamanho > 0){
        list->ultimo->proximo = no;
        no->anterior = list->ultimo;
        list->ultimo = no;
    }
    else{
        list->primeiro = no;
        list->ultimo = no;
    }
    list->tamanho++;

    return list;
}

t_dado getElem(Lista list, int pos){
    t_no aux;
    if((pos>=0)&&(pos<list->tamanho)&&(list->tamanho>0)){
        aux = list->primeiro;
        for(int i=0;i<pos;i++){
            aux = aux->proximo;
        }
        return aux->dado;
    }
    else{
        return NULL;
    }
}

Lista insertElem(Lista list, t_dado data, int pos){
    if((pos>=0)&&(pos<=list->tamanho)){
        if((pos == list->tamanho)||(list->tamanho == 0)){
            appendElem(list,data);
        }
        else{  //lista nao e vazia
            t_no novo_no = newNo(data);
            list->tamanho++;
            if(pos==0){
                novo_no->proximo = list->primeiro;
                list->primeiro->anterior = novo_no;
                list->primeiro = novo_no;
            }
            else{
                t_no aux = list->primeiro;
                for(int i=0;i<pos;i++){
                    aux = aux->proximo;
                }

                novo_no->proximo = aux;
                novo_no->anterior = aux->anterior;
                aux->anterior->proximo = novo_no;
                aux->anterior = novo_no;

            }
        }
    }
    return list;
}

t_dado removeElem(Lista list,int pos){
    if((pos>=0)&&(list->tamanho>0)&&(pos<list->tamanho)){ //checa se pos valida
        t_no aux = list->primeiro;
        for(int i=0;i<pos;i++){
            aux = aux->proximo;
        }
        t_dado auxDado = aux->dado;
        if(pos==0){//se for a primeira
            if(list->tamanho==1){ //lista com 1 elemento
                list->primeiro = NULL;
                list->ultimo = NULL;
            }
            else{
                list->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
            }
        }
        else{ //pos nao e a primeira 
            if(pos==list->tamanho-1){ //se for a ultima
                list->ultimo = aux->anterior;
                aux->anterior->proximo = NULL;
            }
            else{ //pos esta no meio
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
            }
        }

        list->tamanho--;
        anulaNo(aux);
        return auxDado;
    }
    else{
        return NULL;
    }
}

void printListInt(Lista list){
    printf("[ ");
    for(int i=0;i<list->tamanho;i++){
        printf("%d ",getElem(list,i));
    }
    printf("]\n");
}

int main(void){

    Lista lista = newList();
    for(int i=0;i<5;i++){
        lista = appendElem(lista,i*4);
    }
    printListInt(lista);

    lista = appendElem(lista,69);
    printListInt(lista);

    lista = insertElem(lista,85,1);
    printListInt(lista);

    removeElem(lista,3);
    printListInt(lista);

    return 0;
}