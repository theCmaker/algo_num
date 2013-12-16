#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "generateur.h"

// void generatorMenu()
// {
//   int choice=1; //choix menu generation
//   int use, i; //choix reutilisation matrice, indice boucle
//   int n; //dimension matrice
//   double p; //precision
//   double** generatedMat; //matrice generee
//   while (choice != 0)
//   {
//     printf("\n\nMENU : GENERATION DE MATRICES\n\n");
//     printf("Choisir un type de matrice à générer :\n");
//     printf("1. Creuse à 70%%\n");
//     printf("2. A bord\n");
//     printf("3. Ding-Dong\n");
//     printf("4. Franc\n");
//     printf("5. Hilbert\n");
//     printf("6. KMS\n");
//     printf("7. Lehmer\n");
//     printf("8. Lotkin\n");
//     printf("9. Moler\n");
//     printf("0. Retour au menu principal\n");
//     printf("Votre choix : ");
//     scanf("%d", &choice);
//     if (choice!=0)
//     {
//       printf("Dimension : ");
//       scanf("%d", &n);
//       switch (choice)
//       {
// 	case 1:
// 	  generatedMat=creuse70(n);
// 	  break;
// 	case 2:
// 	  generatedMat=bord(n);
// 	  break;
// 	case 3:
// 	  generatedMat=dingDong(n);
// 	  break;
// 	case 4:
// 	  generatedMat=franc(n);
// 	  break;
// 	case 5:
// 	  generatedMat=hilbert(n);
// 	  break;
// 	case 6:
// 	  printf("Parametre p : ");
// 	  scanf("%lf", &p);
// 	  generatedMat=kms(n,p);
// 	  break;
// 	case 7:
// 	  generatedMat=lehmer(n);
// 	  break;
// 	case 8:
// 	  generatedMat=lotkin(n);
// 	  break;
// 	case 9:
// 	  generatedMat=moler(n);
// 	  break;
//       }
//       printf("Matrice générée :\n");
//       afficherMatrice(generatedMat, n, n);
//       printf("Utiliser cette matrice pour une résolution ? (1-oui, 0-non) : ");
//       scanf("%d",&use);
//       if (use==1)
//       {
// 	usewithMenu(generatedMat, n); //menu resolution
//       }
//       //libération mémoire
//       for (i=0;i<n;i++)
//       {
// 	free(generatedMat[i]);
//       }
//       free(generatedMat);
//     }
//   }
// }
// 
// void usewithMenu(double **a, int n)
// {
//   int choice=1, i, j; //choix, indice boucle
//   double** b; //vecteur b
//   double** xInit; //jacobi et sur-relaxation
//   double prec; //jacobi et sur-relaxation
//   double omega; //sur-relaxation
//   double** mat=(double**) malloc(n*sizeof(double*)); //matrice copie de a
//   for (i=0; i<n; i++)
//   {
//     mat[i]=(double*) malloc(n*sizeof(double));
//   }
//   while (choice != 0)
//   {
//     printf("\n\nSOUS-MENU : UTILISER LA MATRICE PRECEDEMMENT GENEREE\n\n");
//     printf("Choisir un type de résolution :\n");
//     printf("1. Gauss\n");
//     printf("2. Cholesky\n");
//     printf("3. Jacobi\n");
//     printf("4. Gauss-Seidel\n");
//     printf("5. Surrelaxation\n");
//     printf("0. Ne rien faire, retourner au menu de génération de matrices.\n");
//     printf("Votre choix : ");
//     scanf("%d", &choice);
//     if (choice!=0)
//     {
//       for (i=0; i<n; i++)
//       {
//         for (j=0; j<n; j++)
//         {
//           mat[i][j]=a[i][j]; //copie matrice
//         }
//       }
//       printf("Vecteur b :\n"); //demande du vecteur b
//       b=creerRemplirMatrice(n,1);
//       switch (choice)
//       {
//         case 1: //gauss
//             gauss(mat,b,n);
//           break;
//         case 2: //cholesky
//             cholesky(mat,b,n);
//           break;
//         case 3: //jacobi
//             printf("Vecteur initial x0 :\n");
//             xInit=creerRemplirMatrice(n,1);
//             printf("Précision : ");
//             scanf("%lf", &prec);
//             printf("\nRésolution par Jacobi...\n");
//             jacobi(mat,b,xInit,n,prec);
//             //libération mémoire
//             for (i=0;i<n;i++)
//             {
//               free(xInit[i]);
//             }
//             free(xInit);
//           break;
//         case 4: //gauss-seidel
//             printf("Vecteur initial x0 :\n");
//             xInit=creerRemplirMatrice(n,1);
//             printf("Précision : ");
//             scanf("%lf", &prec);
//             printf("\nRésolution par Gauss-Seidel...\n");
//             gaussseidel(mat,b,xInit,n,prec);
//             //libération mémoire
//             for (i=0;i<n;i++)
//             {
//               free(xInit[i]);
//             }
//             free(xInit);
//           break;
//         case 5: //sur-relaxation
//             printf("Vecteur initial x0 :\n");
//             xInit=creerRemplirMatrice(n,1);
//             printf("Précision : ");
//             scanf("%lf", &prec);
//             printf("Entrer omega : ");
//             scanf("%lf", &omega);
//             printf("\nRésolution par Surrelaxation...\n");
//             surrelaxation(mat,b,xInit,n,prec,omega);
//             //libération mémoire
//             for (i=0;i<n;i++)
//             {
//               free(xInit[i]);
//             }
//             free(xInit);
//           break;
//       }
//       //libération mémoire
//       for (i=0;i<n;i++)
//       {
//         free(b[i]);
//       }
//       free(b);
//     }
//   }
//   //libération mémoire copie matrice -> choice=0
//   for (i=0; i<n; i++)
//   {
//     free(mat[i]);
//   }
//   free(mat);
// }

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
