#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "neuville.h" 
#include "newton.h" 
#include "polynome.h"

int main (int argc, char ** argv)
{
  int n, i, j;
  printf("Menu principal : Interpolation et Approximation\n\n");
  printf("Entrez n le nombre de points : ");
  scanf("%d", &n);
  double** tab= (double**) malloc(2*sizeof(double*));
  for (i=0; i<2; i++)
  {
    tab[i]=(double*) malloc(n*sizeof(double));
  }
  for (i=0; i<n; i++)
  {
    printf("Entrez x[%d] : ", i+1);
    scanf("%lf", &tab[0][i]);
    printf("Entrez y[%d] : ", i+1);
    scanf("%lf", &tab[1][i]);
  }
  i=1;
  while (i!=0)
  {
    printf("\nQuelle résolution utiliser ?\n");
    printf("1- Lagrange\n");
    printf("2- Newton\n");
    printf("3- Neuville\n");
    printf("4- Régression Linéaire\n");
    printf("0- Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &i);
    switch (i)
    {
      case 1:
	printf("Résolution par Lagrange...\n");
// 	lagrange(tab,n);
	break;
      case 2: 
	printf("Résolution par Newton ... \n");
	newton(tab,n);
	break;
      case 3:
	printf("Résolution par Neuville ... \n");
	neuville(tab,n);
	break;
      case 4:
	printf("Résolution par Régression linéaire ... \n");
// 	regressionlineaire(tab,n);
	break;
    }
  }
  
  //libération mémoire
  for (i=0; i<2; i++)
  {
    free(tab[i]);
  }
  free(tab);
  return 0;
}
