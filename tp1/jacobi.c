#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"

void jacobi (double** a, double** b, double** xInit, int n, double prec)
{
  int i, j, cpt;
  double residu=2*prec;
  double** xNext= xInit;
  cpt=0;
  while (residu>=prec)
  {
    for (i=0; i<n; i++)
    {
      double somme1=0, somme2=0;
      for (j=0; j<i; j++) //avant l'élément diagonal
      {
        somme1=somme1+a[i][j]*xNext[j][0];
      }
      for (j=i+1; j<n; j++)
      {
        somme2=somme2+a[i][j]*xNext[j][0]; //après l'élément diagonal
      }
      xNext[i][0]=(1/a[i][i])*(b[i][0]-somme1-somme2);
    }
    double** ax=produitMatriciel(a, xNext, n, n, 1); //ax
    double** axb=difference(ax, b, n, 1); //ax - b
    residu=norme(axb, n); //norme de (ax - b)
    cpt++;

    //affichage
    printf("\nVecteur à l'itération %d :\n", cpt);
    afficherMatrice(xNext, n, 1);

    //libération mémoire
    for (i=0;i<n;i++)
    {
      free(ax[i]);
      free(axb[i]);
      free(xNext[i]);
    }
    free(ax);
    free(axb);
    free(xNext);
  }
}
