#include <stdio.h>
#include <math.h>

// Estrutura para representar um ponto no espaço tridimensional
typedef struct
{
    double x, y, z;
} Ponto3D;

// Sub-rotina que calcula a distância entre dois pontos no espaço
double distanciaEntrePontos(Ponto3D a, Ponto3D b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

// Sub-rotina que calcula a área de um triângulo usando a fórmula de Heron
double areaTriangulo(double a, double b, double c)
{
    double p = (a + b + c) / 2; // Semi-perímetro
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Sub-rotina que calcula a área total do tetraedro
double areaTetraedro(Ponto3D vertices[4])
{
    double lados[6];
    lados[0] = distanciaEntrePontos(vertices[0], vertices[1]);
    lados[1] = distanciaEntrePontos(vertices[0], vertices[2]);
    lados[2] = distanciaEntrePontos(vertices[0], vertices[3]);
    lados[3] = distanciaEntrePontos(vertices[1], vertices[2]);
    lados[4] = distanciaEntrePontos(vertices[1], vertices[3]);
    lados[5] = distanciaEntrePontos(vertices[2], vertices[3]);

    // Área dos quatro triângulos que compõem as faces do tetraedro
    double areaTotal = areaTriangulo(lados[0], lados[1], lados[3]) +
                       areaTriangulo(lados[0], lados[2], lados[4]) +
                       areaTriangulo(lados[1], lados[2], lados[5]) +
                       areaTriangulo(lados[3], lados[4], lados[5]);
    return areaTotal;
}

int main()
{
    Ponto3D tetraedros[10][4]; // Supondo que temos 10 tetraedros
    double areas[10];

    for (int i = 0; i < 10; ++i)
    {
        areas[i] = areaTetraedro(tetraedros[i]);
        printf("Área do tetraedro %d: %.2f\n", i + 1, areas[i]);
    }

    return 0;
}
