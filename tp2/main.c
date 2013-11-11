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
  FILE* fichier = NULL;
  if (argc>=1) //demande sortie LaTeX -> ouverture du fichier resultat
  {
    fichier=fopen("resultat", "a+");
  }
  printf("Interpolation et Approximation\n\n");
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
  i=1;
  while (i!=0)
  {
    printf("\nQuelle résolution utiliser ?\n");
    printf("1- Newton\n");
    printf("2- Neuville\n");
    printf("3- Régression Linéaire\n");
    printf("0- Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &i);
    switch (i)
    {
      case 1: 
	printf("Résolution par Newton ... \n");
	newton(tab,n);
	break;
      case 2:
	printf("Résolution par Neuville ... \n");
// 	neuville(tab,n);
	break;
      case 3:
	printf("Résolution par Régression linéaire ... \n");
// 	regressionlineaire(tab,n);
	break;	
    }
  }
  if (argc>=1)
  {
    fclose(fichier);
  }
  //libération mémoire
  free(fichier);
  for (i=0; i<n; i++)
  {
    free(tab[i]);
  }
  free(tab);
  return 0;
}
