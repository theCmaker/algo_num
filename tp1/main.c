#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrices.h"
#include "gauss.h"
#include "cholesky.h"
#include "jacobi.h"
#include "surrelaxation.h"
#include "generateur.h"

int main (int argc, char ** argv)
{
  int n, i; //dimension matrices, indice de boucle
  int choice=1;
  double** A;
  double** b;
  double** xInit;
  double determinant;
  double prec;
  double ohm;
  srand (time(NULL));
  while (0!=choice)
  {
    printf("MENU PRINCIPAL : RESOLUTION D'EQUATIONS LINEAIRES\n\n");
    printf("1. Résolution par Gauss\n");
    printf("3. Résolution par Cholesky\n");
    printf("2. Résolution par Jacobi\n");
    printf("4. Résolution par Gauss-Seidel\n");
    printf("5. Résolution par Surrelaxation\n");
    printf("6. Génération de matrices carrées\n");
    printf("7. Jeux de test\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    if (choice!=0)
    {
      if (choice !=6)
      {
        printf("Systeme Ax=b\n");
        printf("Matrice A :\n");
        printf("Dimension : ");
        scanf("%d", &n);
        A=creerRemplirMatrice(n,n);
        printf("Vecteur b :\n");
        b=creerRemplirMatrice(n,1);
      }
      switch(choice)
      {
        case 1:
          /*Methode de Gauss*/
	  determinant=det(A,n);
	  printf("Déterminant : %f", determinant);
          printf("\nRésolution par Gauss...\n");
          gauss(A,b,n);
          break;
        case 2:
          /*Methode de Cholesky*/
          printf("\nRésolution par Cholesky...\n");
          cholesky(A,b,n);
          break;
        case 3:
          /*Methode de Jacobi*/
          printf("Conditions de la methode :\n");
          printf("Vecteur initial x0 :\n");
          xInit=creerRemplirMatrice(n,1);
          printf("Précision : ");
          scanf("%lf", &prec);
          printf("\nRésolution par Jacobi...\n");
          jacobi(A,b,xInit,n,prec);
	  //libération mémoire
	  for (i=0;i<n;i++)
	  {
	    free(xInit[i]);
	  }
	  free(xInit);
          break;
        case 4:
	  /*Methode de Gauss-Seidel*/
	  printf("Conditions de la methode :\n");
	  printf("Vecteur initial x0 :\n");
	  xInit=creerRemplirMatrice(n,1);
	  printf("Précision : ");
	  scanf("%lf", &prec);
	  printf("\nRésolution par Gauss-Seidel...\n");
	  surrelaxation(A,b,xInit,n,prec,1);
	  //libération mémoire
	  for (i=0;i<n;i++)
	  {
	    free(xInit[i]);
	  }
	  free(xInit);
	  break;
	case 5:
          /*Methode de surrelaxation*/
          printf("Conditions de la methode :\n");
          printf("Vecteur initial x0 :\n");
          xInit=creerRemplirMatrice(n,1);
          printf("Précision : ");
          scanf("%lf", &prec);
          printf("Omega : ");
          scanf("%lf", &ohm);
          printf("\nRésolution par Surrelaxation...\n");
          surrelaxation(A,b,xInit,n,prec,ohm);
	  //libération mémoire
	  for (i=0;i<n;i++)
	  {
	    free(xInit[i]);
	  }
	  free(xInit);
          break;
        case 6:
          generatorMenu();
          break;
        case 7:
          break;
      }
      if (choice!=6)
      {
	//Libération mémoire
	for (i=0;i<n;i++)
	{
	  free(A[i]);
	  free(b[i]);
	}
	free(A);
	free(b);
	//Attente retour
        printf("\nAppuyer sur une touche pour retourner au menu principal");
        getchar(); //recupère le \n du dernier scanf
        getchar(); //recupere le caractere tape pour retour au menu
      }
    }
    printf("\n");
  }
  return 0;
}
