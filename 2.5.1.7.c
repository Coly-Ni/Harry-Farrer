#include <stdio.h>

#define NUM_MERCADORIAS 100

int main()
{
    float precos[NUM_MERCADORIAS];
    int quantidades[NUM_MERCADORIAS];
    float faturamento = 0.0;
    int i;

    // Leitura da tabela de preços
    printf("Digite o preço de cada uma das 100 mercadorias:\n");
    for (i = 0; i < NUM_MERCADORIAS; i++)
    {
        printf("Mercadoria %d: ", i + 1);
        scanf("%f", &precos[i]);
    }

    // Leitura das quantidades vendidas
    printf("Digite a quantidade vendida para cada mercadoria:\n");
    for (i = 0; i < NUM_MERCADORIAS; i++)
    {
        printf("Quantidade vendida da mercadoria %d: ", i + 1);
        scanf("%d", &quantidades[i]);
    }

    // Cálculo do faturamento mensal
    for (i = 0; i < NUM_MERCADORIAS; i++)
    {
        faturamento += precos[i] * quantidades[i];
    }

    // Impressão do faturamento mensal
    printf("O faturamento mensal do armazém é: R$%.2f\n", faturamento);

    return 0;
}
