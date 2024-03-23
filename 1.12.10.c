#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	// Variáveis
	int canal, c4 = 0, c5 = 0, c7 = 0, c12 = 0, total = 0;
	float pc4, pc5, pc7, pc12;

	do
	{
		printf("\nDigite o número do canal que a família está assistindo (ou 0 para encerrar): ");
		scanf("%d", &canal);

		switch (canal)
		{
		case 4:
			c4++;
			total++;
			break;
		case 5:
			c5++;
			total++;
			break;
		case 7:
			c7++;
			total++;
			break;
		case 12:
			c12++;
			total++;
			break;
		}
	} while (canal != 0);

	// Cálculos
	if (total > 0)
	{
		pc4 = (float)c4 / total * 100.0;
		pc5 = (float)c5 / total * 100.0;
		pc7 = (float)c7 / total * 100.0;
		pc12 = (float)c12 / total * 100.0;
	}
	else
	{
		pc4 = pc5 = pc7 = pc12 = 0;
	}

	// Exibindo resultados
	printf("\nA porcentagem de pessoas assistindo o canal 4: %.2f%%\n", pc4);
	printf("A porcentagem de pessoas assistindo o canal 5: %.2f%%\n", pc5);
	printf("A porcentagem de pessoas assistindo o canal 7: %.2f%%\n", pc7);
	printf("A porcentagem de pessoas assistindo o canal 12: %.2f%%\n", pc12);

	return 0;
}
