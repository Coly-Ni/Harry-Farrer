#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    // variaveis
    float idade, media, soma;
    int i;
    // inicializando as variaveis
    i = 0;
    media = 0;
    soma = 0;
    do
    {
        printf("digite a sua idade:\n");
        scanf("%f", &idade);
        if (idade > 0)
        {
            i++;
            soma = soma + idade;
        }
    } while (idade > 0);
    // calculando a media
    if (soma > 0)
    {
        media = soma / i;
    }
    printf("a media das idades �:%.2f", media);
    return 0;
}
