#include <stdio.h>

#define NUM_VOOS 10
#define LIMITE_LUCRO 0.6

typedef struct
{
    int numeroVoo;
    int capacidade;
    double precoPassagem;
    int lugaresDisponiveis;
} Voo;

// Função para encontrar o índice do voo com base no número do voo
int encontrarIndiceVoo(Voo voos[], int numVoo)
{
    for (int i = 0; i < NUM_VOOS; i++)
    {
        if (voos[i].numeroVoo == numVoo)
        {
            return i;
        }
    }
    return -1; // Retorna -1 se o voo não for encontrado
}

int main()
{
    Voo voos[NUM_VOOS];
    int numVoo, capacidade, indiceVoo;
    double precoPassagem, totalLucro = 0, lucroVoo;

    // Inicialização dos voos
    for (int i = 0; i < NUM_VOOS; i++)
    {
        printf("Insira o numero do voo, capacidade e preco da passagem para o voo %d:\n", i + 1);
        scanf("%d %d %lf", &numVoo, &capacidade, &precoPassagem);
        voos[i].numeroVoo = numVoo;
        voos[i].capacidade = capacidade;
        voos[i].precoPassagem = precoPassagem;
        voos[i].lugaresDisponiveis = capacidade;
    }

    // Processamento das reservas
    int idPassageiro;
    printf("Insira o ID do passageiro e o numero do voo para a reserva (0 para terminar):\n");
    while (1)
    {
        scanf("%d", &idPassageiro);
        if (idPassageiro == 0)
            break; // Flag para terminar o loop
        scanf("%d", &numVoo);
        indiceVoo = encontrarIndiceVoo(voos, numVoo);

        if (indiceVoo != -1 && voos[indiceVoo].lugaresDisponiveis > 0)
        {
            voos[indiceVoo].lugaresDisponiveis--;
            printf("RESERVA CONFIRMADA\n");
        }
        else
        {
            printf("VOO LOTADO\n");
        }
    }

    // Cálculo e impressão dos lucros e prejuízos
    printf("\nEstatisticas de lucros e prejuizos por voo e no total da companhia aerea:\n");
    for (int i = 0; i < NUM_VOOS; i++)
    {
        lucroVoo = (voos[i].capacidade - voos[i].lugaresDisponiveis) * voos[i].precoPassagem;
        if (lucroVoo / (voos[i].capacidade * voos[i].precoPassagem) < LIMITE_LUCRO)
        {
            printf("Voo %d: Prejuizo\n", voos[i].numeroVoo);
        }
        else
        {
            printf("Voo %d: Lucro\n", voos[i].numeroVoo);
        }
        totalLucro += lucroVoo;
    }

    printf("\nLucro total da companhia: %.2lf\n", totalLucro);

    return 0;
}
