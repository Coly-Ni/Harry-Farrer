#include <stdio.h>
#include <stdbool.h>

#define TAM_MAX 30

int main()
{
    int M, N, i, j;
    int A[TAM_MAX], B[TAM_MAX], C[TAM_MAX * 2]; // C pode conter no máximo M + N elementos
    int tamanhoC = 0;                           // Contador real para o tamanho do conjunto C
    bool ehUnico;

    // a) Leitura dos valores para A
    printf("Digite o número de elementos de A (M <= 30): ");
    scanf("%d", &M);
    printf("Digite os valores de A:\n");
    for (i = 0; i < M; i++)
    {
        scanf("%d", &A[i]);
        C[tamanhoC++] = A[i]; // Insere diretamente em C pois A não tem repetidos
    }

    // b) Leitura dos valores para B
    printf("Digite o número de elementos de B (N <= 30): ");
    scanf("%d", &N);
    printf("Digite os valores de B:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
        // c) Verifica se o elemento de B já existe em C para garantir a unicidade
        ehUnico = true;
        for (j = 0; j < tamanhoC; j++)
        {
            if (C[j] == B[i])
            {
                ehUnico = false;
                break;
            }
        }
        if (ehUnico)
        {
            C[tamanhoC++] = B[i]; // Adiciona em C se for único
        }
    }

    // d) Imprimir os elementos dos conjuntos A, B e C
    printf("Elementos de A:\n");
    for (i = 0; i < M; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nElementos de B:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\nElementos de C (união de A e B sem repetidos):\n");
    for (i = 0; i < tamanhoC; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
