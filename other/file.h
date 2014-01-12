#ifndef FILE_H__
#define FILE_H__

typedef struct element
{
  double val;
  struct element* next;
} element;

typedef struct file
{
  int nb;
  element* first;
} file;

file* creerFile ();
int isEmpty (file* f);
void enfiler (file* f, double x);
int defiler (file* f);
int refiler (file* f);
int taille (file* f);
void liberer (file* f);

#endif
