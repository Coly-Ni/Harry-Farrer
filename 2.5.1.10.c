#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int NA, NB, NC;
    int A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE * 2];
    int iA, iB, iC;

    // a) Leia NA, número de elementos do conjunto A
    printf("Digite o número de elementos do conjunto A (NA <= 100): ");
    scanf("%d", &NA);

    // b) Leia os elementos do conjunto A
    printf("Digite os elementos ordenados do conjunto A:\n");
    for (iA = 0; iA < NA; iA++)
    {
        scanf("%d", &A[iA]);
    }

    // c) Leia o valor de NB, número de elementos do conjunto B
    printf("Digite o número de elementos do conjunto B (NB <= 100): ");
    scanf("%d", &NB);

    // d) Leia os elementos do conjunto B
    printf("Digite os elementos ordenados do conjunto B:\n");
    for (iB = 0; iB < NB; iB++)
    {
        scanf("%d", &B[iB]);
    }

    // e) Criar e imprimir o conjunto C, ordenado
    iA = iB = iC = 0;
    while (iA < NA && iB < NB)
    {
        if (A[iA] < B[iB])
        {
            C[iC++] = A[iA++];
        }
        else
        {
            C[iC++] = B[iB++];
        }
    }

    // Se ainda houver elementos em A, adicione ao conjunto C
    while (iA < NA)
    {
        C[iC++] = A[iA++];
    }

    // Se ainda houver elementos em B, adicione ao conjunto C
    while (iB < NB)
    {
        C[iC++] = B[iB++];
    }

    // Impressão do conjunto C
    NC = NA + NB;
    printf("Conjunto C intercalado e ordenado:\n");
    for (iC = 0; iC < NC; iC++)
    {
        printf("%d ", C[iC]);
    }
    printf("\n");

    return 0;
}
