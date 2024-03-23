#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define MAX 3
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    float BOIS, GORDO, MAGRO, MAIORPESO, MENORPESO, NUMERO, PESO;
    //iniciando variaveis
    BOIS = 0;
    MAIORPESO = 0;
    MENORPESO = 10000;
    while(BOIS < MAX)
    {
        printf("digite o numero e o peso do boi:");
        scanf("%f%f", &NUMERO, &PESO);
        //boi mais gordo
        if (PESO > MAIORPESO)
        {
            MAIORPESO = PESO;
            GORDO = NUMERO;
        }
        //boi mais magro
        if (PESO < MENORPESO)
        {
            MENORPESO = PESO;
            MAGRO = NUMERO;
        }
        //contando os bois
        BOIS++;

    }
    //escrevendo o maior peso
    printf("o mais gordo: %.2f %.2f\n", GORDO, MAIORPESO);
    //escrevendo o menor PESO
    printf("o mais gordo: %.2f %.2f\n", MAGRO, MENORPESO);
}

