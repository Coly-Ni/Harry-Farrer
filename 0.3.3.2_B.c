//0.3.2.2. Escrever um algoritmo que. partindo de diferentes estados iniciais. produza os valores:
//b) 1 – 3 – 5 – 7 – 9 – 11 – 13

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main()
{
    //variaveis
    int i;
    setlocale(LC_ALL, "Portuguese");
    for(i = 1; i <= 13; i+=2){
            printf("%d\n", i);

    }
}
