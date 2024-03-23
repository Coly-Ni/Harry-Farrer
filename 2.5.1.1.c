#include <stdio.h>

int main()
{
    float temperaturas[121]; // Supondo que este array já contém as temperaturas dos 121 dias
    float minTemp = 41.0, maxTemp = 14.0, somaTemp = 0.0, mediaTemp;
    int diasInferioresMedia = 0;

    // Passo 2: Encontrar minTemp, maxTemp e calcular somaTemp
    for (int i = 0; i < 121; i++)
    {
        if (temperaturas[i] < minTemp)
        {
            minTemp = temperaturas[i];
        }
        if (temperaturas[i] > maxTemp)
        {
            maxTemp = temperaturas[i];
        }
        somaTemp += temperaturas[i];
    }

    // Calcular a média das temperaturas
    mediaTemp = somaTemp / 121;

    // Passo 4: Contar dias com temperatura inferior à média
    for (int i = 0; i < 121; i++)
    {
        if (temperaturas[i] < mediaTemp)
        {
            diasInferioresMedia++;
        }
    }

    // Passo 5: Imprimir resultados
    printf("Menor temperatura ocorrida: %.2f°C\n", minTemp);
    printf("Maior temperatura ocorrida: %.2f°C\n", maxTemp);
    printf("Temperatura média: %.2f°C\n", mediaTemp);
    printf("Número de dias com temperatura inferior à média: %d\n", diasInferioresMedia);

    return 0;
}
