#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Faça duas matrizes 5x6 com numeros aleatorios e depois faça a soma das matrizes
*/

int randint(int inf, int sup) {
	int result;
	result = inf + rand() % ((sup + 1) - inf);

	return result;
}

void povoaMat(int m[5][6], int ls, int cs) {
	for (int i = 0; i < ls; i++) {
		for (int j = 0; j < cs; j++) {
			m[i][j] = randint(1, 10);
		}
	}
}

void somaMat(int m[5][6], int n[5][6], int s[5][6], int ls, int cs) {
	for (int i = 0; i < ls; i++) {
		for (int j = 0; j < cs; j++) {
			s[i][j] = m[i][j] + n[i][j];
		}
	}
}

void printMat(int m[5][6], int ls, int cs){

	for (int i = 0; i < ls; i++) {
		for (int j = 0; j < cs; j++) {
			printf("%8d",m[i][j]);
		}
		printf("\n");
	}

}

int main(){

	int mA[5][6],mB[5][6],sM[5][6];

	povoaMat(mA,5,6);
	povoaMat(mB,5,6);

	somaMat(mA,mB,sM,5,6);

	printMat(mA,5,6);
	printf("\n");
	printMat(mB,5,6);
	printf("\n");
	printMat(sM,5,6);

	return 0;
}