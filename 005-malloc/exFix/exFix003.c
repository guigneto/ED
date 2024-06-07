#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr = malloc(sizeof(int));
    *ptr = 10;

    // Libera a memória
    free(ptr);

    // Agora ptr é um dangling pointer
    // Acessar ou modificar os dados através de ptr agora levará a um comportamento indefinido
    printf("%d\n", *ptr);

    return 0;
}
