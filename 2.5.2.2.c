#include <stdio.h>

#define LINHAS 100
#define COLUNAS 200

int main()
{
    int B[LINHAS][COLUNAS];
    int i;
    int soma = 0;

    // Suponha que a matriz B já foi preenchida com alguns valores.
    // Aqui, vamos calcular a soma dos elementos da 40ª coluna.

    for (i = 0; i < LINHAS; i++)
    {
        soma += B[i][39]; // Índices em C começam do 0, então a 40ª coluna é indexada por 39.
    }

    printf("A soma dos elementos da 40ª coluna é: %d\n", soma);

    return 0;
}
