#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ELEMENTOS 250

bool saoDisjuntos(int conjuntoA[], int tamA, int conjuntoB[], int tamB)
{
    for (int i = 0; i < tamA; i++)
    {
        for (int j = 0; j < tamB; j++)
        {
            if (conjuntoA[i] == conjuntoB[j])
            {
                return false; // Os conjuntos não são disjuntos.
            }
        }
    }
    return true; // Os conjuntos são disjuntos.
}

int main()
{
    char identificador[51];
    int conjuntoA[MAX_ELEMENTOS], conjuntoB[MAX_ELEMENTOS];
    int nA, nB;

    while (true)
    {
        printf("Digite o identificador do par de conjuntos (ou 'VAZIO' para terminar): ");
        scanf("%s", identificador);

        if (strcmp(identificador, "VAZIO") == 0)
        {
            break; // Encerra o programa se o identificador for "VAZIO".
        }

        printf("Digite o número de elementos do conjunto A: ");
        scanf("%d", &nA);
        printf("Digite os elementos do conjunto A:\n");
        for (int i = 0; i < nA; i++)
        {
            scanf("%d", &conjuntoA[i]);
        }

        printf("Digite o número de elementos do conjunto B: ");
        scanf("%d", &nB);
        printf("Digite os elementos do conjunto B:\n");
        for (int i = 0; i < nB; i++)
        {
            scanf("%d", &conjuntoB[i]);
        }

        if (saoDisjuntos(conjuntoA, nA, conjuntoB, nB))
        {
            printf("Os conjuntos identificados por '%s' são disjuntos.\n", identificador);
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}
