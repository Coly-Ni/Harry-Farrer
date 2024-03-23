#include <stdio.h>
#include <stdbool.h>

#define MAX_CARACTERES 100
#define NUM_CONJUNTOS 50

// Sub-rotina para determinar a interseção de dois conjuntos de caracteres
void intersecao(char conjuntoA[], char conjuntoB[], char interseccao[])
{
    int pos = 0;
    for (int i = 0; conjuntoA[i] != '\0' && pos < MAX_CARACTERES; ++i)
    {
        for (int j = 0; conjuntoB[j] != '\0'; ++j)
        {
            if (conjuntoA[i] == conjuntoB[j])
            {
                interseccao[pos++] = conjuntoA[i];
                break;
            }
        }
    }
    interseccao[pos] = '\0'; // Encerra a string
}

// Sub-rotina para determinar a união de dois conjuntos de caracteres
void uniao(char conjuntoA[], char conjuntoB[], char uniao[])
{
    int pos = 0;
    bool estaPresente;

    // Adiciona todos os caracteres do conjuntoA na união
    for (int i = 0; conjuntoA[i] != '\0'; ++i)
    {
        uniao[pos++] = conjuntoA[i];
    }

    // Adiciona os caracteres de conjuntoB que não estão em conjuntoA
    for (int i = 0; conjuntoB[i] != '\0'; ++i)
    {
        estaPresente = false;
        for (int j = 0; conjuntoA[j] != '\0'; ++j)
        {
            if (conjuntoB[i] == conjuntoA[j])
            {
                estaPresente = true;
                break;
            }
        }
        if (!estaPresente)
        {
            uniao[pos++] = conjuntoB[i];
        }
    }
    uniao[pos] = '\0'; // Encerra a string
}

int main()
{
    char conjuntoA[NUM_CONJUNTOS][MAX_CARACTERES];
    char conjuntoB[NUM_CONJUNTOS][MAX_CARACTERES];
    char resultadoInterseccao[MAX_CARACTERES];
    char resultadoUniao[2 * MAX_CARACTERES]; // Pode conter todos os caracteres de ambos os conjuntos

    // Leitura dos conjuntos seria implementada aqui

    for (int i = 0; i < NUM_CONJUNTOS; ++i)
    {
        intersecao(conjuntoA[i], conjuntoB[i], resultadoInterseccao);
        uniao(conjuntoA[i], conjuntoB[i], resultadoUniao);

        printf("Conjunto A %d: %s\n", i + 1, conjuntoA[i]);
        printf("Conjunto B %d: %s\n", i + 1, conjuntoB[i]);
        printf("Interseção: %s\n", resultadoInterseccao);
        printf("União: %s\n\n", resultadoUniao);
    }

    return 0;
}
