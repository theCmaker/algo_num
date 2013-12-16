#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "puissancesIt.h" 
#include "matrices.h" 
#include "file.h" 

void puissancesIt(double** A, int n)
{
  int i;
  double ecart = 1.;
  double** x1 = (double**) malloc (n*sizeof(double*));
  double** x2;
  double** x3;
  double** xt;
  double** xtx;
  //Initialisation de x1 -> vecteur unité
  for (i=0; i<n; i++)
  {
    x1[i] = (double*) malloc (sizeof(double));
    x1[i][0] = 1.;
  }
  while (ecart > 0.001)
  {
    x2 = produitMatriciel(A,x1,n,n,1); //x2 = A x1
    diviserComposantes(x2,n);
    x3 = difference(x2, x1, n, 1); //x3 = x2-x1
    ecart = norme(x3, n); //norme(x2-x1)-> écart
    //libération mémoire
    for (i=0; i<n; i++)
    {
      free(x3[i]);
      free(x1[i]);
    }
    free(x3);
    free(x1);
    x1 = x2; //xi = x(i+1)
  }
  printf("Approximation du vecteur propre :\n");
  for (i=0; i<n; i++)
  {
    printf("x[%d]=%f\n", (i+1), x1[i][0]);
  }
  xt = transpose(x1, n, 1);
  x2 = produitMatriciel(xt, A, 1, n, n); //xt A
  x3 = produitMatriciel(x2, x1, 1, n, 1); //xt A x
  xtx = produitMatriciel(xt, x1, 1, n, 1); //xt x
  printf("Approximation de la valeur propre maximum : %f\n", x3[0][0]/xtx[0][0]);
  //libération mémoire
  for (i=0; i<n; i++)
  {
    free(x1[i]);
  }
  free(xt[0]); free(x2[0]); free(x3[0]); free(xtx[0]);
  free(xt); free(x2); free(x3); free(xtx); free(x1);
}
