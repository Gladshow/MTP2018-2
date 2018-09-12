
//Gladson Oliveira Silva   nº 11811EEL002//
//Trabalho: P1//

#include <stdio.h>

int main()
{
	int estado = 0, i;
	char bits[256];
	printf("Digite a seguência de caracteres \n");
	scanf("%s", bits);
	for(i=0;bits[i] != '\0';i++)
	{
		if(estado == 0 && bits[i] == '1')
			estado = 1;
		else if(estado == 1)
		{
			if(bits[i]== '1')
				estado = 0;
			else if (bits[i]=='0')
				estado = 2;
		}
		else if(estado == 2 && bits[i] == '0')
			estado = 1;
	}
		printf("Sequencia original:\n%s", bits);
		if(estado == 0)
			printf("\n\nCaracter digitado e multiplo de 3");
		else
			printf("\n\nCaracter digitado nao e multiplo de 3");
	getch();
	return 0;
}