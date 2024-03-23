#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

int main()
{
    int M, i, j;
    bool simetrica = true;
    double matriz[MAX_SIZE][MAX_SIZE];

    // a) Ler o valor de M
    printf("Insira a dimensao da matriz (MxM) onde M <= 20: ");
    scanf("%d", &M);

    if (M < 1 || M > MAX_SIZE)
    {
        printf("Dimensao fora dos limites permitidos.\n");
        return 1;
    }

    // Ler a matriz
    printf("Insira os elementos da matriz %dx%d:\n", M, M);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%lf", &matriz[i][j]);
        }
    }

    // b) Verificar se a matriz é simétrica
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (matriz[i][j] != matriz[j][i])
            {
                simetrica = false;
                break;
            }
        }
        if (!simetrica)
        {
            break;
        }
    }

    // c) Imprimir o resultado
    if (simetrica)
    {
        printf("A matriz e simetrica.\n");
    }
    else
    {
        printf("A matriz nao e simetrica.\n");
    }

    return 0;
}
