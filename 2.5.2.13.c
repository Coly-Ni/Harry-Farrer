#include <stdio.h>
#define PERGUNTAS 100

int calcularAfinidade(int respostasRapaz[], int respostasMoca[])
{
    int afinidade = 0;
    for (int i = 0; i < PERGUNTAS; i++)
    {
        if (respostasRapaz[i] == respostasMoca[i])
        {
            afinidade++; // Incrementa a afinidade se as respostas forem iguais
        }
    }
    return afinidade;
}

int main()
{
    int R, M;

    // Ler os valores de R e M
    printf("Informe o numero de rapazes (R) e de mocas (M): ");
    scanf("%d %d", &R, &M);

    // Supondo que R e M estão dentro dos limites válidos (R <= 50 e M <= 60)
    int respostasRapazes[R][PERGUNTAS], respostasMocas[M][PERGUNTAS];

    // Ler as respostas dos rapazes
    for (int i = 0; i < R; i++)
    {
        printf("Respostas do rapaz %d:\n", i + 1);
        for (int j = 0; j < PERGUNTAS; j++)
        {
            scanf("%d", &respostasRapazes[i][j]);
        }
    }

    // Ler as respostas das moças
    for (int i = 0; i < M; i++)
    {
        printf("Respostas da moca %d:\n", i + 1);
        for (int j = 0; j < PERGUNTAS; j++)
        {
            scanf("%d", &respostasMocas[i][j]);
        }
    }

    // Calcular e imprimir a tabela de afinidades
    printf("Tabela de Afinidades:\n   ");
    for (int i = 0; i < M; i++)
    {
        printf("%3d ", i + 1); // Cabeçalho da tabela com o número das moças
    }
    printf("\n");

    for (int i = 0; i < R; i++)
    {
        printf("%2d ", i + 1); // Número do rapaz à esquerda da linha
        for (int j = 0; j < M; j++)
        {
            // Calcular afinidade entre o rapaz i e a moça j
            int afinidade = calcularAfinidade(respostasRapazes[i], respostasMocas[j]);
            printf("%3d ", afinidade);
        }
        printf("\n");
    }

    return 0;
}
