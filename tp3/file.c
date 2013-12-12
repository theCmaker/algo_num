#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "file.h" 

file* creerFile ()
{
  file* f=(file*) malloc(sizeof(file));
  f->nb=0;
  f->first=NULL;
  return f;
}

int isEmpty (file* f)
{
  int bool=0;
  if (f->nb > 0)
  {
    bool=1;
  }
  return bool;
}

void enfiler (file* f, double x)
{
  element* e=(element*) malloc (sizeof(element));
  element* current;
  e->val=x;
  e->next=NULL;
  current=f->first;
  if (current != NULL)
  {
    while (current->next != NULL)
    {
      current=current->next;
    }
    current->next=e;
  }
  else
  {
    f->first=e;
  }
  f->nb++;
}

int defiler (file* f)
{
  double tmp=-1;
  element* e;
  if (isEmpty(f)!=0)
  {
    tmp=f->first->val;
    e=f->first;
    f->first=f->first->next;
    f->nb--;
    free(e);
  }
  return tmp;
}

int refiler (file* f)
{
  int tmp=-1;
  if (isEmpty(f)!=0)
  {
    tmp=f->first->val;
  }
  return tmp;
}

int taille (file* f)
{
  return f->nb;
}

void liberer (file* f)
{
  element* e;
  element* s;
  s=f->first;
  while(s!=NULL)
  {
    e=s->next;
    free(s);
    s=e;
  }
  free(f);
}


