#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"

void neuville (double ** tab, int n)
{
  int i, k;
  polynome* pol1=(polynome*) malloc(sizeof(polynome));  
  polynome* pol2=(polynome*) malloc(sizeof(polynome));
  polynome* pol3=(polynome*) malloc(sizeof(polynome));
  polynome*** t= (polynome***) malloc(n*sizeof(polynome**));
  for (i=0; i<n; i++)
  {
    t[i]= (polynome**) malloc((i+1)*sizeof(polynome*));
  }
  //initialisation des valeurs : on récupère les y.
  for (i=0; i<n; i++)
  {
    t[i][0]=creerPoly(1,"valeur", tab[1][i]);
  }
  //calcul des differences divisees
  for (k=1; k<n; k++)
  {
    for (i=k; i<n; i++)
    {
      pol1=creerPoly(2, "valeur", tab[0][i-k], -1.); pol2=mulPoly(pol1,t[i][k-1]);
      free(pol1->poln); free(pol1);
      pol1=creerPoly(2,"valeur", -(tab[0][i]), 1.); pol3=mulPoly(pol1, t[i-1][k-1]);
      free(pol1->poln); free(pol1);
      pol1=addPoly(pol3, pol2);
      t[i][k]=mulSPoly((1/((tab[0][i-k])-(tab[0][i]))),pol1);
      free(pol1->poln); free(pol2->poln); free(pol3->poln); free(pol1); free(pol2); free(pol3);
    }
  }
  //poly à  retourner
  redimensionnerPoly(t[n-1][n-1]);
  //affichage
  menuAffichage(t[n-1][n-1]);
  ecartPoly(tab,n,t[n-1][n-1]);
  printf("\n");
  //libération mémoire
  for(i=0;i<n;i++)
  {
    for(k=0;k<i;k++)
    { free(t[i][k]->poln); free(t[i][k]); }
    free(t[i]);
  }
  free(t);
}