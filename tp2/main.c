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
  FILE* fichier;
  if (argc>1) //demande sortie LaTeX -> ouverture du fichier resultat
  {
    fichier=fopen("resultat", "a+");
  }
  polynome* P1= (polynome*) malloc(sizeof(polynome));
  polynome* P2= (polynome*) malloc(sizeof(polynome));
  polynome* P3= (polynome*) malloc(sizeof(polynome));
  double* tab=(double*) malloc(4*sizeof(double));
  tab[0]=+1.;
  tab[1]=+2.;
  tab[2]=+3.;
  tab[3]=+4.;
  P1=creerPoly(4, "tableau", tab); 
  afficherPoly(P1, "console");
  P2=creerPoly(4, "valeur", 1., 2., 3., 4.); 
  afficherPoly(P2, "console");
  P3=mulPoly(P1,P2);
  afficherPoly(P3, "console");
  
  if (argc>1)
  {
    afficherPoly(P1, "latex", fichier);
  }
  
//   printf("Interpolation et Approximation\n\n");
//   printf("Entrez n le nombre de points : ");
//   scanf("%d", &n);
//   double** tab= (double**) malloc(n*sizeof(double*));
//   for (i=0; i<n; i++)
//   {
//     tab[i]=(double*) malloc((n+1)*sizeof(double));
//     for (j=2; j<n+1; j++)
//     {
//       tab[i][j]=0;
//     }
//   }
//   for (i=0; i<n; i++)
//   {
//     printf("Entrez x[%d] : ", i+1);
//     scanf("%lf", &tab[i][0]);
//     printf("Entrez y[%d] : ", i+1);
//     scanf("%lf", &tab[i][1]);
//   }
//   i=1;
//   while (i!=0)
//   {
//     printf("\nQuelle résolution utiliser ?\n");
//     printf("1- Lagrange\n");
//     printf("2- Newton\n");
//     printf("3- Neuville\n");
//     printf("4- Régression Linéaire\n");
//     printf("0- Quitter\n");
//     printf("Votre choix : ");
//     scanf("%d", &i);
//     switch (i)
//     {
//       case 1:
// 	printf("Résolution par Lagrange...\n");
// // 	lagrange(tab,n);
// 	break;
//       case 2: 
// 	printf("Résolution par Newton ... \n");
// // 	newton(tab,n);
// 	break;
//       case 3:
// 	printf("Résolution par Neuville ... \n");
// // 	neuville(tab,n);
// 	break;
//       case 4:
// 	printf("Résolution par Régression linéaire ... \n");
// // 	regressionlineaire(tab,n);
// 	break;
//     }
//   }
  if (argc>1)
  {
    fclose(fichier);
  }
//   //libération mémoire
//   for (i=0; i<n; i++)
//   {
//     free(tab[i]);
//   }
//   free(tab);
  return 0;
}
