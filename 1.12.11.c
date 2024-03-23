#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	int codigoCurso, vagasCurso, numMascCurso, numFemiCurso;
	int totalCandidatosCurso, totalCandidatos = 0, codigoMaiorConc = 0;
	float candidatosPorVaga, porcFemiCurso, maiorConc = 0.0;

	while (1)
	{
		printf("\nDigite o código do curso (ou 0 para encerrar): ");
		scanf("%d", &codigoCurso);

		if (codigoCurso == 0)
		{
			break;
		}

		printf("\nDigite o número de vagas do curso: ");
		scanf("%d", &vagasCurso);
		printf("\nDigite o número de alunos do sexo masculino no curso: ");
		scanf("%d", &numMascCurso);
		printf("\nDigite o número de alunas do sexo feminino no curso: ");
		scanf("%d", &numFemiCurso);

		totalCandidatosCurso = numMascCurso + numFemiCurso;
		totalCandidatos += totalCandidatosCurso;
		candidatosPorVaga = (float)totalCandidatosCurso / vagasCurso;
		porcFemiCurso = (float)numFemiCurso / totalCandidatosCurso * 100;

		if (candidatosPorVaga > maiorConc)
		{
			maiorConc = candidatosPorVaga;
			codigoMaiorConc = codigoCurso;
		}

		printf("\n------------------------------------------");
		printf("\nCódigo do curso: %d", codigoCurso);
		printf("\nTotal de candidatos: %d", totalCandidatosCurso);
		printf("\nCandidatos por vaga: %.2f", candidatosPorVaga);
		printf("\nPorcentagem de mulheres no curso: %.2f%%", porcFemiCurso);
		printf("\n------------------------------------------");
	}

	printf("\n\nCurso com maior número de candidatos por vaga: Código %d com %.2f candidatos por vaga.", codigoMaiorConc, maiorConc);
	printf("\n------------------------------------------\n");

	return 0;
}
