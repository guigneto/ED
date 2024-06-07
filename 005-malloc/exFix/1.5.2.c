#include <stdio.h>

int a=0; // Global variable a

void qualquer(int c);

int main(void) {
    int a=2; // Local variable a in main
    int b=3; // Local variable b in main

    printf("1. main_b = %d\n", b); // Prints 3
    printf(" main_a = %d\n", a);   // Prints 2

    qualquer(a);

    printf("2. main_b = %d\n", b); // Prints 3
    printf("3. main_a = %d\n", a); // Prints 2

    return 0;
}

void qualquer(int c) {
    int b=4; // Local variable b in qualquer

    printf("qualquer_a = %d\n", a); // Prints the global a, which is 0
    printf("qualquer_b = %d\n", b); // Prints 4

    c = 5; // Modifies local parameter c, does not affect variables in main
}
