#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void remplirMatrice(double** matrice, int n, int m)
{
  int i,j;
  double v; //valeur
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      printf("Entrez l'element [%d] [%d]: ", i+1,j+1);
      scanf("%lf",&v);
      matrice[i][j] = v;
    }
  }
}

void afficherMatrice(double** matrice, int n, int m)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      printf("%+.5lf\t",matrice[i][j]);
    }
    printf("\n");
  }
}

double ** creerRemplirMatrice(int n, int m)
{
  int i;
  int rep;
  
  //création matrice
  double **matrice = (double**) malloc (n*sizeof(double*));
  for(i=0;i<n;i++)
  {
    matrice[i] = (double*) malloc (m*sizeof(double));
  }
  remplirMatrice(matrice,n,m);
  
  //affichage
  printf("Voulez-vous afficher votre matrice ? 0-non  1-oui : ");
  scanf("%d",&rep);
  if (rep)
  {
    afficherMatrice(matrice,n,m);
  }
  
  return matrice;
}

double ** solveTriangulaireSup (double** mat, double** vec, int n)
{
  int i, j; 
  
  //vecteur résultat
  double **x = (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    x[i]=(double*) malloc(sizeof(double));
  }
  
  //calculs
  for (i=n-1; i>=0; i--)
  {
    double somme=0;
    for (j=i+1; j<n; j++)
    {
      somme=somme+(mat[i][j]*x[j][0]);
    }
    x[i][0]=(1.0/mat[i][i])*(vec[i][0]-somme);
  }
  return x;
}

double ** solveTriangulaireInf (double** mat, double** vec, int n)
{
  int i, j; 
  
  //vecteur résultat
  double **x = (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    x[i]=(double*) malloc(sizeof(double));
  }
  
  //calculs
  for (i=0; i<n; i++)
  {
    double somme=0;
    for (j=0; j<i; j++)
    {
      somme=somme+(mat[i][j]*x[j][0]);
    }
    x[i][0]=(1.0/mat[i][i])*(vec[i][0]-somme);
  }
  return x;
}

double ** transpose(double** mat, int n)
{
  int i, j;
  double **tr = (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    tr[i]=(double*) malloc(n*sizeof(double));
  }
  
  //transposition
  for (i=0; i<n ; i++)
  {
    for (j=0 ; j<n ; j++)
    {
      tr[i][j]=mat[j][i];
    }
  }
  return tr;
}

double ** produitMatriciel(double** a, double** b, int n, int m, int o)
{
  int i, j, k; //indices de boucles
  
  //matrice resultat
  double** c=(double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    c[i]=(double*) malloc(o*sizeof(double));
  }
  
  //Calcul de la matrice résultat c=ab
  for (i=0; i<n; i++)
  {
    for (j=0; j<o; j++)
    {
      c[i][j]=0;
      for (k=0; k<n; k++)
      {
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  
  return c;
}

double ** difference (double** a, double** b, int n, int m)
{
  int i, j;
  
  //matrice resultat
  double** c= (double**) malloc(n*sizeof(double*));
  for (i=0; i<n; i++)
  {
    c[i]= (double*) malloc(m*sizeof(double));
  }
  
  //calcul de c=a-b
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
    {
      c[i][j]=(a[i][j])-(b[i][j]);
    }
  }
  return c;
}

double norme (double** x, int n)
{
  double somme=0; //somme des carrés
  int i;
  for (i=0; i<n; i++)
  {
    somme=somme+(x[i][0]*x[i][0]);
  }
  return sqrt(somme);
}

double det (double** mat, int n)
{
  int i, j, k;
  double pivot;
  double determinant=1;
  
  //matrice pour calcul
  double** a= (double**) malloc(n*sizeof(double*)); 
  for (i=0; i<n; i++)
  {
    a[i]=(double*) malloc(n*sizeof(double));
  }
  
  //copie de matrice
  for (k=0; k<n; k++)
  {
    for (i=0; i<n; i++)
    {
      a[k][i]=mat[k][i];
    }
  }
  
  //echelonnage
  for (k=0; k<n-1; k++)
  {
    for (i=k+1; i<n; i++)
    {
      pivot = a[i][k]/a[k][k];
      for (j=k+1; j<n; j++)
      {
	a[i][j]=a[i][j]-pivot*a[k][j];
      }
    }
  }
  
  //calcul determinant
  for (i=0; i<n; i++)
  {
    determinant=determinant*a[i][i];
  }
  
  //libération mémoire
  for (i=0;i<n;i++)
  {
    free(a[i]);
  }
  free(a);
  
  return determinant;
}