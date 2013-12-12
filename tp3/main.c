#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrices.h"
#include "polynome.h"
#include "leverrier.h"

int main (int argc, char ** argv)
{
  int n, j;
  double** A;
  int i=1;
  while (i!=0)
  {
    printf("Menu principal : Polynome caractéristique, valeurs propres et vecteurs propres\n\n");
    printf("Matrice A :\n");
    printf("Dimension : ");
    scanf("%d",&n);
    A=creerRemplirMatrice(n,n);
    convertMattoLatex(A,n,n);
  
    i=1;
    while (i!=0 && i!=9)
    {
      printf("\nQue voulez-vous faire ?\n");
      printf("1- Méthode de Leverrier\n");
      printf("2- Méthode de Leverrier améliorée\n");
      printf("9- Nouvelle matrice (Menu principal)\n");
      printf("0- Quitter\n");
      printf("Votre choix : ");
      scanf("%d", &i);
      cleanBuffer(); //vidage buffer
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
// 	case 3:
// 	  printf("Résolution par Régression linéaire ... \n");
// 	  reglinD(tab,n);
// 	  hitToContinue();
// 	  break;
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
