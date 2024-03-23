#include <stdio.h>
#include <string.h>

#define MAX_PALAVRAS 1000
#define MAX_LEN 100

// Estrutura para armazenar o par de palavras
typedef struct
{
    char ingles[MAX_LEN];
    char portugues[MAX_LEN];
} Dicionario;

// Função para achar a tradução
char *traduzirPalavra(Dicionario dicionario[], int tamanho, char idioma, char *palavra)
{
    for (int i = 0; i < tamanho; ++i)
    {
        if ((idioma == 'I' && strcmp(dicionario[i].ingles, palavra) == 0) ||
            (idioma == 'P' && strcmp(dicionario[i].portugues, palavra) == 0))
        {
            if (idioma == 'I')
            {
                return dicionario[i].portugues;
            }
            else
            {
                return dicionario[i].ingles;
            }
        }
    }
    return NULL; // Palavra não encontrada
}

int main()
{
    Dicionario dicionario[MAX_PALAVRAS];
    char palavra[MAX_LEN], idioma;
    int indiceDicionario = 0;

    // Lendo o dicionário
    while (scanf("%s %s", dicionario[indiceDicionario].ingles, dicionario[indiceDicionario].portugues) == 2)
    {
        indiceDicionario++;
        if (indiceDicionario >= MAX_PALAVRAS)
        {
            break;
        }
    }

    // Lendo palavras para traduzir
    while (scanf(" %c %s", &idioma, palavra) == 2 && (idioma == 'I' || idioma == 'P'))
    {
        char *traducao = traduzirPalavra(dicionario, indiceDicionario, idioma, palavra);
        if (traducao)
        {
            printf("%s -> %s\n", palavra, traducao);
        }
        else
        {
            printf("Palavra '%s' não encontrada no dicionário.\n", palavra);
        }
    }

    return 0;
}
