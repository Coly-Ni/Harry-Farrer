#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARACTERES 256 // Número máximo de caracteres ASCII

int main()
{
    char frase[81];                                  // Array para armazenar a frase, considerando o '\0'
    int contagem[MAX_CARACTERES] = {0};              // Array para contagem de cada caractere ASCII
    int pares[MAX_CARACTERES][MAX_CARACTERES] = {0}; // Matriz para contagem de pares de caracteres
    int contagemA = 0;                               // Contador específico para a letra 'A'

    // Leitura da frase
    printf("Digite uma frase de até 80 caracteres: ");
    fgets(frase, 81, stdin);
    frase[strcspn(frase, "\n")] = 0; // Remove a quebra de linha lida pelo fgets

    // Contagem de frequência de cada caractere e da letra 'A'
    for (int i = 0; frase[i] != '\0'; i++)
    {
        contagem[(unsigned char)frase[i]]++;
        if (toupper(frase[i]) == 'A')
        {
            contagemA++;
        }
        // Contagem de pares de letras
        if (frase[i + 1] != '\0')
        { // Verifica se não é o último caractere
            pares[(unsigned char)frase[i]][(unsigned char)frase[i + 1]]++;
        }
    }

    // Impressão da contagem de cada caractere
    printf("Frequência de cada caractere:\n");
    for (int i = 0; i < MAX_CARACTERES; i++)
    {
        if (contagem[i] > 0)
        {
            printf("%c: %d\n", i, contagem[i]);
        }
    }

    // Impressão da contagem da letra 'A'
    printf("Número de vezes que a letra A aparece: %d\n", contagemA);

    // Contagem e impressão de pares de letras
    printf("Pares de letras e suas frequências:\n");
    for (int i = 0; i < MAX_CARACTERES; i++)
    {
        for (int j = 0; j < MAX_CARACTERES; j++)
        {
            if (pares[i][j] > 0)
            {
                printf("%c%c: %d\n", i, j, pares[i][j]);
            }
        }
    }

    return 0;
}
