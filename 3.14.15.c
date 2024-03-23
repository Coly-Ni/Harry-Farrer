#include <stdio.h>
#include <math.h>

// Sub-rotina para calcular o valor de 'e' usando uma série
double calcularE(int n)
{
    double e = 1.0;
    double fatorial = 1.0;

    for (int i = 1; i <= n; ++i)
    {
        fatorial *= i;       // Calcula i!
        e += 1.0 / fatorial; // Soma o termo atual à soma total
    }

    return e;
}

// Função para determinar o número necessário de termos da série
int determinarNumeroDeTermos(double precisao)
{
    double valorExp = exp(1);
    double e = 1.0;
    double fatorial = 1.0;
    int n = 1;

    while (fabs(valorExp - e) > precisao)
    {
        fatorial *= n;       // Calcula n!
        e += 1.0 / fatorial; // Soma o termo atual à soma total
        ++n;
    }

    return n; // Retorna o número de termos necessários
}

int main()
{
    double precisao = 0.0001;
    int numeroDeTermos = determinarNumeroDeTermos(precisao);

    printf("Número de termos necessários: %d\n", numeroDeTermos);
    printf("Valor de e calculado: %.10f\n", calcularE(numeroDeTermos));
    printf("Valor de e usando exp(1): %.10f\n", exp(1));

    return 0;
}
