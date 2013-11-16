#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "neuville.h" 
#include "newton.h" 
#include "polynome.h"
#include "reglin.h"

int main (int argc, char ** argv)
{
  int n, j;
  int i=1;
  while (i!=0)
  {
    printf("Menu principal : Interpolation et Approximation\n\n");
    n=0;
    while (n<2) //minimum 2 points
    {
      printf("Entrez n le nombre de points : ");
      scanf("%d", &n);
    }
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
    while (i!=0 && i!=9)
    {
      printf("\nTableau de valeurs :\n");
      for (i=0; i<2; i++)
      {
	for (j=0; j<n; j++)
	{
	  if (0==j && 0==i)
	  {
	    printf(" x ");
	  }
	  else if (0==j && 1==i)
	  {
	    printf(" y ");
	  }
	  printf("| %+.5f ", tab[i][j]);
	}
	printf("\n");
      }
      printf("Quelle résolution utiliser ?\n");
      printf("1- Lagrange\n");
      printf("2- Newton\n");
      printf("3- Neuville\n");
      printf("4- Régression Linéaire par une droite\n");
      printf("5- Regression Linéaire par une fonction exponentielle\n");
      printf("6- Regression Linéaire par une fonction puissance\n");
      printf("9- Nouvelle série de points (Menu principal)\n");
      printf("0- Quitter\n");
      printf("Votre choix : ");
      scanf("%d", &i);
      switch (i)
      {
	case 1:
	  printf("Résolution par Lagrange...\n");
// 	  lagrange(tab,n);
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
	  printf("Résolution par Régression linéaire par une droite ... \n");
	  reglinD(tab,n);
	  break;
	case 5:
	  printf("Résolution par Régression linéaire par une fonction exponentielle... \n");
	  reglinE(tab,n);
	  break;
	case 6:
	  printf("Résolution par Régression linéaire par une fonction puissance... \n");
	  reglinP(tab,n);
	  break;
      }
      printf("\n\n");
    }
    
    //libération mémoire
    for (j=0; j<2; j++)
    {
      free(tab[j]);
    }
    free(tab);
  }
  return 0;
}
