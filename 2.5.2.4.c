#include <stdio.h>

int main()
{
    int A[2][4] = {
        {7, 8, 4, 9},
        {2, 1, 7, 3}};
    int B[2][4] = {
        {6, 9, 11, 15},
        {32, 19, 3, 4}};
    int C[2][4];
    int i, j;

    // Calculando o conjunto C = A + B
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Imprimindo o conjunto C
    printf("Conjunto C = A + B:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
