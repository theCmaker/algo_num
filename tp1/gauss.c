#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

void gauss (double** a, double** b, int n)
{
  //initialisation
  int i, j, k;
  double pivot;
    
  //gauss
  for (k=0; k<n-1; k++)
  {
    for (i=k+1; i<n; i++)
    {
      pivot = a[i][k]/a[k][k];
      for (j=k+1; j<n; j++)
      {
        a[i][j]=a[i][j]-pivot*a[k][j];
      }
      b[i][0]=b[i][0]-pivot*b[k][0];
    }
    printf("\nMatrice :\n");
    afficherMatrice(a,n,n);
    printf("Vecteur :\n");
    afficherMatrice(b,n,1);
  }
  
  //calcul et affichage resultat
  double** x=solveTriangulaireSup(a, b, n);
  printf("\nRésultat :\n");
  afficherMatrice(x, n, 1);
  
  //libération mémoire
  for (i=0;i<n;i++)
  {
    free(x[i]);
  }
  free(x);
}
