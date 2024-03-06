 #include <stdio.h>

 float celcius(double farenheit){
    return 5./9.*(farenheit-32.);
 }

 int main(){

    for(int i=50;i<=150;i++){
        printf("%3d = %.2f\n",i, celcius(i));
    }

    return 0;
 }
