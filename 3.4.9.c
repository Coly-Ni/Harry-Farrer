#include <stdio.h>

// Função para calcular o produto usando o método de multiplicação russa
int multiplicacaoRussa(int a, int b)
{
    int produto = 0;
    while (a >= 1)
    {
        if (a % 2 != 0)
        {
            produto += b;
        }
        a /= 2;
        b *= 2;
    }
    return produto;
}

int main()
{
    int pares[10][2];
    printf("Digite 10 pares de números inteiros positivos:\n");

    // Lendo 10 pares de números
    for (int i = 0; i < 10; i++)
    {
        printf("Par %d: ", i + 1);
        scanf("%d %d", &pares[i][0], &pares[i][1]);
    }

    // Calculando e imprimindo o produto de cada par usando a função de multiplicação russa
    for (int i = 0; i < 10; i++)
    {
        int produto = multiplicacaoRussa(pares[i][0], pares[i][1]);
        printf("Produto de %d e %d: %d\n", pares[i][0], pares[i][1], produto);
    }

    return 0;
}
