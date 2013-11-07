 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "neuville.h" 
#include "newton.h" 

int main (int argc, char ** argv)
{
  int n, i, j;
  printf("Entrez n le nombre de points : ");
  scanf("%d", &n);
  double** tab= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    tab[i]=(double*) malloc((n+1)*sizeof(double));
    for (j=2; j<n+1; j++)
    {
      tab[i][j]=0;
    }
  }
  for (i=0; i<n; i++)
  {
    printf("Entrez x[%d] : ", i+1);
    scanf("%lf", &tab[i][0]);
    printf("Entrez y[%d] : ", i+1);
    scanf("%lf", &tab[i][1]);
  }
  printf("Résolution par Newton ...  \n");
  newton(tab,n);
  printf("Résolution par Neuville ...  \n");
  neuville(tab,n);
  printf("Résolution par la regression linéaire ...  \n");
  regressionlineaire(tab,n);
  
  

  return 0;
}
