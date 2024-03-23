#include <stdio.h>

int main()
{
    int M, N;

    // Solicitar as dimensões da matriz
    printf("Insira o numero de linhas (M) e colunas (N) da matriz A: ");
    scanf("%d %d", &M, &N);

    // Validar as dimensões
    if (M > 20 || N > 10 || M < 1 || N < 1)
    {
        printf("Dimensoes fora do intervalo permitido.\n");
        return 1;
    }

    int A[M][N], B[M][N + 1];

    // Ler os elementos da matriz A e inicializar B
    printf("Insira os elementos da matriz A:\n");
    for (int i = 0; i < M; i++)
    {
        int produto = 1; // Inicializa o produto dos elementos da linha
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
            B[i][j] = A[i][j];  // Copia o elemento para B
            produto *= A[i][j]; // Calcula o produto
        }
        B[i][N] = produto; // Atribui o produto à última coluna de B
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

    // Imprimir a matriz B
    printf("Matriz B:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
