#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int fatorial(int n){
    long int fat = 1;
    if((n==1) || (n==0)){
    return 1;
    }
    for(long int i=1;i<=n;i++){
        fat = fat * i;
    }
    return fat;
}

double para_rads(double a){
  return (a * 3.1415)/180;
}

double meu_seno(int aGraus, int numTermos){
  double A = para_rads(aGraus);
  double senoA = 0;
  int expoente = 1;
  int sinal =1;

  for(int i=0;i<numTermos;i++){
    double fracao = pow(A,expoente)/fatorial(expoente);
    senoA +=  sinal * fracao;
    expoente += 2;
    sinal = sinal * -1;
  }
  return senoA;
}

int main(){

    for(int angulo=0; angulo<=360;angulo++){

      double senoC = sin(para_rads(angulo));
      double meuSeno =  meu_seno(angulo,10);
      double diferenca = fabs(senoC - meuSeno); //valor absoluto
      printf("%3d %10.3lf %10.3lf %10.3lf \n",angulo,senoC,meuSeno,diferenca);

    }

    return 0;
}

// gcc Ex1.12.30.c -lm -o main.bin -Wall
// -lm = atrelar o binario ja compilado do math.h