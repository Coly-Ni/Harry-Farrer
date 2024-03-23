#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Incluído para usar a função fabs()

// Função para calcular os pontos de uma equipe baseada na diferença de tempo
int calcularPontos(double tempoPadrao, double tempoEquipe)
{
    double delta = fabs(tempoPadrao - tempoEquipe); // Calcula a diferença absoluta
    if (delta < 3)
        return 100; // Menos de 3 minutos de diferença
    if (delta <= 5)
        return 80; // Entre 3 e 5 minutos de diferença
    // Mais de 5 minutos de diferença, subtrai 5 e multiplica a diferença por 5, depois subtrai de 80
    return (int)(80 - (delta - 5) * 5); // Arredonda e retorna como inteiro
}

int main()
{
    double tempoPadrao[3];                  // Armazena os tempos padrão das 3 etapas
    int numeroInscricao;                    // Armazena o número de inscrição da equipe
    double tempoEquipe[3];                  // Armazena os tempos da equipe para cada uma das 3 etapas
    int pontosEtapa[3], pontosTotais;       // Armazena os pontos da equipe para cada etapa e o total
    int vencedora = 0, pontosVencedora = 0; // Identifica a equipe vencedora e seus pontos

    // Lê os tempos padrão das 3 etapas
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf", &tempoPadrao[i]);
    }

    // Processa as equipes até encontrar o número de inscrição 9999
    while (scanf("%d", &numeroInscricao) && numeroInscricao != 9999)
    {
        pontosTotais = 0; // Zera os pontos totais para a nova equipe

        // Lê os tempos e calcula os pontos para cada uma das 3 etapas
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf", &tempoEquipe[i]);
            pontosEtapa[i] = calcularPontos(tempoPadrao[i], tempoEquipe[i]);
            pontosTotais += pontosEtapa[i]; // Soma os pontos da etapa ao total
        }

        // Atualiza a equipe vencedora se necessário
        if (pontosTotais > pontosVencedora)
        {
            vencedora = numeroInscricao;
            pontosVencedora = pontosTotais;
        }

        // Imprime os pontos de cada etapa e o total para a equipe atual
        printf("Equipe %d: Etapa 1: %d pontos, Etapa 2: %d pontos, Etapa 3: %d pontos, Total: %d pontos\n",
               numeroInscricao, pontosEtapa[0], pontosEtapa[1], pontosEtapa[2], pontosTotais);
    }

    // Imprime a equipe vencedora
    printf("A equipe vencedora é a equipe %d com um total de %d pontos.\n", vencedora, pontosVencedora);

    return 0;
}
