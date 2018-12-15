//Gladson Oliveira Silva   nº 11811EEL002

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef
	struct flag 
	{
		float x;
		float y;
	}Point;

	Point * gerap(int number)
	{
		Point * flag = (Point *) calloc(number,sizeof(Point));
		int i;
		for(i=0; i<number; i++)
		{
			flag[i].x = cos(i*2.0*M_PI/(number-1));
			flag[i].y = sin(i*2.0*M_PI/(number-1));
		}
		return flag;
	}	

void M_apres(Point * pi, Point * volt){
	if(volt> pi)
	{
		printf("<%.3f, %.3f> ", pi->x, pi->y);
		M_apres(pi+1, volt);
	}
}

int main()
{
	unsigned int number;
	Point * flag;
	printf("Entre com o numero de pontos: ");
	scanf("%d",&number);
	getchar();
	flag = gerap(number);
	M_apres(flag, flag+number);
	free(flag);
	return 0;
}