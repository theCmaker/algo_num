#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "newton.h" 

void newton (double ** t, int n)
{
  int i, k;
  //calcul des differences divisees
  for (k=2; k<n+1; k++)
  {
    for (i=k-1; i<n; i++)
    {
      t[i][k]=(t[i][k-1]-t[k-2][k-1])/(t[i][0]-t[k-2][0]);
    }
  }
  //affichage
  for (i=0; i<n; i++)
  {
    if(t[i][i+1] != 0)
    {
    if (i>0)
    {
      printf(" + ");
    }
    for (k=0; k<i; k++)
    {
      if(t[k][0] >0) {printf("(x-%f)",t[k][0])};
      if(t[k][0] <0) {printf("(x+%f)",-t[k][0])};
    }
    printf("%f", t[i][i+1]);
    }
  }
  print("\n");
}