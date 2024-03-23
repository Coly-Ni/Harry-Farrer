#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int numeroConta;
    float saldo; // Saldo atual da conta
} Conta;

typedef struct
{
    int numeroConta;
    char codigoOperacao; // 'D' para débito, 'C' para crédito
    float valorOperacao;
    char dataOperacao[11]; // Formato "AAAA-MM-DD"
} Registro;

bool lerConta(FILE *arquivo, Conta *conta)
{
    return fscanf(arquivo, "%d %f\n", &conta->numeroConta, &conta->saldo) != EOF;
}

void atualizarConta(Conta *conta, Registro *reg)
{
    if (reg->codigoOperacao == 'D')
    {
        conta->saldo -= reg->valorOperacao; // Débito: subtrai do saldo
    }
    else if (reg->codigoOperacao == 'C')
    {
        conta->saldo += reg->valorOperacao; // Crédito: adiciona ao saldo
    }
}

void atualizarContasCorrentes(const char *arquivoIntercalado, const char *arquivoContas, const char *arquivoContasAtualizado)
{
    FILE *intercalado = fopen(arquivoIntercalado, "r");
    FILE *contas = fopen(arquivoContas, "r");
    FILE *contasAtualizado = fopen(arquivoContasAtualizado, "w");

    Registro reg;
    Conta conta;
    bool temRegistro = lerRegistro(intercalado, &reg);
    bool temConta = lerConta(contas, &conta);

    while (temRegistro && temConta)
    {
        if (conta.numeroConta == reg.numeroConta)
        {
            atualizarConta(&conta, &reg);
            temRegistro = lerRegistro(intercalado, &reg); // Lê próximo registro
        }
        else
        {
            fprintf(contasAtualizado, "%d %f\n", conta.numeroConta, conta.saldo);
            temConta = lerConta(contas, &conta); // Avança para a próxima conta
        }
    }

    // Certifica-se de que todas as contas restantes são escritas no arquivo atualizado
    while (temConta)
    {
        fprintf(contasAtualizado, "%d %f\n", conta.numeroConta, conta.saldo);
        temConta = lerConta(contas, &conta);
    }

    fclose(intercalado);
    fclose(contas);
    fclose(contasAtualizado);
}

int main()
{
    atualizarContasCorrentes("contasCorrentesAtualizadas.txt", "contasCorrentes.txt", "contasCorrentesFinal.txt");
    return 0;
}
