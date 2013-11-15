#ifndef REGLIN_H__
#define REGLIN_H__

double moyenneElements(double** tab,int l, int n);
double moyenneElementsCarres(double** tab,int l, int n);
double moyenneProduitElements(double** tab, int n);

void reglinD(double** tab, int n);
void reglinE(double** tab, int n);
void reglinP(double ** tab, int n);


#endif
