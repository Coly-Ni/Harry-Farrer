#include <stdio.h>
#include <math.h>

// Função para calcular a quantidade de dígitos de um número
int contaDigitos(int numero)
{
    int digitos = 0;
    while (numero)
    {
        digitos++;
        numero /= 10;
    }
    return digitos;
}

// Sub-rotina para inverter um número
int inverteNumero(int numero, int digitos)
{
    int invertido = 0;
    while (digitos--)
    {
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }
    return invertido;
}

// Função para verificar se um número é capicua
int ehCapicua(int numero)
{
    int digitos = contaDigitos(numero);
    return numero == inverteNumero(numero, digitos);
}

int main()
{
    for (int i = 1; i < sqrt(5000); ++i)
    {
        int quadrado = i * i;
        if (ehCapicua(quadrado))
        {
            printf("%d\n", quadrado);
        }
    }
    return 0;
}
