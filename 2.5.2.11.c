#include <stdio.h>

#define ESTADOS 23
#define MUNICIPIOS 10

int main()
{
    int populacao[ESTADOS][MUNICIPIOS];
    int estadoMaisPopuloso, municipioMaisPopuloso, populacaoMaior = -1;
    double somaPopulacaoCapitais = 0.0;

    // Leitura dos dados
    for (int i = 0; i < ESTADOS; i++)
    {
        printf("Digite a populacao dos 10 municipios mais populosos do estado %d:\n", i + 1);
        for (int j = 0; j < MUNICIPIOS; j++)
        {
            scanf("%d", &populacao[i][j]);

            // Checagem do município mais populoso
            if (populacao[i][j] > populacaoMaior)
            {
                populacaoMaior = populacao[i][j];
                estadoMaisPopuloso = i;
                municipioMaisPopuloso = j;
            }

            // Soma das populações das capitais (primeira coluna)
            if (j == 0)
            {
                somaPopulacaoCapitais += populacao[i][j];
            }
        }
    }

    // Cálculo da média
    double mediaPopulacaoCapitais = somaPopulacaoCapitais / ESTADOS;

    // Impressão dos resultados
    printf("\nPopulacoes dos municipios:\n");
    for (int i = 0; i < ESTADOS; i++)
    {
        for (int j = 0; j < MUNICIPIOS; j++)
        {
            printf("%d ", populacao[i][j]);
        }
        printf("\n");
    }

    printf("\nMunicipio mais populoso: %d, Estado: %d, Populacao: %d\n",
           municipioMaisPopuloso + 1, estadoMaisPopuloso + 1, populacaoMaior);
    printf("Media da populacao das capitais: %.2f\n", mediaPopulacaoCapitais);

    return 0;
}
