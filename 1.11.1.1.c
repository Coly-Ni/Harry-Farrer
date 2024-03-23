#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    float N, QUADRADO;
    //iniciando as variaveis
    N = 10;
    do
    {
        QUADRADO = pow(N,2);
        printf("%.2f\n", QUADRADO);
        N = N-1;
    }
    while(N >= 1);
}
