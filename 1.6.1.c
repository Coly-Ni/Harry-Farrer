#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    char A[] = "BENS";
    char B[] = "!";
    char C[5] = "PARA";
    //iniciando as variaveis

    printf("a) %s %s %s\n", A,B, C );
    printf("b) %s %s %s\n", A,C, B );
    printf("c) %s %s %s\n", C,A, B );
}
