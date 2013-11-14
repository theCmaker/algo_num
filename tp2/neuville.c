#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"

void neuville (double ** tab, int n)
{
  int i, k;
  polynome*** t= (polynome***) malloc(n*sizeof(polynome**));
  for (i=0; i<n; i++)
  {
    t[i]= (polynome**) malloc(n*sizeof(polynome*));
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
      t[i][k]=mulSPoly((1/((tab[0][i-1])-(tab[0][i]))),addPoly(mulPoly(creerPoly(2,"valeur", -(tab[0][i]), 1.), t[i-1][k-1]), mulPoly(creerPoly(2, "valeur", tab[0][i-k], -1.),t[i][k-1])));
    }
  }
  
//   t[i][k]=(t[i][k-1]-t[k-1][k-1])/(tab[0][i]-tab[0][k-1]);
//   redimensionnerPoly(t[n-1][n-1]);
  
  //affichage
  menuAffichage(t[n-1][n-1]);
  printf("\n");
}