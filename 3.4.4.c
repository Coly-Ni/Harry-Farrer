#include <stdio.h>

#define MAX_DEZENAS 10

// Função para avaliar quantos acertos a aposta teve
int avaliaAposta(int dezenasSorteadas[5], int dezenasApostadas[], int qtdeApostada)
{
    int acertos = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < qtdeApostada; ++j)
        {
            if (dezenasSorteadas[i] == dezenasApostadas[j])
            {
                ++acertos;
            }
        }
    }
    return acertos;
}

int main()
{
    int dezenasSorteadas[5], dezenasApostadas[MAX_DEZENAS], numAposta, qtdeApostada;
    int contTerno = 0, contQuadra = 0, contQuina = 0;

    // Lendo as dezenas sorteadas
    printf("Digite as cinco dezenas sorteadas: ");
    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", &dezenasSorteadas[i]);
    }

    printf("Digite as apostas (número da aposta seguido pela quantidade de dezenas e pelas dezenas apostadas):\n");

    while (1)
    {
        scanf("%d", &numAposta);
        if (numAposta == 0)
            break; // Encerra a leitura das apostas

        scanf("%d", &qtdeApostada);
        for (int i = 0; i < qtdeApostada; ++i)
        {
            scanf("%d", &dezenasApostadas[i]);
        }

        // Avaliando a aposta
        int pontos = avaliaAposta(dezenasSorteadas, dezenasApostadas, qtdeApostada);

        // Contabiliza e imprime o resultado baseado no número de acertos
        if (pontos >= 3)
        {
            printf("Aposta número %d fez %d pontos.\n", numAposta, pontos);
        }

        if (pontos == 3)
        {
            contTerno++;
        }
        else if (pontos == 4)
        {
            contQuadra++;
        }
        else if (pontos == 5)
        {
            contQuina++;
        }
    }

    printf("Total de ternos: %d\n", contTerno);
    printf("Total de quadras: %d\n", contQuadra);
    printf("Total de quinas: %d\n", contQuina);

    return 0;
}
