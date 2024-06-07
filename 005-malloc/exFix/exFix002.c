#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr = malloc(sizeof(int));

    // Esquecemos de liberar a memória alocada
    // free(ptr);

    return 0;
}