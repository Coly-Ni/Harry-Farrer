#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char nome[50];
    double salario;
    int idade;
    bool sexo; // Assumir que 'true' representa um sexo e 'false' o outro.
} REG;

int main()
{
    REG reg;

    // Atribuir o valor ao salário.
    reg.salario = 7840212.00;

    return 0;
}
