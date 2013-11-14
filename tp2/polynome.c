#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include "polynome.h"

polynome* creerPoly(int c,char* mode, ...)
{
  int i;
  polynome* P=(polynome*) malloc(sizeof(polynome));
  P->d = c-1;
  P->poln = (double*) malloc(c*sizeof(double));
  if ((strcmp(mode,"valeur"))==0)//si mode = "valeur"
  {
    va_list ap;
    va_start(ap, mode);
    for (i=0; i<c; i++)
    {
      P->poln[i]=va_arg(ap, double);
    }
    va_end(ap);
  }
  else //si mode= "tableau"
  {
    va_list ap;
    va_start(ap, mode);
    double* tmp=va_arg(ap, double*);
    for (i=0; i<c; i++)
    {
      P->poln[i]=tmp[i];
    }
    free(tmp);
    va_end(ap);
  }
  return P;
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
	if(i != 0) { printf(" + "); }
	if(i == 0) { printf("%f",P->poln[i]); }
	else if(i == 1) { printf("%f * x",P->poln[i]); }
	else { printf("%f * x^%d", P->poln[i],i); }
      }
      if(P->poln[i] < 0) 
      {
			if(i == 0) { printf("-%f",-(P->poln[i])); }
			else if(i == 1) { printf("-%f * x",-(P->poln[i])); }
			else { printf("-%f * x^%d", -(P->poln[i]), i); }
      }
    }
    printf("\n");
  }
  else
  {
    va_list ap;
    va_start(ap,mode);
    f = va_arg(ap,FILE*);
    fprintf(f,"$P(x)= ");
    for(i=0; i<c; i++)
    {
      if(P->poln[i] > 0)
      {
			if(i != 0) { fprintf(f," + "); }
			if(i == 0) { fprintf(f,"%f",P->poln[i]); }
			else if(i == 1) { fprintf(f,"%f \\cdot x",P->poln[i]); }
			else { fprintf(f,"%f \\cdot x^{%d} ", P->poln[i],i); }
      }
      if(P->poln[i] < 0)
      {
			if(i == 0) { fprintf(f,"-%f", -(P->poln[i])); }
			else if(i == 1) { fprintf(f,"-%f \\cdot x", -(P->poln[i])); }
			else { fprintf(f,"- %f \\cdot x^{%d} ", -(P->poln[i]), i); }
      }
    }
    fprintf(f,"$\n");
    va_end(ap);
  }
}


void redimensionnerPoly(polynome* P1)
{
  int degre=P1->d;
  while((P1->poln[degre])==0)
  {
    degre--;
  }
  if(degre!=P1->d)
  {
    P1->d=degre;
    P1->poln= (double*) realloc(P1->poln, (degre+1)*sizeof(double));
  }
}


polynome* addPoly(polynome* P1, polynome* P2)
{
  // Rappel : Deg(P1+P2) <= max(Deg(P1),Deg(P2))
  int i;
  polynome* P;
  if(P1->d > P2->d) // Deg(P1) > Deg(P2)
  {
    P->d = P1->d;
    P->poln = (double*) malloc((1+P1->d)*sizeof(double));
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
    P->poln = (double*) malloc((1+P2->d)*sizeof(double));
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
    P->poln = (double*) malloc((1+P2->d)*sizeof(double));
    for(i=0;i <= P1->d;i++)
    {
      P->poln[i] = P1->poln[i] + P2->poln[i];
    }
  }
  redimensionnerPoly(P);
  return P;
}

polynome* mulSPoly(double s, polynome* P1)
{
  int i;
  polynome* P;
  P->d = P1->d;
  P->poln = (double*) malloc((1+P1->d)*sizeof(double));
  
  for(i=0;i <= P1->d;i++)
  {
    P->poln[i] = s*P1->poln[i] ;
  }
  redimensionnerPoly(P); //redimensionnement nécessaire si le scalaire est nul.
  return P;
}


polynome* mulPoly(polynome * P1, polynome* P2)
{
  int i,j;
  polynome* P=(polynome*)malloc(sizeof(polynome));
  P->d = P1->d + P2->d ;
  P->poln = (double*) malloc((1+P->d)*sizeof(double));
  
  for(i=0; i<=P->d; i++)
  {
    P->poln[i] = 0;
  }
  
  for(i=0; i<=(P2->d); i++)
  {
    for(j=0; j<=(P1->d); j++)
    {
      P->poln[i+j] = P->poln[i+j] + (P2->poln[i])*(P1->poln[j]);
    }
  }
  
  redimensionnerPoly(P);
  return P;
}
