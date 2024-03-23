#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");

	// Declaração de variáveis
	int vendidos, vendidosMaiorLucro;						// vendidos: ingressos vendidos; vendidosMaiorLucro: maior número de ingressos vendidos no lucro máximo
	float ingresso, lucro, lucroMaximo, ingressoMaiorLucro; // ingresso: preço do ingresso; lucro: lucro calculado; lucroMaximo: maior lucro obtido; ingressoMaiorLucro: preço do ingresso no lucro máximo

	// Inicialização de variáveis
	vendidos = 120;	   // Número inicial de ingressos vendidos
	lucroMaximo = 0.0; // Inicialização do lucro máximo
	ingresso = 5.00;   // Preço inicial do ingresso

	printf("____________TABELA DE PREÇOS___________________\n");

	// Laço para calcular os lucros com os diferentes preços de ingressos
	for (int i = 0; i < 9; i++)
	{
		lucro = (ingresso * vendidos) - 200; // Cálculo do lucro

		if (lucro > lucroMaximo)
		{
			lucroMaximo = lucro;
			vendidosMaiorLucro = vendidos;
			ingressoMaiorLucro = ingresso;
		}

		printf("| PREÇO DO INGRESSO: R$ %.2f | LUCRO: R$ %.2f |\n", ingresso, lucro);

		ingresso -= 0.50; // Decremento do preço do ingresso
		vendidos += 26;	  // Aumento no número de ingressos vendidos
	}

	// Exibindo o maior lucro esperado, o preço do ingresso e o número de ingressos vendidos correspondentes
	printf("\nMaior lucro esperado: R$ %.2f", lucroMaximo);
	printf("\nValor do ingresso para maior lucro: R$ %.2f", ingressoMaiorLucro);
	printf("\nQuantidade de ingressos vendidos para maior lucro: %d\n", vendidosMaiorLucro);

	return 0;
}
