#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    float D, K, NUMERO, SOMA;
    printf("digite um número:");
    scanf("%f", &NUMERO);
    SOMA = NUMERO + 1;
           K = (NUMERO/2);
           D = 2;
           while( D < K){
                if (fmod(NUMERO,D) == 0){
                               SOMA = SOMA + D;
                }
                D++;
                  }
        printf("%.2f", SOMA);
}
