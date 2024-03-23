#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	float p1, p2, espaco, tempo, velocidade;

	while (1)
	{
		printf("\nEm ordem crescente:");
		printf("\nDigite o Marco quilométrico 1: ");
		scanf("%f", &p1);
		printf("Digite o Marco quilométrico 2: ");
		scanf("%f", &p2);

		// Verificar se os marcos são iguais para encerrar o loop
		if (p1 == p2)
		{
			break;
		}

		// Garantir que p2 seja maior que p1
		while (p2 < p1)
		{
			printf("!!!!!DIGITE EM ORDEM CRESCENTE!!!!\n");
			printf("Digite o Marco quilométrico 1: ");
			scanf("%f", &p1);
			printf("Digite o Marco quilométrico 2: ");
			scanf("%f", &p2);
		}

		// Calculando o espaço
		espaco = p2 - p1;

		// Calculando o tempo para cada velocidade
		for (velocidade = 20; velocidade <= 80; velocidade += 10)
		{
			tempo = espaco / velocidade;
			if (tempo > 2.00)
			{
				printf("Entre os marcos %f e %f, a %f km/h, o tempo é de %f horas\n", p1, p2, velocidade, tempo);
			}
		}
	}

	return 0;
}
