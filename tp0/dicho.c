#include <stdio.h>
#include <math.h>

float fexp (float x)
{
  return expf(x)-powf(x,3);
}

float fpoly (float x)
{
  return x*x-5;
}

float fdicho( float (*f)(float),float x1,float x2, float e)
{
  float y1=f(x1);
  float ym=y1;
  float xm;
  int cpt=0;
  float n=(logf((x2-x1)/e)/logf(2))+1;
  while (fabsf(ym) > e)
  {
    cpt++;
    xm=(x1+x2)/2;
    ym=f(xm);
    if (y1*ym < 0)
    {
      x2=xm;
    }
    else
    {
      x1=xm;
      y1=ym;
    }
//     printf("xm=%f ym=%f\n", xm, ym);
  }
  printf("\nItérations : %d\tThéorie : %f\n", cpt, n);
  return xm;
}