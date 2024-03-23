#include <stdio.h>

#define LINHAS 100
#define COLUNAS 200

int main()
{
    int B[LINHAS][COLUNAS];
    int j;
    int soma = 0;

    // Suponha que a matriz B já foi preenchida com alguns valores.
    // Aqui, vamos calcular a soma dos elementos da 30ª linha.

    for (j = 0; j < COLUNAS; j++)
    {
        soma += B[29][j]; // Índices em C começam do 0, então a 30ª linha é indexada por 29.
    }

    printf("A soma dos elementos da 30ª linha é: %d\n", soma);

    return 0;
}
