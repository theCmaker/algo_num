#ifndef PILE__H
#define PILE__H


// Utilisation pour le TP : uniquement si on code la méthode de déflation.
typedef struct ValVec
{
  double val;
  double** vec; // Utilisation pour le tp : vecteur colonne.
  int l;
  int c;
  struct ValVec* next;
} ValVec;

typedef struct pile
{
  int nb;
  ValVec* first;
} pile;

pile* creerPile (); // Creation de pile, malloc effectué.
void empiler (pile* p, ValVec* x); // Empile l'élément passé en paramètre déjà créé !
void liberer (pile* p); // Libération de la pile et ses valeurs.
void afficher(pile* p); // Affiche le contenu de la pile.
#endif

