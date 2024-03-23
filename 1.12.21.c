#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variáveis
    int numOperario = 1;                                                                   // Número do operário
    int pecas;                                                                             // Número de peças fabricadas por mês
    int sexo;                                                                              // Sexo do operário (1 para feminino, 2 para masculino)
    int pecasPorMes = 0;                                                                   // Total de peças fabricadas por mês
    int salarioMinimo;                                                                     // Valor do salário mínimo
    int mulheresA = 0, mulheresB = 0, mulheresC = 0;                                       // Contador de mulheres nas classes A/B/C
    int homensA = 0, homensB = 0, homensC = 0;                                             // Contador de homens nas classes A/B/C
    int numOperarioMaiorSalario = 0;                                                       // Número do operário com maior salário
    float salario;                                                                         // Salário calculado do operário
    float folhaPagamento = 0.0;                                                            // Total da folha mensal de pagamento
    float mediaPecasHomensA = 0.0, mediaPecasHomensB = 0.0, mediaPecasHomensC = 0.0;       // Média de peças fabricadas pelos homens em cada classe
    float mediaPecasMulheresA = 0.0, mediaPecasMulheresB = 0.0, mediaPecasMulheresC = 0.0; // Média de peças fabricadas pelas mulheres em cada classe
    float maiorSalario = 0.0;                                                              // Maior salário entre os operários

    printf("Digite o Salário-mínimo: ");
    scanf("%d", &salarioMinimo);

    // Loop enquanto o numero do operário for diferente de 0
    while (numOperario != 0)
    {
        printf("Número do operário (digite 0 para sair): ");
        scanf("%d", &numOperario);
        if (numOperario == 0)
            break;

        printf("Número de peças fabricadas por mês: ");
        scanf("%d", &pecas);

        printf("Sexo do operário (1 para Feminino, 2 para Masculino): ");
        scanf("%d", &sexo);

        // Calculando a quantidade de peças por mês
        pecasPorMes += pecas;

        // Calculando o salário de acordo com a quantidade de peças
        if (pecas <= 30)
        {
            salario = salarioMinimo;
        }
        else if (pecas <= 35)
        {
            salario = salarioMinimo + (pecas - 30) * (0.03 * salarioMinimo);
        }
        else
        {
            salario = salarioMinimo + (pecas - 30) * (0.05 * salarioMinimo);
        }

        // Contabilizando e somando as peças por sexo e classe
        if (sexo == 1)
        { // Feminino
            if (pecas <= 30)
            {
                mulheresA++;
                mediaPecasMulheresA += pecas;
            }
            else if (pecas <= 35)
            {
                mulheresB++;
                mediaPecasMulheresB += pecas;
            }
            else
            {
                mulheresC++;
                mediaPecasMulheresC += pecas;
            }
        }
        else if (sexo == 2)
        { // Masculino
            if (pecas <= 30)
            {
                homensA++;
                mediaPecasHomensA += pecas;
            }
            else if (pecas <= 35)
            {
                homensB++;
                mediaPecasHomensB += pecas;
            }
            else
            {
                homensC++;
                mediaPecasHomensC += pecas;
            }
        }

        // Escrevendo o salário do operário
        printf("Operário(a) %d: Salário: R$ %.2f\n", numOperario, salario);

        // Verificando e armazenando o maior salário e o número do operário correspondente
        if (salario > maiorSalario)
        {
            maiorSalario = salario;
            numOperarioMaiorSalario = numOperario;
        }

        // Calculando a folha de pagamento
        folhaPagamento += salario;
    }

    // Calculando as médias por classe e sexo
    mediaPecasMulheresA = mulheresA > 0 ? mediaPecasMulheresA / mulheresA : 0;
    mediaPecasMulheresB = mulheresB > 0 ? mediaPecasMulheresB / mulheresB : 0;
    mediaPecasMulheresC = mulheresC > 0 ? mediaPecasMulheresC / mulheresC : 0;
    mediaPecasHomensA = homensA > 0 ? mediaPecasHomensA / homensA : 0;
    mediaPecasHomensB = homensB > 0 ? mediaPecasHomensB / homensB : 0;
    mediaPecasHomensC = homensC > 0 ? mediaPecasHomensC / homensC : 0;

    // Escrevendo o que foi calculado
    printf("Total da folha mensal de pagamento: R$ %.2f\n", folhaPagamento);
    printf("Número total de peças fabricadas no mês: %d\n", pecasPorMes);
    printf("Média de peças fabricadas por mulheres na classe A: %.2f\n", mediaPecasMulheresA);
    printf("Média de peças fabricadas por mulheres na classe B: %.2f\n", mediaPecasMulheresB);
    printf("Média de peças fabricadas por mulheres na classe C: %.2f\n", mediaPecasMulheresC);
    printf("Média de peças fabricadas por homens na classe A: %.2f\n", mediaPecasHomensA);
    printf("Média de peças fabricadas por homens na classe B: %.2f\n", mediaPecasHomensB);
    printf("Média de peças fabricadas por homens na classe C: %.2f\n", mediaPecasHomensC);
    printf("Operário(a) com maior salário: %d, Salário: R$ %.2f\n", numOperarioMaiorSalario, maiorSalario);

    return 0;
}
