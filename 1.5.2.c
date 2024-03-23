#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    char nome[6],profissao[9];
    int b,i, logico;
    float a;

    a = 3;
    b = 16;
    nome[6] = "MIRIAM";
    profissao[9] = "ADVOGADO";
    if ( a + 1 >= sqrt(b)){
        logico = 1;
    }else{
        logico = 0;
    }
   printf("%d\n", logico);


    if(nome[6] =! "ANA"){
            logico = 0;

    }else  {
        logico = 1;
    }
    printf("%d\n", logico);

      if(profissao[9] == "MÉDICO"){
        logico = 1;
    }else {
        logico = 0;
    }
        printf("%d\n", logico);

    a = 5;
    b = 64;
    nome[6] = "PEDRO";
    profissao[9] = "MÉDICO";

       if ( a + 1 >= sqrt(b)){
        logico = 1;
    }else{
        logico = 0;
    }
   printf("%d\n", logico);


    if(nome[6] =! "ANA"){
            logico = 0;

    }else  {
        logico = 1;
    }
    printf("%d\n", logico);

      if(profissao[9] == "MÉDICO"){
        logico = 1;
    }else {
        logico = 0;
    }
        printf("%d\n", logico);

    a = 2.5;
    b = 9;
    nome[6] = "ANA";
    profissao[9] = "PROFESSOR";
    }


