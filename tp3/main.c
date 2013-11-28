#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrices.h"
#include "polynome.h"
#include "leverrier.h"

int main (int argc, char ** argv)
{
  double** A;
  int n;
  printf("Matrice A :\n");
  printf("Dimension : ");
  scanf("%d", &n);
  A=creerRemplirMatrice(n,n);
  leverrier(A,n);
  return 0;
}
