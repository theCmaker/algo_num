#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "puissancesIt.h" 
#include "matrices.h" 
#include "file.h" 
#include "polynome.h"

void puissancesIt(double** A, int n, double precision)
{
  int i, cpt=0;
  double ecart = 1.;
  double** x1 = (double**) malloc (n*sizeof(double*));
  double** x2;
  double** x3;
  double** xt;
  double** xtx;
  //Initialisation de x1 -> vecteur unité
  for (i=0; i<n; i++)
  {
    x1[i] = (double*) malloc (sizeof(double));
    x1[i][0] = 1.;
  }
  while (ecart > precision)
  {
    cpt++;
    x2 = produitMatriciel(A,x1,n,n,1); //x2 = A x1
    diviserComposantes(x2,n);
    x3 = difference(x2, x1, n, 1); //x3 = x2-x1
    ecart = norme(x3, n); //norme(x2-x1)-> écart
    //libération mémoire
    for (i=0; i<n; i++)
    {
      free(x3[i]);
      free(x1[i]);
    }
    free(x3);
    free(x1);
    x1 = x2; //xi = x(i+1)
  }
  printf("Nombre d'itérations : %d\n", cpt);
  printf("Approximation du vecteur propre :\n");
  for (i=0; i<n; i++)
  {
    printf("x[%d]=%f\n", (i+1), x1[i][0]);
  }
  xt = transpose(x1, n, 1);
  x2 = produitMatriciel(xt, A, 1, n, n); //xt A
  x3 = produitMatriciel(x2, x1, 1, n, 1); //xt A x
  xtx = produitMatriciel(xt, x1, 1, n, 1); //xt x
  printf("Approximation de la valeur propre maximum : %f\n", x3[0][0]/xtx[0][0]);
  //libération mémoire
  for (i=0; i<n; i++)
  {
    free(x1[i]);
  }
  free(xt[0]); free(x2[0]); free(x3[0]); free(xtx[0]);
  free(xt); free(x2); free(x3); free(xtx); free(x1);
}

void fonctionRapport(double**A,int n, double precision)
{
   int i, j;
  double tempAo;
  double** tmpA;
  double* coeffsA=(double*) malloc ((n+1)*sizeof(double)); //tableau coeffsA
  double** Ak=(double**) malloc (n*sizeof(double*));
  double** B=(double**) malloc (n*sizeof(double*));
  double** I=(double**) malloc (n*sizeof(double*));
  FILE* fichier=fopen("resultat","a+");
  double tempo;
  double* coeffs=(double*) malloc ((n+1)*sizeof(double)); //tableau coeffs
  double* traces=(double*) malloc(n*sizeof(double)); //tableau traces
  double** tmp;
  polynome* p;
  polynome* pA;
  int cpt=0;
  double ecart = 1.;
  double** x1 = (double**) malloc (n*sizeof(double*));
  double** x2;
  double** x3;
  double** xt;
  double** xtx;
  
  //On remplit notre tableau contenant les traces 
  for (i=1; i<=n; i++)
  {
    tmp=puissanceMatrice(A, n, i);
    traces[i-1]=trace(tmp, n);
    for (j=0; j<n; j++)
    {
      free(tmp[j]);
    }
    free(tmp);
  }
  
  //On remplit le tableau des coefficients
  for(i=0; i<=n; i++)
  {
    coeffs[i]=0;
  }
  coeffs[n]=pow(-1.0,n);
  for(i=1; i<=n; i++)
  {
    for(j=0;j<i;j++)
    {
      coeffs[n-i] = coeffs[n-i] - coeffs[n-j]*traces[i-j-1];
    }
    coeffs[n-i] = coeffs[n-i]/i;
  }
  p=creerPoly(n+1, "tableau", coeffs);
  fprintf(fichier,"Polynome Leverrier: ");
  afficherPoly(p,"latex",fichier);
  
  
  for (i=0; i<n; i++)
  {
    Ak[i]=(double*) malloc (n*sizeof(double));
    I[i]=(double*) malloc (n*sizeof(double));
    B[i]=(double*) malloc (n*sizeof(double));
  }
  
  //Création matrice identité, initialisation de B et copAie de A
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      Ak[i][j]=A[i][j];
      if (i==j) 
      {
        I[i][j]=1; 
        B[i][j]=1;
      }
      else 
      {
        I[i][j]=0; 
        B[i][j]=0;
      }
    }
  }
  
  //On rempAlit le tableau des coefficients
  for(i=0; i<=n; i++)
  {
    coeffsA[i]=0;
  }
  
  coeffsA[0]=pow(-1,n);
  
  
  for(i=1; i<=n; i++)
  {
    Ak=produitMatriciel(B,A,n,n,n);
    coeffsA[i]=trace(Ak,n)/i;
    tmpA=produitSMatriciel(I,n,n,coeffsA[i]);
    for(j=0;j<n;j++)
    {
      free(B[j]);
    }
    free(B);
    B=difference(Ak,tmpA,n,n);
    for(j=0;j<n;j++)
    {
      free(Ak[j]);
      free(tmpA[j]);
    }
    free(tmpA); free(Ak);
  }
  
  //On inverse le tableau des coefficients
  for(i=0;i<=((n+1)/2)-1;i++)
  {
    if ((n%2) == 0)
    {
      coeffsA[i]=-coeffsA[i];
    }
    tempAo = coeffsA[i];
    coeffsA[i] = coeffsA[n-i];
    coeffsA[n-i] = tempAo;
  }
  
  pA=creerPoly(n+1, "tableau", coeffsA);
  fprintf(fichier,"Polynome Leverrier amélioré : ");
  afficherPoly(pA,"latex",fichier);
  
  //liberation memoire
  for (i=0; i<n; i++)
  {
    free(B[i]);
  }
  free(B);
  
  //Initialisation de x1 -> vecteur unité
  for (i=0; i<n; i++)
  {
    x1[i] = (double*) malloc (sizeof(double));
    x1[i][0] = 1.;
  }
  while (ecart > precision)
  {
    cpt++;
    x2 = produitMatriciel(A,x1,n,n,1); //x2 = A x1
    diviserComposantes(x2,n);
    x3 = difference(x2, x1, n, 1); //x3 = x2-x1
    ecart = norme(x3, n); //norme(x2-x1)-> écart
    //libération mémoire
    for (i=0; i<n; i++)
    {
      free(x3[i]);
      free(x1[i]);
    }
    free(x3);
    free(x1);
    x1 = x2; //xi = x(i+1)
  }
  printf("Nombre d'itérations : %d\n", cpt);
  fprintf(fichier,"Nombre d'itérations: %d\n",cpt);
  
  printf("Approximation du vecteur propre :\n");
  fprintf(fichier,"Vecteur propre : \n");
  fprintf(fichier,"\\begin{equation*}\n\\begin{pmatrix}\n");
  
  //remplissage des cases
  for(i=0;i<n;i++)
  {
    fprintf(fichier,"%f \\\\ \n",x1[i][0]);
  }
  fprintf(fichier,"\\end{pmatrix}\n\\label{}\n\\end{equation*}\n");
  
  for (i=0; i<n; i++)
  {
    printf("x[%d]=%f\n", (i+1), x1[i][0]);
  }
  xt = transpose(x1, n, 1);
  x2 = produitMatriciel(xt, A, 1, n, n); //xt A
  x3 = produitMatriciel(x2, x1, 1, n, 1); //xt A x
  xtx = produitMatriciel(xt, x1, 1, n, 1); //xt x
  printf("Approximation de la valeur propre maximum : %f\n", x3[0][0]/xtx[0][0]);
  fprintf(fichier,"Valeur propre: $ %f $",x3[0][0]/xtx[0][0]);
  fprintf(fichier,"Image par Leverrier: %f\n",imagePoly(p,x3[0][0]/xtx[0][0]));
  fprintf(fichier,"Image par Leverrier amélioré: %f\n\n\n\n",imagePoly(pA,x3[0][0]/xtx[0][0]));
  fclose(fichier);
  //libération mémoire
  for (i=0; i<n; i++)
  {
    free(x1[i]);
  }
  free(xt[0]); free(x2[0]); free(x3[0]); free(xtx[0]);
  free(xt); free(x2); free(x3); free(xtx); free(x1);
  //liberation memoire
  //libération du tableau de trace
  free(traces);
  //libération du polynome
  free(p->poln);
  free(p);
  //libération du pAolynome
  free(pA->poln);
  free(pA);
}
