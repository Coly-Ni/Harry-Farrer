#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100 // Supondo um número máximo de 100 pessoas
#define PERGUNTAS 10
#define OPCOES 5
#define TAM_NOME 50 // Supondo que o nome tenha até 49 caracteres + terminador nulo

int main()
{
    char nomes[MAX_PESSOAS][TAM_NOME];
    int respostas[MAX_PESSOAS][PERGUNTAS];
    int contagem_respostas[PERGUNTAS][OPCOES] = {0};
    int num_pessoas = 0;

    // Ler nomes e respostas
    while (1)
    {
        printf("Insira o nome da pessoa (ou VAZIO para terminar): ");
        scanf("%49s", nomes[num_pessoas]); // Ler no máximo 49 caracteres + terminador nulo
        if (strcmp(nomes[num_pessoas], "VAZIO") == 0)
        {
            break;
        }

        printf("Insira as respostas das 10 perguntas (1 a 5):\n");
        for (int i = 0; i < PERGUNTAS; i++)
        {
            scanf("%d", &respostas[num_pessoas][i]);
            // Incrementar a contagem da resposta
            if (respostas[num_pessoas][i] >= 1 && respostas[num_pessoas][i] <= OPCOES)
            {
                contagem_respostas[i][respostas[num_pessoas][i] - 1]++;
            }
        }
        num_pessoas++;
    }

    // Imprimir respostas
    printf("\nRespostas:\n");
    for (int i = 0; i < num_pessoas; i++)
    {
        printf("%s respondeu: ", nomes[i]);
        for (int j = 0; j < PERGUNTAS; j++)
        {
            printf("%d ", respostas[i][j]);
        }
        printf("\n");
    }

    // Imprimir a contagem de respostas para cada opção
    printf("\nContagem de respostas por pergunta e opcao:\n");
    for (int i = 0; i < PERGUNTAS; i++)
    {
        printf("Pergunta %d:\n", i + 1);
        for (int j = 0; j < OPCOES; j++)
        {
            printf("Opcao %d: %d resposta(s)\n", j + 1, contagem_respostas[i][j]);
        }
    }

    return 0;
}
