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


// polynome* redimensionnerPoly(polynome* P)
// {
// 	
// }


// polynome* addPoly(polynome* P1, polynome* P2)
// {
// 	
// }
// polynome* mulPoly(polynome * P1, polynome* P2)
// {
// 	
// }
// 
// polynome* mulSPoly(double s, polynome* P1)
// {
// 	
// }