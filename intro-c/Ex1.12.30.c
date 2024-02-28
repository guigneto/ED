#include <stdio.h>

float dividir(float numerador, int denominador){
    return numerador/denominador;
}

float metodo(float numerador, int denominador){
    float divisao,negativo,positivo;
    for(int i=0;i<30;i++){
        printf("%0.f/%d %d\n",numerador,denominador,i+1);
        divisao = dividir(numerador,denominador);
        if(denominador%2==0){
            positivo += divisao;
        } else {
            negativo += divisao;
        }
        numerador -= 5;
        denominador++;
    }
    return positivo - negativo;
}

int main(){

    float numerador = 480.;
    int denominador = 10;

    printf("%.2f",metodo(numerador,denominador));

    return 0;
}