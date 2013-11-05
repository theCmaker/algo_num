#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "gauss-seidel.h"

void surrelaxation (double** a, double** b, double** xInit, int n, double prec, double ohm)
{
  if (ohm==1)
  {gaussseidel(a,b,xInit,n,prec);}
  else
  {
    int i, j, cpt;
    double residu=2*prec;
    double** ax;
    double** axb;
    cpt=0;
    while (residu>=prec)
    {
      for (i=0; i<n; i++)
      {
        double somme1=0, somme2=0;
        for (j=0; j<i; j++)
        {
          somme1=somme1+a[i][j]*xInit[j][0];
        }
        for (j=i+1; j<n; j++)
        {
          somme2=somme2+a[i][j]*xInit[j][0];
        }
        xInit[i][0]=(1-ohm)*xInit[i][0]+(ohm/a[i][i])*(b[i][0]-somme1-somme2);
      }
      ax=produitMatriciel(a, xInit, n, n, 1);
      axb=difference(ax, b, n, 1);
      residu=norme(axb, n);
      cpt++;
      
      //affichage
      printf("\nVecteur à l'itération %d :\n", cpt);
      afficherMatrice(xInit, n, 1);
    }
    //libération mémoire
    for (i=0;i<n;i++) {free(ax[i]); free(axb[i]);}
    free(ax);free(axb);
  }
}
