#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    float A,B,C,MAT,X,XX,Y,YY;
    //iniciando as variaveis
    X = 0;
    XX = 0;
    Y = 0;
    YY = 0;
    A = 2;
    B = 5;
    C = 4;
    printf("escreva o ultimo algarismo do dia em que você nasceu:");
    scanf("%f", &MAT);
    if (MAT>= 5)
    {
        X = pow((A+B),1/2) + C/2 * A;
        Y = fmod(B,A)/A - (C/pow(B,2));
    }
    else
    {
        XX = (B/A)/pow(A,2) + fmod(pow(B,2), C);
        YY = A/2 * C + pow((3 + A), 2)/A;

    }
    printf("%.2f\n%.2f\n%.2f\n%.2f\n",X,XX,Y,YY );
}
