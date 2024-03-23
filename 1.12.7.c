#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 14

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char presenca[2];
    char turma[10];
    int i, matriculas, m, ausent, turmasComAltaAusencia = 0;
    float porcefaltas;

    for (i = 0; i < MAX; i++)
    {
        ausent = 0;
        printf("Digite o nome da turma: ");
        scanf("%s", turma);
        printf("Digite a quantidade de alunos matriculados: ");
        scanf("%d", &matriculas);

        for (m = 0; m < matriculas; m++)
        {
            printf("Digite o número da matrícula e a presença (A para ausente, P para presente):\n");
            scanf("%s", presenca);
            if (strcmp(presenca, "A") == 0)
            {
                ausent++;
            }
        }

        porcefaltas = (float)ausent / matriculas * 100;
        printf("A porcentagem de faltas na turma %s é: %.2f%%\n", turma, porcefaltas);

        if (porcefaltas > 5)
        {
            turmasComAltaAusencia++;
        }
    }

    printf("Quantidade de turmas com mais de 5%% de faltas: %d\n", turmasComAltaAusencia);

    return 0;
}
