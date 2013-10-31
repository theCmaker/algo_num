#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main() {
	
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
	
	for (i=0; i<n; i++) {
		B[i]=1;
	}
	
	for (i=0; i<n; i++) {
		X[i]=0;
	}
	
	printf ("\nMenu Gauss");
	printf ("\n1 ----> Bord");
	printf ("\n2 ----> Ding Dong");
	printf ("\n3 ----> Franc");
	printf ("\n4 ----> Hilbert");
	printf ("\n5 ----> kms");
	printf ("\n6 ----> Lehmer");
	printf ("\n7 ----> Lotkin");
	printf ("\n8 ----> Moler");
	printf ("\n0 EXIT");
	printf ("\n");
	scanf ("%d", &choice);
	
		 
	if (choice==1) {
		for (j=0; j<n; j++){
			A[0][j] = pow(2, -j);
			A[j][0] = pow(2, -j);
			A[j][j] = 1;
		}
	}
	if (choice==2) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				A[i][j]=1/(2*(n-(i+1)-(j+1)+1.5));
			}
		}
	}
	if (choice==3) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if (i>j+1) {
					A[i][j]=0;
				}
				else {
					if (i<j) A[i][j]=i+1;
					else	A[i][j]=j+1;
				}
			}
		}
	}
			
	if (choice==4) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				aux=i+j+1;
				A[i][j]=1/aux;
			}
		}
	}
			
	if (choice==5) {
			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) {
					A[i][j]=pow(p, abs(i-j));
				}
			}
		}
			
	if (choice==6) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if (i<=j) {
					aux=j+1;
					A[i][j]=(i+1)/aux;
				}
				else {
					aux=i+1;
					A[i][j]=(j+1)/aux;
				}
			}
		}
	}
			
	if (choice==7) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				aux=i+1+j;
				A[i][j]=1/aux;
				A[0][j]=1;
			}
		}
	}
			
	if (choice==8) {
			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) {
					if (i==j) A[i][j]=i+1;
					else {
						if (i<j) A[i][j]=i-1;
						else A[i][j]=j-1;
					}
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
	
}