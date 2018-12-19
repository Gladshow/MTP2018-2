//Gladson Oliveira Silva   nº11811EEL002

#include <stdio.h>

void fun1();
void fun2();
void fun4();
void fun5();
void fun6();
void fun7();
void fun8();

int main()
{
	char bits[256];
	char he[20];
	int n, hexd, dec;
	printf("Digite:\n1- Binario para Decimal\n2-Binario para hexadecimal\n3- Hexadecimal para Decimal\n4- Hexadecimal para Binario\n5- Decimal para Binario\n6- Decimal para Hexadecimal\n7-Octal para Decimal\n8- Decimal para Octal\n9-Sair do programa\n\n\nOpacao Escolhida:   ");
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
			fun4();
			break;
		case 5:
			fun5();
			break;
		case 6:
			fun6();
			break;
		case 7:
			fun7();
			break;
		case 8:
			fun8();
			break;
		case 9:
			break;
		default:
			printf("Numero invalido");	
	}
	return 0;
}

void fun1()
{
	char bit[256], aux[256];
	int i=0, j, cont=0, flag=1, dec=0;
	printf("\nDigite o numero em binario: ");
	scanf("%s", bit);
	getchar(); 
	while(bit[i] != '\0')
	{
		i++;
		cont++;
	}
	j=cont-1;
	for(i=0; i<cont; i++, j--)
	{ 
		aux[j] = bit[i];
	}
	for(j=1; j<cont;j++)
	{  
		flag=flag*2;
		if(aux[j] == '1')
		dec = dec + flag;
	}
	if(aux[0] == '1')
	{
		dec = dec +1;
	}
	printf("\nO numero convertido eh: %d ", dec);
}

void fun2()
{
 
 char  num[256];
 int cont = 0, k, cont2, x=1,hex=0;
 int flag[100]; 
 printf("\nDigite o numero em binario: ");
	   scanf("%s", num);
	   getchar();
	   for(cont=0;num[cont]!='\0';cont++);
	   cont--;		   
	   for( k = cont; k >= 0 ; k--)
	   {
	  		if(num[k]=='0')
			{
				flag[k] = 0;
			}
			else if(num[k]=='1')
				flag[k] = 1; 
		}
		cont2 = cont;
		while(cont2>= 0)
		{
			while(x<=cont-cont2)
			{
				flag[cont2] *=2;
				x++;
			}
		
		hex = hex + flag[cont2];
		x = 1;
		cont2--;
        }
	    printf("\nNumero convertido eh = %x", hex);
}

void fun4()
{
   int flag, convert[100], i;
   printf("\nDigite o numero em hexadecimal: ");
   scanf("%x", &flag);
   getchar();
   for(i = 0; flag >= 1; i++)
   {
   convert[i] = flag % 2;
    flag /= 2;
   }
   printf("\nNumero convertido eh: ");
   for(i = i-1; i >= 0; i--)
   {
    printf("%i", convert[i]);
   }
}

void fun5()
{
	int cont, flag, i, j;
	j=9;
    printf("Digite o numero em decimal: ");
    scanf("%d", &cont);
    for(i=j; i >= 0; i--) 
 	{
       flag = cont >> i;
        if(flag & 1) 
           {
		   printf("1");
		   }
        else 
           {
		   printf("0");
		   }
 	}
    printf("\n");
}

void fun6()
{
   int str[256], i, j, cont;
   printf("\nDigite o numero decimal: ");
   scanf("%d", &cont);
   getchar();
   i=0;
   while(cont> 0)
   {
    str[i] = cont % 16;
    i++;
    cont = cont / 16;
   }
   printf("\n");
   for(j = i - 1; j >= 0; j--)
   {
   	 if(str[j] >= 0 && str[j] <= 9 )
	     printf("%d", str[j]);
	    if(str[j] == 10)
	    {
	     printf("A");
		}
	    if(str[j] == 11)
    	{
	     printf("B");
		}
	    if(str[j] == 12)
	    {
    	 printf("C");
	 	}
	    if(str[j] == 13)
	    {
   		    printf("D");
 		}
	    if(str[j] == 14)
	    {
	     printf("E");
	 	}
	    if(str[j] == 15)
	    {
	     printf("F");
	 	}
    }
}

void fun7()
{
   char oct[256], aux[256];
   int i=0, j, flag=0, octal=1, num;
   printf("\nDigite o numero em octal: ");
   scanf("%s", oct);
   getchar();
   while(oct[i] != '\0')
   {
    i++;
    flag++;
   }
   j = flag -1;
   for(i=0; i<flag; i++, j--)
   {
    aux[j] = oct[i];
   }
   num=0;
   for(j=1; j<flag;j++)
   {
    octal=octal*8;
    if(aux[j] == '1')
     	num = num + octal;
    if(aux[j] == '2')
   		num = num + 2*octal;
    if(aux[j] == '3')
    	num = num+ 3*octal;
    if(aux[j] == '4')
     	num = num + 4*octal;
    if(aux[j] == '5')
     	num = num + 5*octal;
    if(aux[j] == '6')
     	num = num + 6*octal;
    if(aux[j] == '7')
     	num = num + 7*octal;
   }
   if(aux[0] == '1')
    {
    num = num +1;
	}
   if(aux[0] == '2')
    {
    num = num + 2;
	}
   if(aux[0] == '3')
    {
    num= num + 3;
	}
   if(aux[0] == '4')
    {
    num = num + 4;
	}
   if(aux[0] == '5')
   {
   	num = num + 5;
   }
   if(aux[0] == '6')
    {
    num = num + 6;
	}
   if(aux[0] == '7')
    {
    num = num + 7;
	}
   printf("\nNumero convertido eh: %d ", num);
}

void fun8()
{
   int dec, oct[256], i=0, j;
   printf("\nDigite o numero decimal: ");
   scanf("%d", &dec);
   getchar();
   while(dec > 0)
   {
    oct[i] = dec % 8;
    i++;
    dec = dec/8;
   }
   printf("\n");
   printf("\nNumero covertido eh: ");
   for(j = i - 1; j >= 0; j--)
    printf("%d", oct[j]);	
}
