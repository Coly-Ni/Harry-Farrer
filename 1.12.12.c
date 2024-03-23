#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100 // Número máximo de alunos

int main()
{
	setlocale(LC_ALL, "");

	// Arrays para armazenar as informações de cada aluno
	int matricula[MAX];				 // Armazena as matrículas dos alunos
	int frequencia[MAX];			 // Armazena a frequência (número de aulas assistidas) dos alunos
	float n1[MAX], n2[MAX], n3[MAX]; // Armazenam as três notas dos alunos
	float notaFinal[MAX];			 // Armazena a nota final (média das notas) de cada aluno
	char aprovacao[MAX][11];		 // Array de strings para armazenar o status de aprovação ("APROVADO" ou "REPROVADO") de cada aluno

	// Variáveis para cálculos gerais sobre a turma
	float maiornot = 0.0;	// Maior nota encontrada na turma
	float menornot = 110.0; // Menor nota encontrada na turma (inicializada com um valor alto para garantir correta atribuição)
	float mediaturma = 0.0; // Média das notas de toda a turma
	int reprovados = 0;		// Contador total de alunos reprovados
	int freqrepro = 0;		// Contador de alunos reprovados por infrequência
							// Leitura dos dados dos alunos
	for (i = 0; i < MAX; i++)
	{
		printf("\nDigite a matricula do aluno: ");
		scanf("%d", &matricula[i]);
		printf("\nDigite a primeira nota do aluno: ");
		scanf("%f", &n1[i]);
		printf("\nDigite a segunda nota do aluno: ");
		scanf("%f", &n2[i]);
		printf("\nDigite a terceira nota do aluno: ");
		scanf("%f", &n3[i]);
		printf("\nDigite a frequencia do aluno: ");
		scanf("%d", &frequencia[i]);
	}

	// Cálculo da nota final e status de aprovação
	for (i = 0; i < MAX; i++)
	{
		notaFinal[i] = (n1[i] + n2[i] + n3[i]) / 3; // Calculando a média

		// Atualizando a maior e menor nota
		if (notaFinal[i] > maiornot)
		{
			maiornot = notaFinal[i];
		}
		if (notaFinal[i] < menornot)
		{
			menornot = notaFinal[i];
		}

		// Verificando condição de aprovação
		if (notaFinal[i] >= 60.0 && frequencia[i] >= 40)
		{
			strcpy(aprovacao[i], "APROVADO");
		}
		else
		{
			strcpy(aprovacao[i], "REPROVADO");
			reprovados++;
			if (frequencia[i] < 40)
			{
				freqrepro++;
			}
		}

		mediaturma += notaFinal[i];
	}

	mediaturma /= MAX; // Calculando a média da turma

	// Exibindo informações dos alunos
	for (i = 0; i < MAX; i++)
	{
		printf("\n-------------------------------------");
		printf("\nMatricula: %d", matricula[i]);
		printf("\nFrequencia: %d", frequencia[i]);
		printf("\nMedia: %.2f", notaFinal[i]);
		printf("\n%s", aprovacao[i]);
		printf("\n-------------------------------------");
	}

	// Exibindo informações gerais da turma
	printf("\nA menor nota da turma: %.2f", menornot);
	printf("\nA maior nota da turma: %.2f", maiornot);
	printf("\nA nota media da turma: %.2f", mediaturma);
	printf("\nO total de alunos reprovados: %d", reprovados);
	printf("\nO total de alunos reprovados por infrequencia: %d", freqrepro);

	return 0;
}