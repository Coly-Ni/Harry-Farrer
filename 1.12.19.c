#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "");

    // Variáveis
    int acor, pretoebranco, id = 1;                                                               // acor: TVs a cores vendidas; pretoebranco: TVs P&B vendidas; id: identificador do empregado
    float INSS, ir, salarioLiquido, comissaoAcor, comissaoPretoBranco, salarioBruto, salarioBase; // INSS: desconto do INSS; ir: imposto de renda; salarioLiquido: salário após descontos; comissaoAcor/PretoBranco: comissão por TVs vendidas; salarioBruto: salário antes dos descontos; salarioBase: salário fixo

    while (id != 0)
    {
        printf("Digite seu ID ou (0) para sair: ");
        scanf("%d", &id);

        if (id == 0)
        {
            break;
        }

        printf("Digite o seu salário fixo: ");
        scanf("%f", &salarioBase);

        printf("Digite quantos televisores a cores foram vendidos: ");
        scanf("%d", &acor);

        printf("Digite quantos televisores preto e branco foram vendidos: ");
        scanf("%d", &pretoebranco);

        // Cálculo das comissões
        comissaoAcor = acor >= 10 ? acor * 50 : acor * 5;
        comissaoPretoBranco = pretoebranco >= 20 ? pretoebranco * 20 : pretoebranco * 2;

        // Cálculo do salário bruto
        salarioBruto = salarioBase + comissaoAcor + comissaoPretoBranco;

        // Cálculo do desconto do INSS
        INSS = salarioBruto * 0.08; // Desconto de 8% para o INSS

        // Cálculo do salário líquido e do imposto de renda
        if (salarioBruto >= 500)
        {
            ir = salarioBruto * 0.15; // Desconto de 15% para o imposto de renda
        }
        else
        {
            ir = 0;
        }
        salarioLiquido = salarioBruto - INSS - ir;

        // Escrevendo o salário líquido
        printf("Salário líquido: R$ %.2f\n", salarioLiquido);
    }

    return 0;
}
