#include <stdio.h>
#include <string.h>

// Suponha que estas são as estruturas dos registros RS e RM
typedef struct
{
    int codigo;    // Código do registro, será 1 para RS
    char nome[50]; // Nome do cliente
    double saldo;  // Saldo disponível
} RegistroRS;

typedef struct
{
    int codigo;          // Código do registro, será 2 ou 3 para RM
    char nome[50];       // Nome do cliente
    double movimentacao; // Valor da movimentação, positivo para depósitos e negativo para retiradas
} RegistroRM;

// Função para processar o arquivo de entrada e gerar o arquivo de saída
void processaArquivo()
{
    RegistroRS rs;
    RegistroRM rm;
    FILE *entrada, *saida;

    // Abre os arquivos de entrada e saída
    entrada = fopen("ENTRADA.txt", "r");
    saida = fopen("SAIDA.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        perror("Erro ao abrir os arquivos");
        return;
    }

    // Lê o primeiro registro do arquivo
    while (fscanf(entrada, "%d %s %lf", &rs.codigo, rs.nome, &rs.saldo) != EOF)
    {
        if (rs.codigo == 1)
        { // Se o registro for do tipo RS
            // Lê os registros RM seguintes correspondentes a esse cliente e atualiza o saldo
            while (fscanf(entrada, "%d %s %lf", &rm.codigo, rm.nome, &rm.movimentacao) != EOF && strcmp(rm.nome, rs.nome) == 0)
            {
                if (rm.codigo == 2)
                { // Depósito
                    rs.saldo += rm.movimentacao;
                }
                else if (rm.codigo == 3)
                { // Retirada
                    rs.saldo -= rm.movimentacao;
                }
            }
            // Escreve o registro RS atualizado no arquivo de saída
            fprintf(saida, "%d %s %.2f\n", rs.codigo, rs.nome, rs.saldo);
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);
}

int main()
{
    processaArquivo();
    printf("Arquivo processado e saída gerada com sucesso.\n");
    return 0;
}
