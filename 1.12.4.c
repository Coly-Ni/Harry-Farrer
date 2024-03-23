#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[20];
    float precocompra, precovenda, valorcompra = 0, valorvenda = 0, lucro, lucrototal = 0;
    int lucroMenor10 = 0, lucroEntre10e20 = 0, lucroMaior20 = 0;

    do
    {
        printf("Digite o nome da mercadoria (ou -1 para sair), o valor de compra e o valor de venda:\n");
        scanf("%s", nome);
        if (strcmp(nome, "-1") == 0)
            break; // Flag para sair do loop
        scanf("%f%f", &precocompra, &precovenda);

        valorcompra += precocompra;
        valorvenda += precovenda;

        lucro = ((precovenda - precocompra) / precocompra) * 100;

        if (lucro < 10)
        {
            lucroMenor10++;
        }
        else if (lucro <= 20)
        {
            lucroEntre10e20++;
        }
        else
        {
            lucroMaior20++;
        }

        lucrototal += precovenda - precocompra; // Lucro total é a soma dos lucros individuais
    } while (1);

    printf("Quantidade de mercadorias com lucro menor que 10%%: %d\n", lucroMenor10);
    printf("Quantidade de mercadorias com lucro entre 10%% e 20%%: %d\n", lucroEntre10e20);
    printf("Quantidade de mercadorias com lucro maior que 20%%: %d\n", lucroMaior20);
    printf("Valor total de compra: %.2f\n", valorcompra);
    printf("Valor total de venda: %.2f\n", valorvenda);
    printf("Lucro total: %.2f\n", lucrototal);

    return 0;
}
