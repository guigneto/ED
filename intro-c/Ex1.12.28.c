 #include <stdio.h>
 #include <stdlib.h>

 float dividir(float numerador, int denominador){
    float div = numerador/denominador;
    return div;
 }

 int main(){
    
    float numerador, divisao, negativos, positivos;
    int denominador;
    numerador = 1000.0;
    denominador = 1;

    for(int i=0;i<50;i++){
        printf("%.0f/%d\n",numerador,denominador);
        divisao = dividir(numerador, denominador); 
        if(denominador%2==0){
            negativos += divisao;
        } else {
            positivos += divisao;
        }
        numerador -= 3;
        denominador++;
    }

    printf("%.2f",positivos-negativos);
    return 0;
 }