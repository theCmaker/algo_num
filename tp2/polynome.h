#ifndef POLYNOME__H
#define POLYNOME__H

typedef struct polynome
{
  int d; //degree
  double* poln; //coefficients
} polynome;

//fonctions sortie LaTeX
void convertTabtoLatex(double** tab, int n, int m); //sortie du tableau en LaTeX
void menuAffichage(polynome* P); //choix entre LaTeX et terminal
void afficherPoly(polynome* P, char* mode, ...); //mode:"console"||"latex"; console->terminal; latex->fichier (FILE* opt) format maths LaTeX.

//fonctions de manipulation des polynomes
polynome* creerPoly(int c,char* mode, ...); //c: nbre coefs;mode: "tableau"||"valeur";mode tableau -> paramètre optionnel : tableau des coefs.
void redimensionnerPoly(polynome* P1); // Enleve les 0 inutile dans le polynome.
polynome* addPoly(polynome* P1, polynome* P2); // addition de 2 polynomes entre eux.
polynome* mulSPoly(double s, polynome* P1); // multiplication d'un polynome par un scalaire.
polynome* mulPoly(polynome * P1, polynome* P2); // multiplication de 2 polynomes entre eux.

// fonctions de calcul d'images de fonctions
double imagePoly(polynome* P, double x); // La fonction calcule l'image de x  par un polynome.
double imageExpo(double c, double d, double x); // La fonction calcule l'image de x par une exponentielle de la forme f(x)=c*exp(dx).
double imagePui(double a, double b, double x); // La fonction calcule l'image de x par une fonction puissance de la forme f(x)=a*x^b.

//fonctions de statistiques
void ecartPoly(double** tab, int n, polynome* P); 
void ecartExpo(double** tab, int n, double c, double d);
void ecartPui(double** tab, int n, double a, double b);

#endif