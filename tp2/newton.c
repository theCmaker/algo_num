#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"
#include "newton.h" 

void newton (double ** tab, int n)
{
  int i, k;
  double** t= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    t[i]= (double*) malloc(n*sizeof(double));
  }
  //initialisation des valeurs : on récupère les y.
  for (i=0; i<n; i++)
  {
    t[i][0]=tab[1][i];
  }
  //calcul des differences divisees
  for (k=1; k<n; k++)
  {
    for (i=k-1; i<n; i++)
    {
      t[i][k]=(t[i][k-1]-t[k-1][k-1])/(tab[0][i]-tab[0][k]);
    }
  }
  //tableau de polynomes
  polynome** tabP= (polynome**) malloc(n*(sizeof(polynome*)));
  tabP[0]->d=0;
  tabP[0]->poln=(double*) malloc(sizeof(double));
  tabP[0]->poln[0]=t[n-1][n-1];
  
  polynome* tmp=(polynome*) malloc(sizeof(polynome));
  tmp->d=0;
  tmp->poln=(double*) malloc(sizeof(double));
  
  for (i=1; i<n; i++)
  {
    tmp->poln=creerPoly(1,"valeurs",t[n-1-i][n-1-i]); //??
    tabP[i]->d=i;
    tabP[i]->poln=(double*) malloc((i+1)*sizeof(double));
//     tab[i]->poln=addPoly(tmp,multPoly(/*Créer polynome*/,tabP[i-1]))
  }
  //calcul du polynome
  polynome* P=creerPoly(1,"valeur", t[]);
  
  
  //affichage
//   int choix; // permet de choisir les options voulues
  // 
  //affichage du polynome en console
  // affichage du polynome en format latex
    
//   printf("Voulez-vous afficher le polynome dans la sortie standard ? 1-Oui Autre-Non");
//   scanf("%d",&choix);
//   if(choix ==1)
//   {
//     afficherPoly(P,"console");
//   }
//   else
//   {
//     afficherPoly(P,"latex",fichier);
//   }


//   for (i=0; i<n; i++)
//   {
//     if(t[i][i+1] != 0)
//     {
//       if (i>0)
//       {
// 	printf(" + ");
//       }
//       for (k=0; k<i; k++)
//       {
// 	if(t[k][0] >0) {printf("(x-%f)",t[k][0]);}
// 	if(t[k][0] <0) {printf("(x+%f)",-t[k][0]);}
//       }
//       printf("%f", t[i][i+1]);
//     }
//   }
  printf("\n");
}