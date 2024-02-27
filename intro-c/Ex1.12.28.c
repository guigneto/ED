 #include <stdio.h>
 #include <stdlib.h>

 float dividir(float numerador, int denominador){
    float div = numerador/denominador;
    return div;
 }

 float somatoria(float numerador, int denominador){
    float divisao, negativos, positivos;
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
    return positivos-negativos;
 }

 int main(){
    
    // float numerador, divisao, negativos, positivos;
    // int denominador;
    float numerador = 1000.0;
    int denominador = 1;

    // for(int i=0;i<50;i++){
    //     printf("%.0f/%d\n",numerador,denominador);
    //     divisao = dividir(numerador, denominador); 
    //     if(denominador%2==0){
    //         negativos += divisao;
    //     } else {
    //         positivos += divisao;
    //     }
    //     numerador -= 3;
    //     denominador++;
    // }

    printf("%.2f",somatoria(numerador, denominador));
    return 0;
 }