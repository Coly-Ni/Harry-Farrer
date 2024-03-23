#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main ()
{
    //variaveis

    int i;
    int j;
    int s;

    //iniciando
    s = 0;
    j = 1;

    //calculo

    for(i = 1; i < 5; i = i + 2)
    {
        s = s + i / j;
        j++;
    }

    //escrevendo resultado
    printf("%d", s);
}
