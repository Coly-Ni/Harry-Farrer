#include <stdio.h>
#include <math.h>

#define MAX_GRAU 20
#define NUM_VALORES 10

int main()
{
    int n, i, j;
    double coeficientes[MAX_GRAU + 1];
    double x, P;

    // a) Ler o valor de n
    printf("Digite o grau do polinômio (n <= 20): ");
    scanf("%d", &n);

    // Verificar se n é menor ou igual a 20
    if (n < 0 || n > 20)
    {
        printf("Grau inválido. O grau deve ser entre 0 e 20.\n");
        return 1;
    }

    // b) Ler os coeficientes do polinômio
    printf("Digite os coeficientes do polinômio (a0 até an):\n");
    for (i = 0; i <= n; i++)
    {
        printf("a%d: ", i);
        scanf("%lf", &coeficientes[i]);
    }

    // c) e d) Calcular e imprimir P(x) para 10 valores de x
    printf("Digite 10 valores para x:\n");
    for (i = 0; i < NUM_VALORES; i++)
    {
        printf("x%d: ", i + 1);
        scanf("%lf", &x);

        P = 0.0;
        for (j = n; j >= 0; j--)
        {
            P += coeficientes[j] * pow(x, j);
        }

        printf("P(%.2f) = %.2f\n", x, P);
    }

    return 0;
}
