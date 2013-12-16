#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrices.h"
#include "polynome.h"
#include "leverrier.h"
#include "generateur.h"

int main (int argc, char ** argv)
{
  int n, j, g, choice;
  double p;
  double** A;
  int i=1;
  while (i!=0)
  {
    printf("Menu principal : Polynome caractéristique, valeurs propres et vecteurs propres\n\n");
    printf("Choisir le mode de saisie de la matrice ? \n");
    printf("1-Utiliser le générateur de matrices\n");
    printf("0-Entrer manuellement les valeurs\n");
    printf("Votre choix : ");
    scanf("%d",&g);
    if(g)
    {
      printf("\n\nMENU : GENERATION DE MATRICES\n\n");
      printf("Choisir un type de matrice à générer :\n");
      printf("1. Creuse à 70%%\n");
      printf("2. A bord\n");
      printf("3. Ding-Dong\n");
      printf("4. Franc\n");
      printf("5. Hilbert\n");
      printf("6. KMS\n");
      printf("7. Lehmer\n");
      printf("8. Lotkin\n");
      printf("9. Moler\n");
      printf("Votre choix : ");
      scanf("%d", &choice);
      printf("Dimension : ");
      scanf("%d", &n);
      switch (choice)
      {
	case 1:
	  A=creuse70(n);
	  break;
	case 2:
	  A=bord(n);
	  break;
	case 3:
	  A=dingDong(n);
	  break;
	case 4:
	  A=franc(n);
	  break;
	case 5:
	  A=hilbert(n);
	  break;
	case 6:
	  printf("Parametre p : ");
	  scanf("%lf", &p);
	  A=kms(n,p);
	  break;
	case 7:
	  A=lehmer(n);
	  break;
	case 8:
	  A=lotkin(n);
	  break;
	case 9:
	  A=moler(n);
	  break;
      }
      printf("Matrice générée :\n");
      afficherMatrice(A, n, n);
    }
    else
    {
      printf("Matrice A :\n");
      printf("Dimension : ");
      scanf("%d",&n);
      A=creerRemplirMatrice(n,n);
    }
    cleanBuffer();
    hitToContinue();
    i=1;
    while (i!=0 && i!=9)
    {
      clear();
      printf("Que voulez-vous faire ?\n");
      printf("1- Méthode de Leverrier\n");
      printf("2- Méthode de Leverrier améliorée\n");
      printf("3- Méthode des Puissances Itérées\n");
      printf("9- Nouvelle matrice (Menu principal)\n");
      printf("0- Quitter\n");
      printf("Votre choix : ");
      scanf("%d", &i);
      cleanBuffer(); //vidage buffer
      convertMattoLatex(A,n,n);
      switch (i)
      {
	case 1:
	  printf("Polynome caracteristique par Leverrier... \n");
	  leverrier(A,n);
	  hitToContinue();
	  break;
	case 2:
	  printf("Polynome caracteristique par Leverrier améliorée ... \n");
	  leverrierA(A,n);
	  hitToContinue();
	  break;
	case 3:
	  printf("Méthode des puissances itérées ... \n");
	  puissancesIt(A,n);
	  hitToContinue();
	  break;
// 	case 4:
// 	  printf("Résolution par Approximation par une fonction exponentielle... \n");
// 	  reglinE(tab,n);
// 	  hitToContinue();
// 	  break;
// 	case 5:
// 	  printf("Résolution par Approximation par une fonction puissance... \n");
// 	  reglinP(tab,n);
// 	  hitToContinue();
// 	  break;
      }
      printf("\n\n");
    }
    
    //libération mémoire
    for (j=0; j<n; j++)
    {
      free(A[j]);
    }
    free(A);
    clear(); //nettoyage écran
  }
  return 0;
}
