//Gladson Oliveira Silva      nº 11811EEL002
#include <stdio.h>
#include <stdio.h>

typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual;}
LCG;

void semente(LCG * r, Bytes8 seed) 
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) //retorna um vetor entre 0.5 e 1.5
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *i_vet, float *f_vet)
{
	float aux;
	while (i_vet != f_vet + 1)
	{
		aux = (*i_vet + soma(i_vet + 1, f_vet));
		return aux;
	}
	return 0;
}

float produto(float *i_vet, float *f_vet)
{
	float aux;
	while (i_vet != f_vet + 1)
	{
		aux = (*i_vet * produto(i_vet + 1, f_vet));
		return aux;
	}
	return 1;	
}
int main()
{
	LCG random;
   	semente(&random, 123456);
	int flag;
	float vet[50];	
	gera_numeros(vet, 50, 0.5, 1.5, &random);
	do
	{
		printf("DIGITE:\n1- Somatorio\n2-Produtorio\n3-Sair do programa\n\n\n");
		scanf ("%d", &flag);
		getchar();
		switch (flag)
		{
			case 1:
				printf ("\nSomatorio: %.6f \n", soma (&vet[0], &vet[49]));
				break;
			case 2:
				printf ("\nProdutorio: %g \n", produto (&vet[0], &vet[49]));
				break;	
			default:
				if (flag != 3)
					printf ("\nERRO! \n");
		}	
	} while (flag != 3);
	return 0;
}