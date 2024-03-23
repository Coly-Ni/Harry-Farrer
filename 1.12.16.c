#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");

	// Variáveis
	int idade;							 // Armazena a idade do candidato
	int numMasculino = 0;				 // Conta o número de candidatos do sexo masculino
	int numFeminino = 0;				 // Conta o número de candidatas do sexo feminino
	int F35anos = 0;					 // Conta o número de mulheres com menos de 35 anos e experiência
	int menorIdadeF = 100;				 // Armazena a menor idade entre as mulheres com experiência
	int totalHomensExperiencia = 0;		 // Conta o número de homens com experiência
	int totalHomensMais45 = 0;			 // Conta o número de homens com mais de 45 anos
	int idadeTotalHomensExperiencia = 0; // Soma das idades dos homens com experiência
	int inscri;							 // Número de inscrição do candidato
	float idadeMediaM = 0;				 // Idade média dos homens com experiência
	float porcentagemM = 0;				 // Porcentagem de homens com mais de 45 anos entre todos os homens
	char sexo[12], experi[4];			 // Armazenam o sexo e a experiência (sim/não), respectivamente

	while (1)
	{
		printf("Digite o número da inscrição (0 para sair): ");
		scanf("%d", &inscri);
		if (inscri == 0)
			break;

		printf("Digite sua idade: ");
		scanf("%d", &idade);

		printf("Digite seu sexo (masculino/feminino): ");
		scanf("%s", sexo);

		printf("Possui experiência? (sim/nao): ");
		scanf("%s", experi);

		// Processamento para candidatos do sexo feminino
		if (strcmp(sexo, "feminino") == 0)
		{
			numFeminino++;
			if (idade < 35 && strcmp(experi, "sim") == 0)
			{
				F35anos++;
				printf("Número da inscrição da mulher com idade inferior a 35 e experiência: %d\n", inscri);
				if (menorIdadeF > idade)
				{
					menorIdadeF = idade;
				}
			}
		}

		// Processamento para candidatos do sexo masculino
		if (strcmp(sexo, "masculino") == 0)
		{
			numMasculino++;
			if (strcmp(experi, "sim") == 0)
			{
				idadeTotalHomensExperiencia += idade;
				totalHomensExperiencia++;
			}
			if (idade > 45)
			{
				totalHomensMais45++;
			}
		}
	}

	// Cálculos finais
	if (totalHomensExperiencia > 0)
	{
		idadeMediaM = (float)idadeTotalHomensExperiencia / totalHomensExperiencia;
	}
	if (numMasculino > 0)
	{
		porcentagemM = (float)totalHomensMais45 / numMasculino * 100;
	}

	// Resultados
	printf("Número de mulheres com idade inferior a 35 e experiência: %d\n", F35anos);
	printf("A menor idade entre as mulheres com experiência: %d\n", menorIdadeF);
	printf("Número de candidatos do sexo feminino: %d\n", numFeminino);
	printf("Número de candidatos do sexo masculino: %d\n", numMasculino);
	printf("Idade média dos homens com experiência: %.2f\n", idadeMediaM);
	printf("Porcentagem de homens com mais de 45 anos: %.2f%%\n", porcentagemM);

	return 0;
}
