#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dicho.h"

int main (int argc, char ** argv)
{
  printf("Question 1.a");
  
  printf("Fexp :\n");
  
  float res=fdicho(&fexp,1,2,0.00001);
  printf("Valeur : %f\tImage : %f \n", res, fexp(res)); //1.a.1
  res=fdicho(&fexp,4,5,0.00001);
  printf("Valeur : %f\tImage : %f \n\n", res, fexp(res)); //1.a.2
  
  
  
  printf("Question 1.b");
  
  printf("Fpoly :\n");
  
  res=fdicho(&fpoly,2,3,0.01);
  printf("Valeur : %f\tImage : %f \n", res, fpoly(res)); //1.b.1
  res=fdicho(&fpoly,2,3,0.001);
  printf("Valeur : %f\tImage : %f \n", res, fpoly(res)); //1.b.2
  res=fdicho(&fpoly,2,3,0.0001);
  printf("Valeur : %f\tImage : %f \n", res, fpoly(res)); //1.b.3
  res=fdicho(&fpoly,2,3,0.00001);
  printf("Valeur : %f\tImage : %f \n\n\n", res, fpoly(res)); //1.b.4  
  
  
  
  printf("Question 2 -> Tests");
  
  printf("Fpoly :\n");
  
  res=fdicho(&fpoly,0,10,0.01);
  printf("Fpoly, Grand intervalle, faible précision : Valeur : %f\tImage : %f \n",res, fpoly(res));
  res=fdicho(&fpoly,0,10,0.0000001);
  printf("Fpoly, Grand intervalle, grande précision : Valeur : %f\tImage : %f \n",res, fpoly(res));
  res=fdicho(&fpoly,2.2,2.3,0.01);
  printf("Fpoly, Petit intervalle, faible précision : Valeur : %f\tImage : %f \n",res, fpoly(res));
  res=fdicho(&fpoly,2.2,2.3,0.0000001);
  printf("Fpoly, Petit intervalle, grande précision : Valeur : %f\tImage : %f \n\n",res, fpoly(res));
  
  
  printf("Fexp :\n");
  
  res=fdicho(&fexp,0,4,0.01);
  printf("Fexp, Grand intervalle, faible précision : Valeur : %f\tImage : %f \n",res, fexp(res));
  res=fdicho(&fexp,0,4,0.0000001);
  printf("Fexp, Grand intervalle, grande précision : Valeur : %f\tImage : %f \n",res, fexp(res));
  res=fdicho(&fexp,1.8,1.9,0.01);
  printf("Fexp, Petit intervalle, faible précision : Valeur : %f\tImage : %f \n",res, fexp(res));
  res=fdicho(&fexp,1.8,1.9,0.0000001);
  printf("Fexp, Petit intervalle, grande précision : Valeur : %f\tImage : %f \n",res, fexp(res));
  
  
  
  return 0;
}
