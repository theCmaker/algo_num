#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"

void cholesky (double ** a, double ** b, int n)
{
  int i, j, k;
  double **r = (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    r[i]=(double*) malloc(n*sizeof(double));
  }
  
  /*Calcul de R*/
  for (k=0; k<n; k++)
  {
    for (i=k; i<n; i++)
    {
      double somme=0;
      if(k==i)
      {
        for (j=0; j<k; j++) {somme=somme+r[i][j]*r[i][j]; }//somme des carrés
        r[i][k]=sqrt(a[i][k]-somme);
      }
      else
      {
        for (j=0; j<k; j++) {somme=somme+r[i][j]*r[k][j];}
        r[i][k]=(1.0/r[k][k])*(a[i][k]-somme);
      }
    }
  }
  printf("Matrice R :\n");
  afficherMatrice(r,n,n);
  printf("Matrice Rt :\n");
  afficherMatrice(transpose(r,n),n,n);
  
  /*Résolution de Ry=b*/
  double** y=solveTriangulaireInf(r,b,n);
  /*Résolution de tRx=y*/
  double** x=solveTriangulaireSup(transpose(r,n),y,n);
  
  /*Affichage de x*/
  printf("\nVecteur résultat :\n");
  afficherMatrice(x,n,1);

  // libération mémoire
  for (i=0; i<n; i++) {free(r[i]);} free(r);
}