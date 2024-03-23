#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<conio.c>
int main()
{
    setlocale(LC_ALL, "Portuguese");
	// variaveis
	float S;
	int i,j;
	
	//iniciando 
	i = 1;
	j = 50;
	S = 0; 
	//calculo
	while(j > 0)
	{
		S = S +(float)(pow(2,i)/j);
		i++;
		j--;
	}
	printf("%f\n", S);
	
	return 0;
}