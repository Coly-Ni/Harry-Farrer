//0.3.2.3. Escrever um segundo algoritmo que produza os mesmo, valores que o exercício de fixação 0.3.2.2.
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
    for(i = 0; i <= 14; i++){
            if(i % 2 == 0 & i != 0){
            printf("%d\n", i);

            }
    }
}

