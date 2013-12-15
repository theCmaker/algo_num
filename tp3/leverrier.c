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
  polynome* p;
  
  //On remplit notre tableau contenant les traces 
  for (i=1; i<=n; i++)
  {
    tmp=puissanceMatrice(A, n, i);
    traces[i-1]=trace(tmp, n);
    for (j=0; j<n; j++)
    {
      free(tmp[j]);
    }
    free(tmp);
  }
  
  //On remplit le tableau des coefficients
  for(i=0; i<=n; i++)
  {
    coeffs[i]=0;
  }
  coeffs[n]=pow(-1.0,n);
  for(i=1; i<=n; i++)
  {
    for(j=0;j<i;j++)
    {
      coeffs[n-i] = coeffs[n-i] - coeffs[n-j]*traces[i-j-1];
    }
    coeffs[n-i] = coeffs[n-i]/i;
  }
  p=creerPoly(n+1, "tableau", coeffs);
  menuAffichage(p);
  
  //liberation memoire
  //libération du tableau de trace
  free(traces);
  //libération du polynome
  free(p->poln);
  free(p);
}

void leverrierA(double** A, int n)
{
  int i, j;
  double tempo;
  double** tmp;
  double* coeffs=(double*) malloc ((n+1)*sizeof(double)); //tableau coeffs
  double** Ak=(double**) malloc (n*sizeof(double*));
  double** B=(double**) malloc (n*sizeof(double*));
  double** I=(double**) malloc (n*sizeof(double*));
  polynome* p;
  
  for (i=0; i<n; i++)
  {
    Ak[i]=(double*) malloc (n*sizeof(double));
    I[i]=(double*) malloc (n*sizeof(double));
    B[i]=(double*) malloc (n*sizeof(double));
  }
  
  //Création matrice identité, initialisation de B et copie de A
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      Ak[i][j]=A[i][j];
      if (i==j) 
      {
        I[i][j]=1; 
        B[i][j]=1;
      }
      else 
      {
        I[i][j]=0; 
        B[i][j]=0;
      }
    }
  }
  
  //On remplit le tableau des coefficients
  for(i=0; i<=n; i++)
  {
    coeffs[i]=0;
  }
  
  coeffs[0]=pow(-1,n);
  
  
  for(i=1; i<=n; i++)
  {
    Ak=produitMatriciel(B,A,n,n,n);
    coeffs[i]=trace(Ak,n)/i;
    tmp=produitSMatriciel(I,n,n,coeffs[i]);
    for(j=0;j<n;j++)
    {
      free(B[j]);
    }
    free(B);
    B=difference(Ak,tmp,n,n);
    for(j=0;j<n;j++)
    {
      free(Ak[j]);
      free(tmp[j]);
    }
    free(tmp); free(Ak);
  }
  
  //On inverse le tableau des coefficients
  for(i=0;i<=((n+1)/2)-1;i++)
  {
    if ((n%2) == 0)
    {
      coeffs[i]=-coeffs[i];
    }
    tempo = coeffs[i];
    coeffs[i] = coeffs[n-i];
    coeffs[n-i] = tempo;
  }
  
  p=creerPoly(n+1, "tableau", coeffs);
  menuAffichage(p);
  
  //liberation memoire
  for (i=0; i<n; i++)
  {
    free(B[i]);
  }
  free(B);
  //libération du polynome
  free(p->poln);
  free(p);
}