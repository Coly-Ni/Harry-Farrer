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
	int i,j,k;
	
	//iniciando 
	i = 37;
	j = 38; 
	k = 1;
	S = 0;
	//calculo
	while(i > 0)
	{
		S = S + (float)(i*j)/k;
		i--;
		j--;
		k++;
	}
	printf("%f\n", S);
	
	return 0;
}