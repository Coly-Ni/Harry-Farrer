// invente um problema e resolva 0.3.4.1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int main()
{
    int n,i;
    setlocale(LC_ALL, "Portuguese");
    for(i = 0; i <= 10; i++){
        printf("digite um número:");
        scanf("%d", &n);
        if(n == 5){
            i = 10;
        }
    }

}
