#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include "polynome.h"

polynome* creerPoly(int c,char* mode, ...)
{
// 	int i;
// 	polynome* P;
// 	P->d = c-1
// 	P->poln = (double*) malloc(c*sizeof(double));
// 	//variable si mode = "valeur"
// 	if ((strcmp(mode,"")))
}


void afficherPoly(polynome* P, char* mode, ...)
{
  int i;
  FILE* f;
  int c = (P->d) +1 ;
  if((strcmp(mode,"console")) == 0)
  {
    printf("P(x) = ");
    for(i=0;i<c;i++)
    {
      if(P->poln[i] > 0) 
      {
	if(i != 0) { printf("+"); }
	printf("%f * x^%d ", P->poln[i],i);
      }
      if(P->poln[i] < 0) 
      {
	printf("- %f * x^%d", -(P->poln[i]), i);
      }

    }
  }
  else
  {
    va_list  ap;
    va_start(ap,mode);
    f = va_arg(ap,FILE*);
    fprintf(f,"$P(x)= ");
    for(i=0; i<c; i++)
    {
      if(P->poln[i] > 0)
      {
	if(i != 0) { fprintf(f,"+ "); }
	fprintf(f,"%f \\cdot x^{%d} ", P->poln[i],i);
      }
      if(P->poln[i] < 0)
      {
	fprintf(f,"- %f \\cdot x^{%d} ", -(P->poln[i]), i);
      }
    }
    fprintf(f,"$\n");
    va_end(ap);
  }
}


// polynome* redimensionnerPoly(polynome* P1)
// {
// 	
// }


polynome* addPoly(polynome* P1, polynome* P2)
{
	// Rappel : Deg(P1+P2) <= max(Deg(P1),Deg(P2))
	int i;
	polynome* P;
	if(P1->d > P2->d) // Deg(P1) > Deg(P2)
	{
		P->d = P1->d;
		P->poln = (double*) malloc((1+P1->d)*sizeof(double);
		for(i=0;i <= P2->d;i++)
		{
			P->poln[i] = P1->poln[i] + P2->poln[i];
		}
		for(i= P2->d +1; i<= P1->d; i++)
		{
			P->poln[i] = P1->poln[i];
		}
	}
	else if (P1->d < P2->d) // Deg(P2) > Deg(P1)
	{
		P->d = P2->d;
		P->poln = (double*) malloc((1+P2->d)*sizeof(double);
		for(i=0;i <= P1->d;i++)
		{
			P->poln[i] = P1->poln[i] + P2->poln[i];
		}
		for(i= P1->d +1; i<= P2->d; i++)
		{
			P->poln[i] = P2->poln[i];
		}
	}
	else // Deg(P2) = Deg(P1)
	{
		P->d =  P2->d;
		P->poln = (double*) malloc((1+P2->d)*sizeof(double);
		for(i=0;i <= P1->d;i++)
		{
			P->poln[i] = P1->poln[i] + P2->poln[i];
		}
	}
	P=redimensionnerPoly(P);
	return P;
}

polynome* mulSPoly(double s, polynome* P1)
{
	int i;
	polynome* P;
	P->d = P1->d;
	P->poln = (double*) malloc((1+P1->d)*sizeof(double);
	
	for(i=0;i <= P1->d;i++)
	{
		P->poln[i] = s*P1->poln[i] ;
	}
	P = redimensionnerPoly(P);
	return P;
}


polynome* mulPoly(polynome * P1, polynome* P2)
{
	int i,j, k;
	polynome* P;
	P->d = P1->d + P2->d ;
	P->poln = (double*) malloc((1+P->d)*sizeof(double));

	
	for(i=0;i<= P->d; i++)
	{
		P->poln[i] = 0;
	}
	
	for(i=0;i<=P->d;i++)
	{
		for(j=0; j<i;j++)
		{
			P->poln[i+j] = P->poln[i+j] + P1->poln[i]*P2->poln[j];
		}
	}
	
	P=redimensionnerPoly(P);
	return P;
}
