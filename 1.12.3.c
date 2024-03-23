#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float c, i;
    for (i = 50; i <= 150; i++)
    {
        c = 5.0 / 9.0 * (i - 32);
        printf("|%.2f| em Fahrenheit equivale a |%.2f| em Celsius\n", i, c);
    }

    return 0;
}
