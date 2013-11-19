#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"

void mapping(double** from, double** to, int n, char* fn)
{
  int i, j;
  if (strcmp(fn,"exponentielle")==0)
  {
    for (j=0; j<n; j++)
    {
      to[0][j]=from[0][j];
    }
    for (j=0; j<n; j++)
    {
      to[1][j]=log(from[1][j]);
    }
  }
  else if (strcmp(fn,"puissance")==0)
  {
    for (i=0; i<2; i++)
    {
      for (j=0; j<n; j++)
      {
	to[i][j]=log(from[i][j]);
      }
    }
  }
}

double moyenneElements(double** tab,int l, int n)
{
  double resultat = 0.;
  double cpt = 0.;
  int i;
  for(i=0;i<n;i++)
  {
    resultat = resultat + tab[l][i];
    cpt = cpt + 1.;
  }
  resultat = resultat/cpt;
  return resultat;
}

double moyenneElementsCarres(double** tab,int l, int n)
{
  double resultat = 0;
  double cpt = 0;
  int i;
  for(i=0;i<n;i++)
  {
    resultat = resultat + pow(tab[l][i],2);
    cpt = cpt + 1;
  }
  resultat = resultat/cpt;
  return resultat;
}

double moyenneProduitElements(double** tab, int n)
{
  double resultat = 0;
  double cpt = 0;
  int i;
  for(i=0;i<n;i++)
  {
    resultat = resultat + tab[0][i]*tab[1][i];
    cpt = cpt + 1;
  }
  resultat = resultat/cpt;
  return resultat;
}

reglinD(double** tab, int n)
{
  double a0 = 0;
  double a1 = 0;
  double xb, yb, xcb, xyb; // b pour barre et c pour carre
  printf("Nous cherchons le polynome de degré 1 sous la forme a0 + a1*x.\n");
  
  //calculs
  xb = moyenneElements(tab,0,n);
  yb = moyenneElements(tab,1,n);
  xcb = moyenneElementsCarres(tab,0,n);
  xyb = moyenneProduitElements(tab,n);
  
  a1 = (xyb-xb*yb)/(xcb-pow(xb,2));
  a0 = yb-xb*a1;

  // creation et affichage du polynome
  polynome *P = creerPoly(2,"valeur",a0,a1);
  menuAffichage(P);
  
  //statistiques
  ecartPoly(tab,n,P);
  printf("\n");
  
  //libération mémoire
  free(P->poln);
  free(P);
}

reglinE(double** tab, int n) //y=c(e^(dx)) <=> ln(y)=ln(c)+xd => c=e^(a0) & d=a1
{
  int i;
  double c = 0;
  double d = 0;
  double a0 = 0;
  double a1 = 0;
  double xb, yb, xcb, xyb; // b pour barre et c pour carre
  double** t = (double**) malloc(2*sizeof(double*)); // contiendra le mapping de tab
  for(i=0;i<2;i++)
  {
    t[i] = (double*) malloc (n*sizeof(double));
  }
  printf("Nous cherchons une approximation sous la forme c*(e^(d*x)).\n");
  
  //calculs
  mapping(tab, t, n, "exponentielle");
  xb = moyenneElements(t,0,n);
  yb = moyenneElements(t,1,n);
  xcb = moyenneElementsCarres(t,0,n);
  xyb = moyenneProduitElements(t,n);
  
  a1 = (xyb-xb*yb)/(xcb-pow(xb,2.));
  a0 = yb-xb*a1;
  d = a1;
  c = exp(a0);
  
  //affichage
  printf("P(x) = %f*exp(%f*x)",c,d);
  
  //statistiques
  ecartExpo(tab,n,c,d);
  printf("\n");
  
  //libération mémoire
  for (i=0; i<2; i++)
  {
    free(t[i]);
  }
  free(t);
}

reglinP(double ** tab, int n) //y=a(x^b) <=> ln(y)=ln(a)+b*ln(x) => a=e^(a0) & b=a1
{
  int i;
  double a = 0.;
  double b = 0.;
  double a0 = 0.;
  double a1 = 0.;
  double xb, yb, xcb, xyb; // b pour barre et c pour carre
  double** t = (double**) malloc(2*sizeof(double*)); // contiendra le mapping de tab
  for(i=0;i<2;i++)
  {
    t[i] = (double*) malloc (n*sizeof(double));
  }
  printf("Nous cherchons une approximation sous la forme a*(x^(b)).\n");
  
  //calculs
  mapping(tab, t, n, "puissance");
  xb = moyenneElements(t,0,n);
  yb = moyenneElements(t,1,n);
  xcb = moyenneElementsCarres(t,0,n);
  xyb = moyenneProduitElements(t,n);
  
  a1 = (xyb-xb*yb)/(xcb-pow(xb,2));
  a0 = yb-xb*a1;
  b = a1;
  a = exp(a0);
  
  //affichage
  printf("P(x) = %f*x^(%f)",a,b);
  //statistiques
  ecartPui(tab,n,a,b);
  printf("\n");
  
  //libération mémoire
  for (i=0; i<2; i++)
  {
    free(t[i]);
  }
  free(t);
}
