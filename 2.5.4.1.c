#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
    char informacao[100];
    int data;
} Registro;

int main()
{
    FILE *fonte, *fontenova;
    Registro reg;

    fonte = fopen("FONTE.txt", "r");
    if (fonte == NULL)
    {
        perror("Erro ao abrir o arquivo FONTE.txt");
        return EXIT_FAILURE;
    }

    fontenova = fopen("FONTENOVA.txt", "w");
    if (fontenova == NULL)
    {
        perror("Erro ao criar o arquivo FONTENOVA.txt");
        fclose(fonte);
        return EXIT_FAILURE;
    }

    // Lendo e escrevendo registros.
    while (fscanf(fonte, "%d %s %d", &reg.chave, reg.informacao, &reg.data) == 3)
    {
        fprintf(fontenova, "%d %s %d\n", reg.chave, reg.informacao, reg.data);
    }

    fclose(fonte);
    fclose(fontenova);

    printf("Arquivo copiado com sucesso!\n");

    return EXIT_SUCCESS;
}
