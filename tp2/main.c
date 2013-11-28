#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "neville.h" 
#include "newton.h" 
#include "polynome.h"
#include "reglin.h"
#include "useful.h"

int main (int argc, char ** argv)
{
  int n, j;
  int i=1;
  char c;
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
      clear(); //nettoyage écran
      printf("Tableau de valeurs :\n");
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
	  printf("| %+4.5f ", tab[i][j]);
	}
	printf("\n");
      }
      printf("\nQuelle résolution utiliser ?\n");
      printf("1- Newton\n");
      printf("2- Neville\n");
      printf("3- Régression Linéaire\n");
      printf("4- Approximation par une fonction exponentielle\n");
      printf("5- Approximation par une fonction puissance\n");
      printf("9- Nouvelle série de points (Menu principal)\n");
      printf("0- Quitter\n");
      printf("Votre choix : ");
      scanf("%d", &i);
      c='0';
      cleanBuffer(); //vidage buffer
      switch (i)
      {
	case 1:
	  printf("Résolution par Newton ... \n");
	  newton(tab,n);
	  hitToContinue();
	  break;
	case 2:
	  printf("Résolution par Neville ... \n");
	  neville(tab,n);
	  hitToContinue();
	  break;
	case 3:
	  printf("Résolution par Régression linéaire ... \n");
	  reglinD(tab,n);
	  hitToContinue();
	  break;
	case 4:
	  printf("Résolution par Approximation par une fonction exponentielle... \n");
	  reglinE(tab,n);
	  hitToContinue();
	  break;
	case 5:
	  printf("Résolution par Approximation par une fonction puissance... \n");
	  reglinP(tab,n);
	  hitToContinue();
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
    clear(); //nettoyage écran
  }
  return 0;
}
