//Gladson Oliveira Silva  nº11811EEL002
//P4

#include <stdio.h>

int recur(int m, int n);

int main()
{
	int m, n;
	printf("DIGITE OS VALORES M, N, RESPECTIVAMENTE:\n");
	scanf("%d%d", &m, &n);
	printf("%d", recur(m,n));
	return 0;
}

int recur(m, n)
{
	if(m>0 && n==0)
	{
		recur(m-1,1);
	}
	if (m==0)
	{
		n++;
		return n;
	}
	if (m>0 && n>0)
	{
		recur(m- 1, recur(m, n- 1));
	}
}