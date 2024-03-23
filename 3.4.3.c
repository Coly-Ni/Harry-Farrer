#include <stdio.h>

// Função para calcular a soma das três maiores notas de quatro notas dadas
int somaTresMaiores(int n1, int n2, int n3, int n4)
{
    int min = n1;
    if (n2 < min)
        min = n2;
    if (n3 < min)
        min = n3;
    if (n4 < min)
        min = n4;
    return n1 + n2 + n3 + n4 - min; // Soma todas e subtrai a menor
}

// Função para determinar o conceito baseado na nota final
char determinaConceito(int notaFinal)
{
    if (notaFinal >= 90)
        return 'A';
    if (notaFinal >= 80)
        return 'B';
    if (notaFinal >= 70)
        return 'C';
    if (notaFinal >= 60)
        return 'D';
    if (notaFinal >= 40)
        return 'E';
    return 'F';
}

int main()
{
    int numAluno, n1, n2, n3, n4, notaFinal;
    char conceito;

    for (int i = 0; i < 80; i++)
    { // Supondo que serão lidos dados de 80 alunos
        printf("Digite o número do aluno e as quatro notas mensais e a nota final: ");
        scanf("%d %d %d %d %d %d", &numAluno, &n1, &n2, &n3, &n4, &notaFinal);
        notaFinal += somaTresMaiores(n1, n2, n3, n4);
        conceito = determinaConceito(notaFinal);
        printf("Aluno %d - Nota final: %d - Conceito: %c\n", numAluno, notaFinal, conceito);
    }

    return 0;
}
