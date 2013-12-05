#ifndef MATRICES__H
#define MATRICES__H

void remplirMatrice(double** matrice, int n, int m);
void afficherMatrice(double** matrice, int n, int m);
double ** creerRemplirMatrice(int n, int m);
double ** solveTriangulaireSup (double** mat, double** vec, int n);
double ** solveTriangulaireInf (double** mat, double** vec, int n);
double ** transpose(double** mat, int n);
double ** produitMatriciel(double** a, double** b, int n, int m, int o); // Produit AB
double** produitSMatriciel(double** a, int n, int m, double s); //Produit par un scalaire
double ** difference (double** a, double** b, int n, int m);
double ** puissanceMatrice(double** mat, int n, int e); // calcule la matrice à la puissance e avec e différent de 0  et 1 (inutile pour nous)
double norme (double** x, int n);
double det (double** mat, int n);
double trace(double** mat, int n);

#endif
