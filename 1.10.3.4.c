#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    float A, B, I, M;
    printf("digite um numero:");
    scanf("%f", &M);

    if(M != 0)
    {
        I = truncf(M/2); //15
        A = M/2; //15
        B = round(M/2); //15
        if (fmod(M,(float)2)>= 6)
        {
            I = I++;
        }
        printf("%.2f\n%.2f\n%.2f\n", A, B, I);
    }
}
