#include <stdio.h>

int recur(int m, int n)
{
	if(m == 0)
	{
		return n + 1; 
	}
	else if(m > 0 && n > 0)
	{
		recur(m - 1, recur(m, n - 1));
	}
	else if(m > 0 && n == 0)
	{
		recur(m - 1, 1);
	}
}

int main()
{
	int m, n;
	printf("Digite os valores de m e n\n\n");
	scanf("%i%i", &m,&n);
	printf("TEMOS:\n %i", recur(m,n));
	return 0;
}