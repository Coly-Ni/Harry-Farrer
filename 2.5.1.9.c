#include <stdio.h>

#define TAMANHO 30

int main()
{
    int A[TAMANHO];
    int B[TAMANHO];
    int X;
    int i, posicao = -1;

    // Leitura dos valores para a variável composta A
    printf("Digite 30 valores para o array A:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        scanf("%d", &A[i]);
    }

    // Leitura dos valores para a variável composta B
    printf("Digite 30 valores para o array B:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        scanf("%d", &B[i]);
    }

    // Leitura do valor para a variável X
    printf("Digite o valor para X: ");
    scanf("%d", &X);

    // Verificação qual elemento de A é igual a X
    for (i = 0; i < TAMANHO; i++)
    {
        if (A[i] == X)
        {
            posicao = i;
            break;
        }
    }

    // Impressão do elemento de B correspondente
    if (posicao != -1)
    {
        printf("O elemento de B correspondente à posição de X em A é: %d\n", B[posicao]);
    }
    else
    {
        printf("O valor X não foi encontrado em A.\n");
    }

    return 0;
}
