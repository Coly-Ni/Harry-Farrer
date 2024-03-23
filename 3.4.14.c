#include <stdio.h>
#include <math.h>

// Sub-rotina para calcular o valor de S da série até n termos.
double calcularS(int n)
{
    double s = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        double termo = 1.0 / pow((2 * i + 1), 3);
        if (i % 2 == 1)
        { // subtrai para ímpares
            s -= termo;
        }
        else
        { // soma para pares
            s += termo;
        }
    }
    return s;
}

// Função para calcular e imprimir a tabela de valores de π.
void imprimirTabelaPi(int n)
{
    printf("Termos da Série\tValor de π\n");
    for (int i = 1; i <= n; ++i)
    {
        double s = calcularS(i);
        double pi = sqrt(32) * s;
        printf("%d\t\t%.10f\n", i, pi);
    }
}

int main()
{
    int n;
    printf("Digite o número de termos N: ");
    scanf("%d", &n);
    imprimirTabelaPi(n);
    return 0;
}
