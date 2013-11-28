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
  double somme;
  double* coeffs=(double*) malloc ((n+1)*sizeof(double)); //tableau coeffs
  double* traces=(double*) malloc(n*sizeof(double)); //tableau traces
  double** tmp;
  polynome* p=(polynome*) malloc(sizeof(polynome));
  for (i=1; i<=n; i++)
  {
    tmp=puissanceMatrice(A, n, i);
    traces[i-1]=trace(tmp, n);
    for (j=0; j<n; j++)
    {free(tmp[j]);}
    free(tmp);
  }
  coeffs[0]=pow(-1.0,n);
  for (i=1; i<=n; i++)
  {
    somme=0;
    for (j=0; j<i; j++)
    {
      somme=somme+coeffs[i]*traces[i-j-1];
    }
    coeffs[i]=(-1/i)*somme;
  }
  p=creerPoly(n, "tableau", coeffs);
  menuAffichage(p);
  
  //liberation memoire
   //----- For you my rubber duck ! 
}