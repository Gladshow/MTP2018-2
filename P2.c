#include <stdio.h>

int fun1()
{
	char bits[256];
	int i, j, k, flag = 1 , soma = 0, cont;
	printf("\n\nDIgite o numero:\n");
	scanf ("%s", bits);
	for(i=0;i!='\0';i++);
	cont= (i-1);
	for(j=0;j<cont;j++,i--) 
	{
		if (bits [i] == ' 1 ' )
			soma = soma + bits[i]*flag;
		flag = flag*2;
	}
			if (bits [cont] == ' 1 ' )
				soma++;
	printf("Numero convertido eh: %d",soma);
}
int fun2()
{
	char bits[256];
	int i, j, k, flag = 1 , soma = 0, cont;
	printf("\n\nDIgite o numero:\n");
	scanf ("%s", bits);
	for(i=0;i!='\0';i++);
	cont= (i-1);
	for(j=0;j<cont;j++,i--) 
	{
		if (bits [i] == ' 1 ' )
			soma = soma + bits[i]*flag;
		flag = flag*2;
	}
			if (bits [cont] == ' 1 ' )
				soma++;
	printf("Numero convertido eh: %X",soma);
}
int main()
{
	char bits[256];
	int n, hexd, dec;
	printf("Digite:\n1- Binario para Decimal\n2-Binario para hexadecimal\n3- Hexadecimal para Decimal\n4- Hexadecimal para Binario\n5- Decimal para Binario\n6- Decimal para Hexadecimal\n7-Octal para Decimal\n8- Sair do programa\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			
			fun1();
			break;
		case 2:
			fun2();
			break;
		case 3:
			printf("\n\nDIgite o numero:\n");
			scanf("%X", &hexd);
			printf("numero convertido:\n ");
			itoa(hexd,bits,10);
			printf("%s", bits);
			break;
		case 4:
			printf("\n\nDIgite o numero:\n");
			scanf("%d", &hexd);
			printf("numero convertido:\n ");
			itoa(hexd,bits,2);
			printf("%s", bits);
			break;
		case 5:
			printf("\n\nDIgite o numero:\n");
			scanf("%d", &dec);
			printf("numero convertido:\n ");
			itoa(hexd,bits,2);
			printf("%s", bits);
			break;
		case 6:
			printf("\n\nDIgite o numero:\n");
			scanf("%d", &hexd);
			printf("numero convertido:\n ");
			itoa(hexd,bits,2);
			printf("%s", bits);
			break;
		case 7:
			printf("\n\nDIgite o numero:\n");
			scanf("%d", &hexd);
			printf("numero convertido:\n ");
			itoa(hexd,bits,2);
			printf("%s", bits);
			break;
		case 8:
			break;
		default:
			printf("Numero invalido");
	}
	return 0;
}