#include <stdio.h>

int main()
{
    // a) Inicializando a matriz A com os valores fornecidos.
    double A[5][5] = {
        {175, 225, 10, 9000, 3.7},
        {9.8, 100, 363, 432, 156},
        {40, 301, 30.2, 6381, 1},
        {402, 4211, 7213, 992, 442},
        {21, 3, 2, 1, 9000}};

    // b) Imprimindo o conteúdo do elemento A[4][5].
    printf("Elemento A[4][5]: %.2f\n", A[3][4]); // Índices em C baseados em 0

    // c) Calculando o conteúdo de X
    double X = A[2][1] + A[4][0]; // Índices ajustados para base 0
    printf("Conteúdo de X: %.2f\n", X);

    // d) Se A[6][2] fosse referenciado, isso resultaria em acesso fora dos limites da matriz.

    // e) Somando os elementos da quarta coluna
    double sumColumn4 = 0;
    for (int i = 0; i < 5; i++)
    {
        sumColumn4 += A[i][3]; // Índice da coluna é 3 porque C começa a contar do 0
    }
    printf("Soma da quarta coluna: %.2f\n", sumColumn4);

    // f) Somando os elementos da terceira linha
    double sumLine3 = 0;
    for (int i = 0; i < 5; i++)
    {
        sumLine3 += A[2][i]; // Índice da linha é 2 porque C começa a contar do 0
    }
    printf("Soma da terceira linha: %.2f\n", sumLine3);

    return 0;
}
