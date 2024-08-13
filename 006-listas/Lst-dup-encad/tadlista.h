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

Lista newList();

int lenLista(Lista list);

Lista appendElem(Lista list, t_dado data);

t_dado getElem(Lista list, int pos);

Lista insertElem(Lista list, t_dado data, int pos);

t_dado removeElem(Lista list,int pos);

void printListInt(Lista list);

void printListString(Lista lst);