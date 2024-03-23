#include <stdio.h>

int main()
{
    int M, N;

    // Ler os valores de M e N
    printf("Insira o numero de linhas (M) e colunas (N): ");
    scanf("%d %d", &M, &N);

    // Verificar se M e N estão dentro do intervalo permitido
    if (M < 1 || M > 20 || N < 1 || N > 50)
    {
        printf("Dimensoes fora do intervalo permitido.\n");
        return 1;
    }

    int A[M][N], transposta[N][M];

    // Ler os valores para a matriz A
    printf("Insira os elementos da matriz A:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Calcular a transposta de A
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            transposta[j][i] = A[i][j];
        }
    }

    // Imprimir a matriz A
    printf("Matriz A:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Imprimir a matriz transposta
    printf("Transposta de A:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
