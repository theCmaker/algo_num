#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main() {
	
   // Pour que du aléatoire soit vraiment du aléatoire (dépend de la date courante)
   srand (time(NULL));   
   
	int n=0;
	int i, j, k;
	float A[N][N];
	float B[N], X[n];
	float pivot;
	int choice;
	float p=0.5;
	float aux;
	float sum;
	
	printf("\nEntrez la dimension de la matrice\n");
	scanf("%d", &n);
	printf("\n");
	//n=3;
	
   // Créer la matrice A
   for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
         int rand_value = rand()%100;
         if (rand_value<70)
         {
             A[i][j]=0;         
         }
         else
         {
            float A_value = (float) (rand()%10) ;
            A[i][j]=A_value; 
         }
      }
   }   

	printf ("\n matrice A initiale\n");
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%f ",A[i][j]);
		}
		printf("\n");
	}

   return 0 ;	
}