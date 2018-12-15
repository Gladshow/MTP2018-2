//Gladson Oliveira Silva   nº 11811EEL002


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Pnt
{
    double x;
    double y;
};

struct Pnt *criar(int cont)
{

    struct Pnt *point=(struct Pnt*) malloc(cont*sizeof(struct Pnt));
    int i;

    for (i=0; i<cont; i++)
    {
    	point[i].x = cos(i*2.0*M_PI/(cont-1));
        point[i].y = sin(i*2.0*M_PI/(cont-1));
    }
    return point;
}
struct Pnt *r_p(unsigned int *pn)
{
	unsigned int cont = 0;
    struct Pnt *point = (struct Pnt *) malloc(sizeof(struct Pnt));
    FILE *past;
    past = fopen("pontuacao.dat", "rb");
    while(1)
    {
        fread(point, 1, sizeof(struct Pnt), past);
        if(feof(past))
        {
            break;
    	}
        cont++;
    }
    rewind(past);
   	point = (struct Pnt *) realloc(point, cont*sizeof(struct Pnt));
    fread(point, cont, sizeof(struct Pnt), past);
    fclose(past);
    *pn = cont;
    return point;
}
void kill_safe(struct Pnt *point, int cont);
void hurb(struct Pnt *point, int cont);
void xp (struct Pnt *point, struct Pnt *pf);

int main ()
{
    struct Pnt *point;
    int cont, flag;
    do
    {
        system ("cls");
		printf("DIGITE:\n1- Gerar arquivo c/ pontos\n2- Recuperar pontos do arquivo\n3- Sair do programa\n\n");
        scanf("%d", &flag);
        switch (flag)
        {
        case 1:
            printf ("\nDigite o numero de pontos: ");
            scanf ("%d", &cont);
            getchar();
            point = criar(cont);
            kill_safe(point, cont);
            hurb(point, cont);
            printf ("\nArquivo salvo");
            getch();
            break;
        case 2:
            point = r_p(&cont);
            xp(point, point+cont);
            getch ();
            break;
        default:
            if (flag != 3)
                printf("ERRO!");
            getch();
            break;
        }
    }
    while(flag != 3);
    free(point);
    return 0;
}

void kill_safe(struct Pnt *point, int cont)
{
    FILE *past;
    past = fopen("pontuacao.dat", "w");
    int i, j;
    for(i = 0; i < cont; i++)
    {
        for(j = 0; j < 20; j++)
        {
            fprintf(past, "%d\t%d\t\t", point[i].x, point[i].y);
        }
        fprintf(past, "\n");
    }
    fclose(past);
}

void hurb(struct Pnt *point, int cont)
{
    FILE * past;
    past = fopen("pontuacao.dat", "wb");
    fwrite (point, cont, sizeof(struct Pnt), past);
    fclose (past);
}
void xp (struct Pnt *point, struct Pnt *pf)
{
    if(point < pf)
    {
        printf("(%.3lf , %.3lf) \n", (*point).x, (*point).y);
        xp (point+1, pf);
    }
}