#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    double A, B;
    int anos = 0; // Inicializando a quantidade de anos

    A = 90000000;  // População inicial do país A
    B = 200000000; // População inicial do país B

    while (A <= B)
    {
        A = A * 1.03;  // Crescimento de 3% ao ano
        B = B * 1.015; // Crescimento de 1.5% ao ano
        anos++;
    }

    printf("Quantidade de anos necessários para que o país A ultrapasse ou iguale a população do país B: %d", anos);

    return 0;
}
