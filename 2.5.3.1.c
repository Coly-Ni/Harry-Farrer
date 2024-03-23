#include <stdio.h>
#include <stdbool.h>

// Declaração do registro REG
typedef struct
{
    char nome[50];
    double salario;
    int idade;
    bool sexo; // true para masculino, false para feminino
} REG;

int main()
{
    // Declaração de uma variável do tipo REG
    REG reg;
    return 0;
}
