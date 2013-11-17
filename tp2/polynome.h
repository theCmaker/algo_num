#ifndef POLYNOME__H
#define POLYNOME__H

typedef struct polynome
{
  int d; //degree
  double* poln; //coefficients
} polynome;

//fonctions auxiliaires

void convertTabtoLatex(double** tab, int n);

polynome* creerPoly(int c,char* mode, ...);
// les valeurs seront de type double et c correspond au nombre de coefficient. 
//Le mode peut être "tableau" ou "valeur". 
//Si le mode tableau est utilisé, le paramètre optionnel est uniquement le tableau contenant les  c coefficients.

void afficherPoly(polynome* P, char* mode, ...); 
// N'affiche pas les coefficients nuls, gere les signes des coefficients à l'affichage.
// Le mode peut-être "console" ou "latex". Le mode console affiche dans la console alors que le latex écrit dans un fichier sous le format maths de latex.
// Si le mode latex est utilisé, le paramètre optionnel est le pointeur FILE *.

void menuAffichage(polynome* P);

void redimensionnerPoly(polynome* P1);
// Enleve les 0 inutile dans le polynome. Attention, l'adresse de résultat ne sera pas la même que celle de P1.


// opération sur les polynomes qui gèrent des degrés différents

polynome* addPoly(polynome* P1, polynome* P2); // addition de 2 polynomes entre eux.
polynome* mulSPoly(double s, polynome* P1); // multiplication d'un polynome par un scalaire.
polynome* mulPoly(polynome * P1, polynome* P2); // multiplication de 2 polynomes entre eux.

// images de fonctions
double imagePoly(polynome* P, double x); // La fonction calcule l'image de x  par un polynome.
double imageExpo(double c, double d, double x); // La fonction calcule l'image de x par une exponentielle de la forme f(x)=c*exp(dx).
double imagePui(double a, double b, double x); // La fonction calcule l'image de x par une fonction puissance de la forme f(x)=a*x^b.

//affiche  la moyenne de la valeur absolue de l'écart relatif entre les valeurs mesurées et calculées.
void ecartPoly(double** tab, int n, polynome* P); 
void ecartExpo(double** tab, int n, double c, double d);
void ecartPui(double** tab, int n, double a, double b);

#endif