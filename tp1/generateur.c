#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "gauss.h"
#include "cholesky.h"
#include "jacobi.h"
#include "surrelaxation.h"
#include "generateur.h"

void generatorMenu()
{
  int choice=1; //choix menu generation
  int use, i; //choix reutilisation matrice, indice boucle
  int n; //dimension matrice
  double p; //precision
  double** generatedMat; //matrice generee
  while (choice != 0)
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
    printf("0. Retour au menu principal\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    if (choice!=0)
    {
      printf("Dimension : ");
      scanf("%d", &n);
      switch (choice)
      {
	case 1:
	  generatedMat=creuse70(n);
	  break;
	case 2:
	  generatedMat=bord(n);
	  break;
	case 3:
	  generatedMat=dingDong(n);
	  break;
	case 4:
	  generatedMat=franc(n);
	  break;
	case 5:
	  generatedMat=hilbert(n);
	  break;
	case 6:
	  printf("Parametre p : ");
	  scanf("%lf", &p);
	  generatedMat=kms(n,p);
	  break;
	case 7:
	  generatedMat=lehmer(n);
	  break;
	case 8:
	  generatedMat=lotkin(n);
	  break;
	case 9:
	  generatedMat=moler(n);
	  break;
      }
      printf("Matrice générée :\n");
      afficherMatrice(generatedMat, n, n);
      printf("Utiliser cette matrice pour une résolution ? (1-oui, 0-non) : ");
      scanf("%d",&use);
      if (use==1)
      {
	usewithMenu(generatedMat, n); //menu resolution
      }
      //libération mémoire
      for (i=0;i<n;i++)
      {
	free(generatedMat[i]);
      }
      free(generatedMat);
    }
  }
}

void usewithMenu(double **a, int n)
{
  int choice=1, i; //choix, indice boucle
  double** b; //vecteur b
  double** xInit; //jacobi et sur-relaxation
  double prec; //jacobi et sur-relaxation
  double omega; //sur-relaxation
  int* carac=(int*) malloc(4*sizeof(int)); //tableau caractéristique des resolutions possibles 0-Gauss; 1-Cholesky; 2-Jacobi; 3-Sur-relaxation
// --------------------------------------
//   
//   FONCTION DE
//   
// 	TESTS
//   
//   --------------------------------------
  while (choice != 0)
  {
    printf("\n\nSOUS-MENU : UTILISER LA MATRICE PRECEDEMMENT GENEREE\n\n");
    printf("Choisir un type de résolution :\n");
    printf("1. Gauss\n");
    printf("2. Cholesky\n");
    printf("3. Jacobi\n");
    printf("4. Surrelaxation\n");
    printf("0. Ne rien faire, retourner au menu de génération de matrices.\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    if (choice!=0)
    {
      printf("Vecteur b :\n"); //demande du vecteur b
      b=creerRemplirMatrice(n,1);
      switch (choice)
      {
        case 1: //gauss
          if (carac[0]==1) //possibilité gauss en position 0 du tableau.
          {
            gauss(a,b,n);
          }
          break;
        case 2: //cholesky
          if (carac[1]==1) //possibilité cholesky en position 1 du tableau.
          {
            cholesky(a,b,n);
          }
          break;
        case 3: //jacobi
          if (carac[2]==1) //possibilité jacobi en position 2 du tableau.
          {
            printf("Vecteur initial x0 :\n");
            xInit=creerRemplirMatrice(n,1);
            printf("Précision : ");
            scanf("%lf", &prec);
            printf("\nRésolution par Jacobi...\n");
            jacobi(a,b,xInit,n,prec);
	    //libération mémoire
	    for (i=0;i<n;i++)
	    {
	      free(xInit[i]);
	    }
	    free(xInit);
          }
          break;
        case 4: //sur-relaxation
          if (carac[3==1]) //possibilité sur-relaxation en position 3 du tableau.
          {
            printf("Vecteur initial x0 :\n");
            xInit=creerRemplirMatrice(n,1);
            printf("Précision : ");
            scanf("%lf", &prec);
            printf("Entrer omega : ");
            scanf("%lf", &omega);
            printf("\nRésolution par Surrelaxation...\n");
            surrelaxation(a,b,xInit,n,prec,omega);
	    //libération mémoire
	    for (i=0;i<n;i++)
	    {
	      free(xInit[i]);
	    }
	    free(xInit);
          }
          break;
      }
      //libération mémoire
      for (i=0;i<n;i++)
      {
	free(b[i]);
      }
      free(b);
    }
  }
}

double** creuse70(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      int rand_value = rand()%100;
      if (rand_value<=70)
      {
        a[i][j]=0;
      }
      else
      {
        double a_value = (double) (rand()%10);
        a[i][j]=a_value;
      }
    }
  }
  return a;
}

double** bord(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=i; j<n; j++)
    {
      if(i==j)
      {
        a[i][j]=1;
      }
      else if (i==0)
      {
        a[i][j]= pow(2, (double) (-j));
        a[j][i]= pow(2, (double) (-j));
      }
      else
      {
        a[i][j]=0;
        a[j][i]=0;
      }
    }
  }
  return a;
}

double** dingDong(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      a[i][j]=1/(2*(n-(i+1)-(j+1)+1.5));
    }
  }
  return a;
}

double** franc(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (i>=j+2)
      {
        a[i][j]=0;
      }
      else if (i<j)
      {
        a[i][j]=(double) i+1;
      }
      else
      {
        a[i][j]=(double) j+1;
      }
    }
  }
  return a;
}

double** hilbert(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      a[i][j]=1/(double)(i+j+1);
    }
  }
  return a;
}

double** kms(int n, double p)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      a[i][j]=pow(p, fabs((double) (i-j)));
    }
  }
  return a;
}

double** lehmer(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (i<=j)
      {
        a[i][j]=((double)(i+1))/((double)(j+1));
      }
      else
      {
        a[i][j]=((double)(j+1))/((double)(i+1));
      }
    }
  }
  return a;
}

double** lotkin(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (i==0)
      {
        a[i][j]=1;
      }
      else
      {
        a[i][j]=1/((double) (i+j+1));
      }
    }
  }
  return a;
}

double** moler(int n)
{
  int i, j;
  //initialisation matrice
  double** a= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  //generation matrice
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (i==j)
      {
        a[i][j]=i+1;
      }
      else if (i<j)
      {
        a[i][j]=(double) i-1;
      }
      else
      {
        a[i][j]=(double) j-1;
      }
    }
  }
  return a;
}
