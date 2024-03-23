#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "");

    // Variáveis
    int D;           // Dia
    int M;           // Mês
    int A;           // Ultimos dois dígitos do ano
    int S;           // Primeiros dois dígitos do ano
    int i;           // Auxiliar
    int ANO;         // Recebe o ajuste do ano e o mês se for janeiro ou fevereiro
    int MES;         // Mes que o usuário digitou
    int diadasemana; // Recebe o cálculo do dia da semana
    int ANO_REAL;    // Variável para armazenar o ano inserido pelo usuário

    for (i = 0; i < 50; i++)
    {
        printf("Digite um dia do mês: ");
        scanf("%d", &D);
        printf("Digite o mês: ");
        scanf("%d", &MES);
        printf("Digite o ano: ");
        scanf("%d", &ANO_REAL);

        // Ajusta o ano e o mês se for janeiro ou fevereiro
        ANO = ANO_REAL;
        M = MES;
        if (M < 3)
        {
            M += 12;
            ANO--;
        }

        // A recebe os 2 últimos dígitos do ano
        A = ANO % 100;

        // S recebe os 2 primeiros dígitos do ano
        S = ANO / 100;

        // Cálculo do dia da semana
        diadasemana = (int)(D + floor(2.6 * M - 0.2) - 2 * S + A + floor(A / 4.0) + floor(S / 4.0)) % 7;

        // Ajuste do resultado para que domingo seja 0 e sábado 6
        diadasemana = (diadasemana + 6) % 7;

        // Conversão de dias da semana para texto
        switch (diadasemana)
        {
        case 0:
            printf("Domingo\n");
            break;
        case 1:
            printf("Segunda-feira\n");
            break;
        case 2:
            printf("Terça-feira\n");
            break;
        case 3:
            printf("Quarta-feira\n");
            break;
        case 4:
            printf("Quinta-feira\n");
            break;
        case 5:
            printf("Sexta-feira\n");
            break;
        case 6:
            printf("Sábado\n");
            break;
        }

        // Escrevendo os resultados
        printf("%d/%d/%d é um(a) ", D, MES, ANO_REAL);
        switch (diadasemana)
        {
        case 0:
            printf("Domingo\n");
            break;
        case 1:
            printf("Segunda-feira\n");
            break;
        case 2:
            printf("Terça-feira\n");
            break;
        case 3:
            printf("Quarta-feira\n");
            break;
        case 4:
            printf("Quinta-feira\n");
            break;
        case 5:
            printf("Sexta-feira\n");
            break;
        case 6:
            printf("Sábado\n");
            break;
        }
    }

    return 0;
}
