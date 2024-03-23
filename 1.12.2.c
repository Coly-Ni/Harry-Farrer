#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 50 // Supondo que MAX seja 50 como mencionado no problema

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Variáveis
    float altura, soma = 0, media = 0, maioraltura = 0, menoraltura = 9999.99;
    char sexo[10];
    int m = 0, h = 0, i;

    for (i = 0; i < MAX; i++)
    {
        printf("Digite o sexo (masculino/feminino): ");
        scanf("%s", sexo);
        printf("Digite a altura: ");
        scanf("%f", &altura);

        // Maior e menor altura
        if (altura > maioraltura)
            maioraltura = altura;
        if (altura < menoraltura)
            menoraltura = altura;

        // Processamento para feminino
        if (strcmp(strlwr(sexo), "feminino") == 0)
        {
            m++;
            soma += altura;
        }

        // Contagem de homens
        if (strcmp(strlwr(sexo), "masculino") == 0)
        {
            h++;
        }
    }

    // Cálculo da média de altura das mulheres
    if (m > 0)
        media = soma / m;

    // Resultados
    printf("A maior altura do grupo: %.2f\n", maioraltura);
    printf("A menor altura do grupo: %.2f\n", menoraltura);
    printf("O número de homens: %d\n", h);
    if (m > 0)
    {
        printf("A média da altura das mulheres: %.2f\n", media);
    }
    else
    {
        printf("Não foram informadas mulheres no grupo.\n");
    }

    return 0;
}
