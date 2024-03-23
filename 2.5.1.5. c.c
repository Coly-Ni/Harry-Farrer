#include <stdio.h>

int main()
{
    int notas[80];                    // Array para armazenar as 80 notas dos alunos
    int frequenciaAbsoluta[11] = {0}; // Array para a frequência absoluta (de 0 a 10)
    float frequenciaRelativa[11];     // Array para a frequência relativa
    int i, nota;

    // Leitura das 80 notas
    printf("Digite as 80 notas dos alunos (entre 0 e 10):\n");
    for (i = 0; i < 80; i++)
    {
        scanf("%d", &nota);
        if (nota < 0 || nota > 10)
        {
            printf("Nota inválida! Notas devem estar entre 0 e 10.\n");
            i--; // Pedir novamente a nota
        }
        else
        {
            frequenciaAbsoluta[nota]++; // Incrementa a frequência da nota lida
        }
    }

    // Cálculo da frequência relativa
    for (i = 0; i <= 10; i++)
    {
        frequenciaRelativa[i] = (float)frequenciaAbsoluta[i] / 80;
    }

    // Impressão da tabela com frequências absoluta e relativa
    printf("\nNota | Frequência Absoluta | Frequência Relativa\n");
    for (i = 0; i <= 10; i++)
    {
        printf("%4d | %18d | %17.2f%%\n", i, frequenciaAbsoluta[i], frequenciaRelativa[i] * 100);
    }

    return 0;
}
