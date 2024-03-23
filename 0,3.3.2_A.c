//0.3.2.2. Escrever um algoritmo que. partindo de diferentes estados iniciais. produza os valores:
//a) 2 – 4 – 6 – 8 – 10 – 12 – 14

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main()
{
    //variaveis
    int i;
    setlocale(LC_ALL, "Portuguese");
    for(i = 2; i <= 14; i+=2){
            printf("%d\n", i);

    }
}
