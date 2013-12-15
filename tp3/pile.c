#include <math.h>
#include <sdlib.h>
#include <sdtio.h>
#include "pile.h"
#include "matrices.h"

pile* creerPile () // Creation de pile, malloc effectué
{
  file* p=(pile*) malloc(sizeof(pile));
  p->nb=0;
  p->first=NULL;
  return p;
}

void empiler (pile* p, ValVec* x) // Empile l'élément passé en paramètre déjà créé !
{
  
  if(p->first == NULL)
  {
    p->first = x;
    x->next = NULL;
  }
  else
  {
    x->next = p->first;
    p->first = x;
  }
  f->nb ++;
}

void liberer (pile* p) // Libération de la pile et ses valeurs
{
  int i,j;
  element* e;
  element* s;
  s=p->first;
  while(s!=NULL)
  {
    e=s->next;
    for(i=0;i< s->l; i++)
    {
      free(s->tab[i]);
    }
    free(s->tab);
    free(s);
    s=e;
  }
  free(p);
}

void afficher(pile* p) // Affichage de la pile
{
  ValVec* e;
  if(p->first == NULL)
  {
    printf("La pile est vide\n");
  }
  else
  {
    e = p->first;
    while(e != NULL)
    {
      printf("Valeur propre: %lf\n",e->val);
      printf("Vecteur propre: \n");
      afficherMatrice(e->vec,e->l,e->c);
      e = e->next;
    }
  }
}