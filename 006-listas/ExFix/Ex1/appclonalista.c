#include "../../Lst-dup-encad/tadlista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strip(char *s){
    if(s[strlen(s)-1]=='\n'){
        s[strlen(s)-1] = '\0';
    }
    return s;
}

Lista loadLista(Lista l, char *filename){

    FILE *arq = fopen(filename,"rt");
    char linha[64];
    char *dadolst;


    while(!feof(arq)){
        dadolst = (char *)malloc(64 * sizeof(char));
        fgets(linha,64,arq);
        strip(linha);

        strcpy(dadolst,linha);

        appendElem(l, dadolst);
    }

    return l;
}

Lista clonaLista(Lista lst){
    Lista clone = newList();

    for(int i=0;i<lenLista(lst);i++){
        appendElem(clone,getElem(lst,i));
    }

    return clone;
}


int main(void){

    Lista lstA = newList();
    lstA = loadLista(lstA,"./clonadados.txt");

    Lista lstB = newList();
    lstB = clonaLista(lstA);

    printListString(lstB);

    return 0;
}