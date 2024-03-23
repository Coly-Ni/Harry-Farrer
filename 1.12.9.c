#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "");
    // Variáveis
    int criancas, mortes = 0, masc = 0, mesespor = 0, meses;
    char sexo[10];
    float porcenmortas, porcenmascmortas, porcenmeses;

    printf("Digite o número de crianças nascidas no período:\n");
    scanf("%d", &criancas);

    while (1)
    {
        printf("Digite o sexo da criança falecida (ou 'vazio' para encerrar):\n");
        scanf("%s", sexo);

        if (strcmp(sexo, "vazio") == 0)
        {
            break;
        }

        mortes++;
        printf("Digite a idade da criança falecida em meses:\n");
        scanf("%d", &meses);

        if (meses <= 24)
        {
            mesespor++;
        }

        if (strcmp(sexo, "masculino") == 0 || strcmp(sexo, "Masculino") == 0)
        {
            masc++;
        }
    }

    // Cálculos de porcentagens
    if (mortes > 0)
    {
        porcenmortas = ((float)mortes / criancas) * 100;
        porcenmascmortas = ((float)masc / mortes) * 100;
        porcenmeses = ((float)mesespor / mortes) * 100;
    }
    else
    {
        porcenmortas = 0;
        porcenmascmortas = 0;
        porcenmeses = 0;
    }

    printf("\nPorcentagem de crianças do sexo masculino falecidas: %.2f%%\n", porcenmascmortas);
    printf("Porcentagem de crianças falecidas com 24 meses ou menos: %.2f%%\n", porcenmeses);
    printf("Porcentagem total de crianças falecidas no período: %.2f%%\n", porcenmortas);

    return 0;
}
