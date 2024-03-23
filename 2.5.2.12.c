#include <stdio.h>

#define MAX_ATIVIDADES 15
#define RECURSOS 7

int main()
{
    // Definindo as variáveis necessárias
    float custosUnitarios[RECURSOS];
    float percentualAdmin, lucro, leisSociais;
    int atividadesRealizadas = 0;
    float quantidades[MAX_ATIVIDADES][RECURSOS];
    float custoAtividades[MAX_ATIVIDADES];
    float precoVendaAtividades[MAX_ATIVIDADES];
    float custoTotalObra = 0, precoTotalObra = 0;

    // a) Ler o percentual de administração do mês
    printf("Insira o percentual de administracao do mes: ");
    scanf("%f", &percentualAdmin);

    // b) Ler os custos unitários dos sete recursos envolvidos
    printf("Insira os custos unitarios dos recursos (cimento, areia, brita, tijolo, pedreiro, servente, betoneira):\n");
    for (int i = 0; i < RECURSOS; i++)
    {
        scanf("%f", &custosUnitarios[i]);
    }

    // c) Ler o conjunto indeterminado de dados das atividades
    printf("Insira os quantitativos dos recursos para cada atividade (insira 0 para terminar):\n");
    for (int i = 0; i < MAX_ATIVIDADES; i++)
    {
        printf("Atividade %d:\n", i + 1);
        for (int j = 0; j < RECURSOS; j++)
        {
            scanf("%f", &quantidades[i][j]);
        }
        if (quantidades[i][0] == 0)
        { // Se o primeiro recurso (cimento) for 0, termina a leitura
            break;
        }
        atividadesRealizadas++;
    }

    // d.1) e d.2) Calcular e imprimir custo unitário e preço de venda de cada atividade
    printf("\nCustos e Precos de Venda por Atividade:\n");
    for (int i = 0; i < atividadesRealizadas; i++)
    {
        float custoDireto = 0;
        for (int j = 0; j < RECURSOS; j++)
        {
            custoDireto += quantidades[i][j] * custosUnitarios[j];
        }
        float custoAdmin = custoDireto * (percentualAdmin / 100);
        custoAtividades[i] = custoDireto + custoAdmin;
        leisSociais = custoDireto * 0.16;
        lucro = custoAtividades[i] * 0.36;
        precoVendaAtividades[i] = custoAtividades[i] + leisSociais + lucro;

        // Acumulando o custo e o preço total da obra
        custoTotalObra += custoAtividades[i];
        precoTotalObra += precoVendaAtividades[i];

        printf("Atividade %d: Custo Direto: %.2f, Custo com Admin: %.2f, Preco de Venda: %.2f\n",
               i + 1, custoDireto, custoAtividades[i], precoVendaAtividades[i]);
    }

    // d.3) e d.4) Imprimir o custo total e o preço total da obra
    printf("\nCusto Total da Obra: %.2f\n", custoTotalObra);
    printf("Preco Total da Obra: %.2f\n", precoTotalObra);

    return 0;
}
