#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "generateur.h"

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
