#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polynome.h"

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
	double resultat = 0.;
	double cpt = 0.;
	int i;
	for(i=0;i<n;i++)
	{
		resultat = resultat + pow(tab[l][i],2.);
		cpt = cpt + 1.;
	}
	resultat = resultat/cpt;
	return resultat;
}

double moyenneProduitElements(double** tab, int n)
{
	double resultat = 0.;
	double cpt = 0.;
	int i;
	for(i=0;i<n;i++)
	{
		resultat = resultat + tab[0][i]*tab[1][i];
		cpt = cpt + 1.;
	}
	resultat = resultat/cpt;
	return resultat;
}

reglinD(double** tab, int n)
{
	double a0 = 0.;
	double a1 = 0.;
	double xb, yb, xcb, xyb; // b pour barre et c pour carre
	printf("Nous cherchons le polynome de degré 1 sous la forme a0 + a1*x. ");
	xb = moyenneElements(tab,0,n);
	yb = moyenneElements(tab,1,n);
	xcb = moyenneElementsCarres(tab,0,n);
	xyb = moyenneProduitElements(tab,n);
	
	a1 = (xyb-xb*yb)/(xcb-pow(xb,2.));
	a0 = yb-xb*a1;

	// creation et affichage du polynome
	polynome *P = creerPoly(2,"valeur",a0,a1);
	menuAffichage(P);
	
}

reglinE(double** tab, int n)
{
	double a0 = 0.;
	double a1 = 0.;
	double tmpa0 = 0.;
	double tmpa1 = 0.;
	double xb, yb, xcb, xyb; // b pour barre et c pour carre
	
	double** t = (double**) malloc(2*sizeof(double*)); // contiendra le mapping de tab
	int i;
	for(i=0;i<2;i++)
	{
		t[i] = (double*) malloc (n*sizeof(double));
	}
// 	t prendra le résultat du mapping par la fonction log du tableau tab, libre à toi de gerer comme tu le sens

	xb = moyenneElements(t,0,n);
	yb = moyenneElements(t,1,n);
	xcb = moyenneElementsCarres(t,0,n);
	xyb = moyenneProduitElements(t,n);
	
	tmpa1 = (xyb-xb*yb)/(xcb-pow(xb,2.));
	tmpa0 = yb-xb*a1;
	
	a1 = tmpa1;
	a0 = exp(tmpa0);
	printf("P(x) = %f*exp(%f*x)",a0,a1);
}

reglinP(double ** tab, int n)
{
	double a0 = 0.;
	double a1 = 0.;
	double tmpa0 = 0.;
	double tmpa1 = 0.;
	double xb, yb, xcb, xyb; // b pour barre et c pour carre
	
	double** t = (double**) malloc(2*sizeof(double*)); // contiendra le mapping de tab
	int i;
	for(i=0;i<2;i++)
	{
		t[i] = (double*) malloc (n*sizeof(double));
	}
// 	t prendra le résultat du mapping par la fonction log2 du tableau tab, libre à toi de gerer comme tu le sens

	xb = moyenneElements(t,0,n);
	yb = moyenneElements(t,1,n);
	xcb = moyenneElementsCarres(t,0,n);
	xyb = moyenneProduitElements(t,n);
	
	tmpa1 = (xyb-xb*yb)/(xcb-pow(xb,2.));
	tmpa0 = yb-xb*a1;
	
	a1 = tmpa1;
	a0 = pow(2,tmpa0);
	printf("P(x) = %f*exp(%f*x)",a0,a1);
}