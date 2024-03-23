#include <stdio.h>

typedef struct
{
    char nome[50];
    int inscricao;
    int horas_extras;
    int horas_normais;
    int classe;
} Cadastro;

int main()
{
    Cadastro funcionario;
    double salario_referencia, salario_bruto, salario_hora_extra, salario_hora_normal;
    double inss, salario_liquido;
    int quantidade_funcionarios, i;

    printf("Digite o salario de referencia: ");
    scanf("%lf", &salario_referencia);

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &quantidade_funcionarios);

    for (i = 0; i < quantidade_funcionarios; i++)
    {
        // Lê os dados do funcionário
        printf("\nDigite o nome do funcionario: ");
        scanf("%s", funcionario.nome);
        printf("Digite o numero de inscricao: ");
        scanf("%d", &funcionario.inscricao);
        printf("Digite as horas normais trabalhadas: ");
        scanf("%d", &funcionario.horas_normais);
        printf("Digite as horas extras trabalhadas: ");
        scanf("%d", &funcionario.horas_extras);
        printf("Digite a classe do funcionario (1 ou 2): ");
        scanf("%d", &funcionario.classe);

        // Calcula salário baseado na classe do funcionário
        if (funcionario.classe == 1)
        {
            salario_hora_normal = 1.3 * salario_referencia;
        }
        else
        {
            salario_hora_normal = 1.9 * salario_referencia;
        }

        // Calcula o salário bruto
        salario_bruto = funcionario.horas_normais * salario_hora_normal;
        salario_hora_extra = 1.3 * salario_hora_normal;
        salario_bruto += funcionario.horas_extras * salario_hora_extra;

        // Calcula o desconto do INSS
        inss = salario_bruto * 0.08;

        // Calcula o salário líquido
        salario_liquido = salario_bruto - inss;

        // Emite o contracheque
        printf("\nContracheque: %s\n", funcionario.nome);
        printf("Salario Horas Normais: %.2f\n", salario_bruto - (funcionario.horas_extras * salario_hora_extra));
        printf("Salario Horas Extras: %.2f\n", funcionario.horas_extras * salario_hora_extra);
        printf("Deducao INSS: %.2f\n", inss);
        printf("Salario Liquido: %.2f\n", salario_liquido);
    }

    return 0;
}
