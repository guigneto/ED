#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td {
    int dia;
    int mes;
    int ano;
} tdata;

typedef struct pessoa {
    char nome[30];
    int idade;
    char fone[15];
    tdata nasc;
} pessoa;


int main(){

    pessoa amigo;
    strcpy(amigo.nome, "Romulo Alves");
    amigo.idade = 20;
    strcpy(amigo.fone, "9505-2526");
    amigo.nasc.dia = 25;
    amigo.nasc.mes = 05;
    amigo.nasc.ano = 2003;

    pessoa amiga = {"Natalia Valente",19,"8115-7292",{27,07,2004} }; //inicializando estrutura aninhada

    return 0;
}