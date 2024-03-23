#include <stdio.h>
#define MAX_N 20

int main()
{
    int n, i, j;
    double A[MAX_N][MAX_N], B[MAX_N], X[MAX_N];

    // Ler o número de equações
    printf("Insira o numero de equacoes (n <= 20): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_N)
    {
        printf("Numero de equacoes fora dos limites permitidos.\n");
        return 1;
    }

    // Ler a matriz triangular A dos coeficientes
    printf("Insira os coeficientes da matriz triangular superior A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
            {
                A[i][j] = 0; // Garante que a parte inferior da matriz é zero
            }
            else
            {
                scanf("%lf", &A[i][j]);
            }
        }
    }

    // Ler o vetor B dos termos independentes
    printf("Insira os termos independentes B:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &B[i]);
    }

    // Resolver o sistema utilizando substituição retroativa
    for (i = n - 1; i >= 0; i--)
    {
        X[i] = B[i];
        for (j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        if (A[i][i] == 0)
        {
            if (B[i] == 0)
            {
                printf("Sistema possui infinitas solucoes.\n");
            }
            else
            {
                printf("Sistema nao possui solucao.\n");
            }
            return 1;
        }
        X[i] /= A[i][i];
    }

    // Imprimir as raízes
    printf("Raizes do sistema:\n");
    for (i = 0; i < n; i++)
    {
        printf("X%d = %f\n", i + 1, X[i]);
    }

    return 0;
}
