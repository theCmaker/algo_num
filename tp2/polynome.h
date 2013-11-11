#ifndef POLYNOME__H
#define POLYNOME__H

typedef struct polynome
{
  int d; //degree
  double* poln; //coefficients
} polynome;

//fonctions auxiliaires

polynome* creerPoly(int c,char* mode, ...);
// les valeurs seront de type double et c correspond au nombre de coefficient. 
//Le mode peut être "tableau" ou "valeur". 
//Si le mode tableau est utilisé, le paramètre optionnel est uniquement le tableau contenant les  c coefficients

void afficherPoly(polynome* P, char* mode, ...); 
// N'affiche pas les coefficients nuls, gere les signes des coefficients à l'affichage.
// Le mode peut-être "console" ou "latex". Le mode console affiche dans la console alors que le latex écrit dans un fichier sous le format maths de latex.
// Si le mode latex est utilisé, le paramètre optionnel est le pointeur FILE *.

polynome* redimensionnerPoly(polynome* P1);
// Enleve les 0 inutile dans le polynome. Attention, l'adresse de résultat ne sera pas la même que celle de P1.


// opération sur les polynomes qui gèrent des degrés différents

polynome* addPoly(polynome* P1, polynome* P2); // addition de 2 polynomes entre eux
polynome* mulSPoly(double s, polynome* P1); // multiplication d'un polynome par un scalaire.
polynome* mulPoly(polynome * P1, polynome* P2); // multiplication de 2 polynomes entre eux


#endif