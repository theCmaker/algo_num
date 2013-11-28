#ifndef MATRICES__H
#define MATRICES__H

void remplirMatrice(double** matrice, int n, int m);
void afficherMatrice(double** matrice, int n, int m);
double ** creerRemplirMatrice(int n, int m);
double ** solveTriangulaireSup (double** mat, double** vec, int n);
double ** solveTriangulaireInf (double** mat, double** vec, int n);
double ** transpose(double** mat, int n);
double ** produitMatriciel(double** a, double** b, int n, int m, int o); // Produit AB
double ** difference (double** a, double** b, int n, int m);
double norme (double** x, int n);
double det (double** mat, int n);

#endif
