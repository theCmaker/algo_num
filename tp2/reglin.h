#ifndef REGLIN_H__
#define REGLIN_H__

//fonctions de modification
void mapping(double** from, double** to, int n, char* fn);
double moyenneElements(double** tab,int l, int n);
double moyenneElementsCarres(double** tab,int l, int n);
double moyenneProduitElements(double** tab, int n);

//fonctions de résolution
void reglinD(double** tab, int n);
void reglinE(double** tab, int n);
void reglinP(double ** tab, int n);


#endif
