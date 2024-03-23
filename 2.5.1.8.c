#include <stdio.h>

#define MAX_EMPREGADOS 3

typedef struct
{
    int numeroEmpregado;
    int mesesTrabalhados;
} Empregado;

int main()
{
    Empregado empregados[MAX_EMPREGADOS];
    int numero, meses, i;

    // Inicializar os três empregados com valores máximos de meses
    for (i = 0; i < MAX_EMPREGADOS; i++)
    {
        empregados[i].mesesTrabalhados = 301; // Nenhum empregado pode ter mais de 300 meses de trabalho
    }

    while (1)
    {
        printf("Digite o número do empregado e o número de meses de trabalho (ou '0 0' para encerrar): ");
        scanf("%d %d", &numero, &meses);

        if (numero == 0 && meses == 0)
        {
            break; // Encerra a leitura quando lê '0 0'
        }

        // Verificar se o empregado é um dos três mais recentes
        for (i = 0; i < MAX_EMPREGADOS; i++)
        {
            if (meses < empregados[i].mesesTrabalhados)
            {
                // Desloca os empregados mais antigos para baixo no array
                for (int j = MAX_EMPREGADOS - 1; j > i; j--)
                {
                    empregados[j] = empregados[j - 1];
                }
                // Inserir o novo empregado mais recente na posição correta
                empregados[i].numeroEmpregado = numero;
                empregados[i].mesesTrabalhados = meses;
                break;
            }
        }
    }

    // Impressão dos três empregados mais recentes
    printf("Os três empregados mais recentes são:\n");
    for (i = 0; i < MAX_EMPREGADOS; i++)
    {
        if (empregados[i].mesesTrabalhados < 301)
        { // Checa se a posição foi preenchida
            printf("Empregado: %d, Meses de trabalho: %d\n", empregados[i].numeroEmpregado, empregados[i].mesesTrabalhados);
        }
    }

    return 0;
}
