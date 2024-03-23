#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char numeroConta[12]; // Inclui espaço para o dígito verificador e o caractere nulo de término
    double saldo;
    char nomeCliente[MAX_NAME_LENGTH];
} ContaBancaria;

bool verificarDigito(char *numeroConta)
{
    int pesos[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Pesos de 2 a 11 para os 10 primeiros dígitos
    int soma = 0, i, digitoCalculado;

    // Calcula a soma dos dígitos multiplicados pelos pesos, excluindo o dígito verificador
    for (i = 0; i < 10; i++)
    {
        soma += (numeroConta[i] - '0') * pesos[i]; // '0' é usado para converter o caractere para o inteiro correspondente
    }

    digitoCalculado = (soma % 11) == 10 ? 0 : soma % 11; // O dígito é 0 se o resto for 10, caso contrário é o próprio resto

    // Retorna verdadeiro se o dígito verificador calculado corresponder ao último dígito do número da conta
    return digitoCalculado == (numeroConta[10] - '0');
}

int main()
{
    ContaBancaria contas[MAX_ACCOUNTS];
    int numContas = 0;

    // Lê as contas bancárias
    while (scanf("%s", contas[numContas].numeroConta) == 1 && contas[numContas].numeroConta[0] != '0')
    {
        scanf("%lf %s", &contas[numContas].saldo, contas[numContas].nomeCliente);
        numContas++;
    }

    printf("CONTAS DE NÚMERO CORRETO:\n");
    for (int i = 0; i < numContas; i++)
    {
        if (verificarDigito(contas[i].numeroConta))
        {
            printf("%s $%.2f %s\n", contas[i].numeroConta, contas[i].saldo, contas[i].nomeCliente);
        }
    }

    printf("\nCONTAS DE NÚMERO ERRADO:\n");
    for (int i = 0; i < numContas; i++)
    {
        if (!verificarDigito(contas[i].numeroConta))
        {
            printf("%s $%.2f %s\n", contas[i].numeroConta, contas[i].saldo, contas[i].nomeCliente);
        }
    }

    return 0;
}
