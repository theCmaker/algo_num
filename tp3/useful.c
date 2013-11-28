#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear()
{
  system("clear");
}

void cleanBuffer()
{
  char c=getchar();
  while (c!='\n' && c!=EOF)
  {
    c=getchar();
  }
}

void hitToContinue()
{
  printf("Appuyez sur une touche pour continuer. ");
  cleanBuffer();
}