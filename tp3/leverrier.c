#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "leverrier.h" 
#include "matrices.h"
#include "polynome.h"

void leverrier(double** A, int n)
{
  int i, j;
  double tempo;
  double* coeffs=(double*) malloc ((n+1)*sizeof(double)); //tableau coeffs
  double* traces=(double*) malloc(n*sizeof(double)); //tableau traces
  double** tmp;
  polynome* p=(polynome*) malloc(sizeof(polynome));
  
  //On remplit notre tableau contenant les traces 
  for (i=1; i<=n; i++)
  {
    tmp=puissanceMatrice(A, n, i);
    traces[i-1]=trace(tmp, n);
    for (j=0; j<n; j++)
    {free(tmp[j]);}
    free(tmp);
  }
  
  //On remplit le tableau des coefficients
  for(i=0; i<=n; i++)
  {
    coeffs[i]=0;
  }
  coeffs[0]=pow(-1.0,n);
  for(i=1; i<=n; i++)
  {
    for(j=0;j<i;j++)
    {
      coeffs[i] = coeffs[i] - coeffs[j]*traces[i-j-1];
    }
    coeffs[i] = coeffs[i]/i;
  }
  //On inverse le tableau des coefficients
  for(i=0;i<=(n/2)-1;i++)
  {
    tempo = coeffs[i];
    coeffs[i] = coeffs[n-i];
    coeffs[n-i] = tempo;
  }
  p=creerPoly(n+1, "tableau", coeffs);
  menuAffichage(p);
  
  //liberation memoire
  //libération du tableau de trace
  free(traces);
  free(coeffs);
  //libération du polynome
  free(p->poln);
  free(p);
  
   //----- For you my rubber duck ! 
}
