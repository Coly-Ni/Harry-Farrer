#include <stdio.h>

#define MAX_M 20
#define MAX_N 30

int main()
{
    int m, n;
    int matrizA[MAX_M][MAX_N], matrizB[MAX_M][MAX_N], matrizSoma[MAX_M][MAX_N];

    // Ler os valores de m e n.
    printf("Insira o numero de linhas (m) e colunas (n): ");
    scanf("%d %d", &m, &n);

    // Verificar se m e n estão dentro do intervalo especificado.
    if (m > MAX_M || n > MAX_N)
    {
        printf("Dimensoes fora do intervalo permitido.\n");
        return 1;
    }

    // Ler os valores para a matriz A.
    printf("Insira os elementos da matriz A:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Ler os valores para a matriz B.
    printf("Insira os elementos da matriz B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Calcular a soma das matrizes.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    // Imprimir a matriz de soma.
    printf("Matriz Soma:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrizSoma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
