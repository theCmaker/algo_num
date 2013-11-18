#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"

void newton (double ** tab, int n)
{
  int i, k;
  double** t= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    t[i]= (double*) malloc((i+1)*sizeof(double));
  }
  
  //initialisation des valeurs : on récupère les y.
  for (i=0; i<n; i++)
  {
    t[i][0]=tab[1][i];
  }
  
  //calcul des differences divisees
  for (k=1; k<n; k++)
  {
    for (i=k; i<n; i++)
    {
      t[i][k]=(t[i][k-1]-t[k-1][k-1])/(tab[0][i]-tab[0][k-1]);
    }
  }
  
  //tableau de polynomes
  polynome** tabP= (polynome**) malloc(n*(sizeof(polynome*)));
  for (i=0; i<n; i++)
  {
    tabP[i]=(polynome*) malloc(sizeof(polynome));
  }
  tabP[0]->d=0;
  tabP[0]->poln=(double*) malloc(sizeof(double));
  tabP[0]->poln[0]=t[n-1][n-1];
  
  for (i=1; i<n; i++)
  {
    tabP[i]=addPoly(creerPoly(1,"valeur",t[n-1-i][n-1-i]),mulPoly(creerPoly(2,"valeur",-tab[0][n-1-i], 1.),tabP[i-1]));
  }
  redimensionnerPoly(tabP[n-1]);
  
  //affichage
  menuAffichage(tabP[n-1]);
  ecartPoly(tab,n,tabP[n-1]);
  printf("\n");
  
  //libération mémoire
  for(i=0;i<n;i++)
  {
    free(tabP[i]->poln);
    free(tabP[i]);
    free(t[i]);
  }
  free(tabP);
  free(t);
}