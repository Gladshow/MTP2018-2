//Gladson Oliveira Silva
//nº: 11811EEL002
//P3.c

#include <stdio.h>

int main()
{
	int i, num=0;
	char str[256], aux[256];
	printf("Digite a string\n");
	scanf("%s", str);
	aux[0]=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]<='9'&& str[i]>='0')
			num = num*10+(str[i]-'0');
	}
	printf("\nRETORNA: %d", num);
	return 0;
}
