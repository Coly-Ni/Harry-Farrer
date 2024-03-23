#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numeroCliente;
    char codigoOperacao; // 'C' para compra e 'V' para venda
    char descricao[100];
    int quantidade;
    float valorUnitario;
} RegistroBoleta;

typedef struct
{
    int numeroCliente;
    float saldoApurado;
    char tipoSaldo; // 'C' para credor e 'D' para devedor
} RegistroResultado;

// Protótipo da função que processa os registros
void processaRegistros(const char *nomeArquivoEntrada, const char *nomeArquivoSaida);

int main()
{
    processaRegistros("BOLETA.txt", "RESULTADO.txt");
    printf("Arquivo de resultado gerado com sucesso.\n");
    return 0;
}

void processaRegistros(const char *nomeArquivoEntrada, const char *nomeArquivoSaida)
{
    FILE *entrada = fopen(nomeArquivoEntrada, "r");
    FILE *saida = fopen(nomeArquivoSaida, "w");
    RegistroBoleta registroAtual;
    RegistroResultado resultado;
    int numeroClienteAtual = -1;
    float saldo = 0;

    if (entrada == NULL || saida == NULL)
    {
        fprintf(stderr, "Erro ao abrir os arquivos.\n");
        exit(1);
    }

    while (fscanf(entrada, "%d %c %*s %d %f", &registroAtual.numeroCliente,
                  &registroAtual.codigoOperacao, &registroAtual.quantidade,
                  &registroAtual.valorUnitario) == 4)
    {
        // Se é o primeiro registro ou ainda está no mesmo cliente
        if (numeroClienteAtual == -1 || numeroClienteAtual == registroAtual.numeroCliente)
        {
            // Acumula o saldo
            saldo += (registroAtual.codigoOperacao == 'C' ? -1 : 1) * registroAtual.quantidade * registroAtual.valorUnitario;
        }
        else
        {
            // Escreve o saldo do cliente anterior
            fprintf(saida, "%d %.2f %c\n", numeroClienteAtual, saldo, saldo >= 0 ? 'C' : 'D');

            // Reseta o saldo para o novo cliente
            saldo = (registroAtual.codigoOperacao == 'C' ? -1 : 1) * registroAtual.quantidade * registroAtual.valorUnitario;
        }
        // Atualiza o número do cliente atual
        numeroClienteAtual = registroAtual.numeroCliente;
    }

    // Escreve o saldo do último cliente
    if (numeroClienteAtual != -1)
    {
        fprintf(saida, "%d %.2f %c\n", numeroClienteAtual, saldo, saldo >= 0 ? 'C' : 'D');
    }

    fclose(entrada);
    fclose(saida);
}
