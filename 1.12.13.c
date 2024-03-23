#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setl333Aocale(LC_ALL, "");
	//variaveis
	float KWh, aux, preco, consu, numeroconsumidor, total, maiorconsumo, menorconsumo, totalre, totalco, totalind, mediageral;
	char tipo[12];
	
	//inicia
	totalre = 0.0;
	totalco = 0.0;
	totalind = 0.0;
	consu = 0;
	menorconsumo = 1000.000;
	maiorconsumo = 0.0;v
	total = 0.0;
	
	printf("digite o preço do KWh:");
	scanf("%f", &preco);
	
	do
	{
		printf("digite o número do consumidor:");
		scanf("%f", &numeroconsumidor);
		
		if(numeroconsumidor != 0 )
		{
			printf("Diite a quantidade de KWh consumida durante o mês:");
			scanf("%f", &KWh);
			media = media + KWh; 											//utilizado para média
			consu++; 														//ultilizado para média
			
			//total a pagar
			total = total * KWh;
			
			//escrever total e numero
			printf("\nO consumidor %f deve pagar %f:",numeroconsumidor, total );
			
			if(KWh > maiorconsumo)
			{
				maiorconsumo = KWh;
			}
			if(KWh < menorconsumo)
			{
				menorconsumo = KWh;
			}
			
			printf("digite o tipo de consumidor:");
			scanf("%s", tipo);
		
			if (strcmp(tipo,"residencial") ==0)
			{
				totalre = totalre + KWh;
				
				
			}
			
			if (strcmp(tipo,"comercial") ==0)
			{
				totalco = totalco + KWh;
				
				
			}
			
			if (strcmp(tipo,"industrial") ==0)
			{
				totalind = totalind + KWh;
				
				
			}			
			
			totAL = 0.0;
		
		
		}
		
	}while(numeroconsumidor != 0);

		//calculo
		media = media / (float) consu;
		
		//escreva
		printf("\n-------DADOS GERAIS----------");
		printf("\nMédia de consumo: %f", media);
		printf("\nTotal residencial: %f", totalre);
		printf("\nTotal comercial: %f", totalco);
		printf("\nTotal industrial: %f", totalind);
		printf("\nMaior consumo: %f", maiorconsumo);
		printf("\n Menor consumo: %f", menorconsumo );
		printf("\n-----------------------------");
