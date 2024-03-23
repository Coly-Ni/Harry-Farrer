#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int sexo;
    char corDeOlhos[15];
    float altura;
    float peso;
    char dataDeNascimento[11]; // Formato DD/MM/AAAA
} RegistroCadastro;

int main()
{
    FILE *arquivoCadastro = fopen("CADASTRO.txt", "r");
    FILE *arquivoHomens = fopen("HOMENS.txt", "w");
    FILE *arquivoMulheres = fopen("MULHERES.txt", "w");

    if (arquivoCadastro == NULL || arquivoHomens == NULL || arquivoMulheres == NULL)
    {
        fprintf(stderr, "Erro ao abrir os arquivos.\n");
        exit(1);
    }

    RegistroCadastro registro;
    while (fscanf(arquivoCadastro, "%49[^;];%d;%14[^;];%f;%f;%10[^\n]\n", registro.nome, &registro.sexo, registro.corDeOlhos, &registro.altura, &registro.peso, registro.dataDeNascimento) == 6)
    {
        if (registro.sexo == 1)
        {
            fprintf(arquivoHomens, "%s;%s;%.2f;%s\n", registro.nome, registro.corDeOlhos, registro.peso, registro.dataDeNascimento);
        }
        else if (registro.sexo == 2)
        {
            fprintf(arquivoMulheres, "%s;%s;%.2f;%s\n", registro.nome, registro.corDeOlhos, registro.peso, registro.dataDeNascimento);
        }
    }

    fclose(arquivoCadastro);
    fclose(arquivoHomens);
    fclose(arquivoMulheres);
    printf("Arquivos 'HOMENS.txt' e 'MULHERES.txt' gerados com sucesso.\n");

    return 0;
}
