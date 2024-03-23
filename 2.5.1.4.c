#include <stdio.h>
#include <math.h>

int main()
{
    double B[100];
    double S = 0.0;
    int i;

    // Leitura dos 100 valores numéricos
    printf("Digite os 100 valores para o conjunto B:\n");
    for (i = 0; i < 100; i++)
    {
        scanf("%lf", &B[i]);
    }

    // Cálculo do somatório S
    for (i = 0; i < 50; i++)
    {
        S += pow(B[i] - B[99 - i], 3);
    }

    // Impressão do resultado
    printf("O valor do somatório S é: %.2f\n", S);

    return 0;
}
