#include <stdio.h>

#define MAX_CIDADES 30
#define MAX_PERCURSO 24

int main()
{
    // Substitua com os valores reais de distâncias entre as cidades
    int tabelaDistancias[MAX_CIDADES][MAX_CIDADES] = {
        {0, 10, 20, 30, 40, /* ... continuação dos dados ... */},
        {10, 0, 15, 25, 35, /* ... continuação dos dados ... */},
        {20, 15, 0, 35, 45, /* ... continuação dos dados ... */},
        // ... demais linhas da matriz ...
    };

    int numeroOnibus, numeroCidades;
    int percurso[MAX_PERCURSO];
    int distanciaTotal = 0;

    // Leitura do número do ônibus
    printf("Digite o número do ônibus: ");
    scanf("%d", &numeroOnibus);

    // Leitura do número de cidades
    printf("Digite o número de cidades percorridas: ");
    scanf("%d", &numeroCidades);

    if (numeroCidades > MAX_PERCURSO)
    {
        printf("Número de cidades excede o máximo permitido.\n");
        return 1;
    }

    // Leitura das cidades no percurso
    printf("Digite os códigos das %d cidades percorridas em ordem:\n", numeroCidades);
    for (int i = 0; i < numeroCidades; i++)
    {
        printf("Cidade %d: ", i + 1);
        scanf("%d", &percurso[i]);
        if (percurso[i] < 1 || percurso[i] > MAX_CIDADES)
        {
            printf("Código de cidade inválido.\n");
            return 1;
        }
    }

    // Cálculo da distância total
    for (int i = 0; i < numeroCidades - 1; i++)
    {
        int origem = percurso[i] - 1;      // Ajuste do índice
        int destino = percurso[i + 1] - 1; // Ajuste do índice
        distanciaTotal += tabelaDistancias[origem][destino];
    }

    // Impressão do resultado
    printf("Distância total percorrida pelo ônibus número %d é: %d km\n", numeroOnibus, distanciaTotal);

    return 0;
}
