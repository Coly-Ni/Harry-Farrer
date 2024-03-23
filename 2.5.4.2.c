#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do Registro.
typedef struct
{
    char nome[50];
    char endereco[100];
    char cep[10];
    char telefone[15];
} Registro;

int main()
{
    FILE *arquivo;
    Registro reg;

    // Tenta abrir o arquivo "DADOS.txt" para leitura.
    arquivo = fopen("DADOS.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo DADOS.txt");
        return EXIT_FAILURE;
    }

    printf("Listando os registros do arquivo 'DADOS':\n\n");

    // Lendo e imprimindo os registros.
    while (fscanf(arquivo, "%49[^;];%99[^;];%9[^;];%14[^\n]\n", reg.nome, reg.endereco, reg.cep, reg.telefone) == 4)
    {
        printf("Nome: %s\n", reg.nome);
        printf("Endereço: %s\n", reg.endereco);
        printf("CEP: %s\n", reg.cep);
        printf("Telefone: %s\n\n", reg.telefone);
    }

    // Fechando o arquivo.
    fclose(arquivo);

    return EXIT_SUCCESS;
}
