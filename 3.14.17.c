#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int numero)
{
    if (numero <= 1)
        return false;
    if (numero <= 3)
        return true;

    if (numero % 2 == 0 || numero % 3 == 0)
        return false;

    for (int i = 5; i * i <= numero; i += 6)
    {
        if (numero % i == 0 || numero % (i + 2) == 0)
            return false;
    }

    return true;
}

// Função principal para encontrar e imprimir pares de números primos
void encontrarParesGoldbach(int numero)
{
    if (numero % 2 != 0)
    {
        printf("O número %d não é par e, portanto, não se aplica à conjectura de Goldbach.\n", numero);
        return;
    }

    for (int i = 2; i <= numero / 2; ++i)
    {
        if (ehPrimo(i) && ehPrimo(numero - i))
        {
            printf("%d = %d + %d\n", numero, i, numero - i);
            return; // Retorna após encontrar o primeiro par válido
        }
    }
}

int main()
{
    // Substitua o array abaixo pelos números desejados
    int numeros[] = {8, 16, 68}; // Exemplo
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < tamanho; ++i)
    {
        encontrarParesGoldbach(numeros[i]);
    }

    return 0;
}
