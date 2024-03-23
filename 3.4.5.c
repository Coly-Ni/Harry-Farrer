#include <stdio.h>
#include <string.h>

// Função para calcular os dígitos verificadores de um CPF
int calculaDigitoVerificador(char *cpfBase)
{
    int soma = 0, digito1, digito2, i, j, resultado1, resultado2;

    // Cálculo do primeiro dígito verificador
    for (i = 0, j = 10; i < 9; i++, j--)
    {
        soma += (cpfBase[i] - '0') * j;
    }
    resultado1 = soma % 11;
    digito1 = (resultado1 < 2) ? 0 : 11 - resultado1;

    soma = 0;

    // Cálculo do segundo dígito verificador
    for (i = 0, j = 11; i < 9; i++, j--)
    {
        soma += (cpfBase[i] - '0') * j;
    }
    soma += digito1 * 2;
    resultado2 = soma % 11;
    digito2 = (resultado2 < 2) ? 0 : 11 - resultado2;

    // Retorna os dois dígitos calculados como um inteiro de dois dígitos
    return digito1 * 10 + digito2;
}

// Função para verificar se um CPF é válido
int verificaCPF(char *cpf)
{
    // Extrai os dígitos verificadores do CPF recebido
    int digitoVerificador = (cpf[9] - '0') * 10 + (cpf[10] - '0');
    // Cria uma string temporária com os primeiros 9 dígitos do CPF
    char cpfBase[10];
    strncpy(cpfBase, cpf, 9);
    cpfBase[9] = '\0';
    // Calcula o dígito verificador esperado
    int esperado = calculaDigitoVerificador(cpfBase);
    // Compara o dígito verificador calculado com o fornecido no CPF
    return digitoVerificador == esperado;
}

int main()
{
    char nome[100];
    char cpf[12];
    int valido;

    printf("Digite o nome e o CPF da pessoa, ou 'sair' para encerrar:\n");

    while (1)
    {
        scanf("%s", nome);
        if (strcmp(nome, "sair") == 0)
            break;

        scanf("%s", cpf);

        valido = verificaCPF(cpf);

        printf("%s, CPF: %s - %s\n", nome, cpf, valido ? "VÁLIDO" : "INVÁLIDO");
    }

    return 0;
}
