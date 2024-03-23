#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	// Declaração de variáveis
	float saldo, saldomin, valor, taxa;
	int nconta, quanttransacao, transacao;

	while (1)
	{
		// Leitura dos dados da conta
		printf("\nDigite o número da conta (ou 0 para encerrar), saldo atual, saldo mínimo diário, quantidade de transações e taxa de serviço: ");
		scanf("%d%f%f%d%f", &nconta, &saldo, &saldomin, &quanttransacao, &taxa);

		// Verifica se o número da conta é zero para encerrar o programa
		if (nconta == 0)
			break;

		// Processamento das transações
		for (int i = 0; i < quanttransacao; i++)
		{
			printf("\nDigite o valor e o código da transação ([1] para depósito [2] para retirada): ");
			scanf("%d%f", &transacao, &valor);

			if (transacao == 1)
			{
				// Processamento de depósito
				saldo += valor;
			}
			else if (transacao == 2)
			{
				// Processamento de retirada
				if (valor <= saldo)
				{
					saldo -= valor;
				}
				else
				{
					printf("\nNão possui fundos suficientes para a retirada\n");
				}
			}
		}

		// Aplicação da taxa de serviço
		if (saldo < saldomin)
		{
			saldo -= taxa;
		}

		// Exibição do saldo final
		if (saldo >= 0)
		{
			printf("\nNúmero da conta: %d\nSaldo: %.2f\n", nconta, saldo);
		}
		else
		{
			printf("\nNúmero da conta: %d\nNÃO HÁ FUNDOS\n", nconta);
		}
	}

	return 0;
}
