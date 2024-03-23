#include <stdio.h>

int main()
{
    int total_pessoas = 2000;
    int feminino_sim = 0, feminino_nao = 0, masculino_sim = 0, masculino_nao = 0;
    char sexo, resposta;

    for (int i = 0; i < total_pessoas; i++)
    {
        printf("Sexo da pessoa #%d (F/M): ", i + 1);
        scanf(" %c", &sexo);
        printf("Resposta da pessoa #%d (S/N): ", i + 1);
        scanf(" %c", &resposta);

        if (sexo == 'F' || sexo == 'f')
        {
            if (resposta == 'S' || resposta == 's')
                feminino_sim++;
            else
                feminino_nao++;
        }
        else if (sexo == 'M' || sexo == 'm')
        {
            if (resposta == 'S' || resposta == 's')
                masculino_sim++;
            else
                masculino_nao++;
        }
    }

    printf("Número de pessoas que responderam sim: %d\n", feminino_sim + masculino_sim);
    printf("Número de pessoas que responderam não: %d\n", feminino_nao + masculino_nao);
    printf("Percentagem de mulheres que responderam sim: %.2f%%\n", (feminino_sim / (float)total_pessoas) * 100);
    printf("Percentagem de homens que responderam não: %.2f%%\n", (masculino_nao / (float)total_pessoas) * 100);

    return 0;
}
