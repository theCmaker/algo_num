#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear()
{
  system("clear");
}

void cleanBuffer()
{
  char c='0';
  while (c!='\n' && c!=EOF)
  {
    c=getchar();
  }
}

void hitToContinue()
{
  cleanBuffer();
  printf("Appuyez sur une touche pour continuer. ");
  getchar();
  cleanBuffer();
}