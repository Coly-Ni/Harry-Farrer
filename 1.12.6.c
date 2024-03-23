#include <stdio.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float massainicial, massafinal;
    int segundos = 0, minutos, horas, resto;

    printf("Digite a massa inicial do material: ");
    scanf("%f", &massainicial);

    massafinal = massainicial;

    while (massafinal >= 0.50)
    {
        massafinal /= 2;
        segundos += 50;
    }

    // Conversão do tempo
    horas = segundos / 3600;
    resto = segundos % 3600;
    minutos = resto / 60;
    segundos = resto % 60;

    printf("Massa inicial: %.2f g\n", massainicial);
    printf("Massa final: %.2f g\n", massafinal);
    printf("Tempo necessário: %d horas, %d minutos e %d segundos\n", horas, minutos, segundos);

    return 0;
}
