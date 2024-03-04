// C program to generate a random integer between two numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int inf, int sup) {
    return inf + rand() / (RAND_MAX / (sup - inf + 1) + 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer between 10 and 50
    int randNum = randint(10, 50);

    printf("Random number: %d\n", randNum);

    return 0;
}