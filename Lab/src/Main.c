#include "ressources.h"
#include "algo1.h"
#include <time.h>
#include <stdio.h>


void partie1();


const int M[] 		= {10,20,30,40,50,60,70,80,90,100};
const int R[] 		= {10^2,10^4,10^6,10^8};
const float D[] 	= {0,0.25,0.50,0.75,1};


int main(){


	partie1();

}

void partie1(){

	int i,j,k,x;
	int nb, rang, desordre;
	double tBefore;
	double* tDiff[9];

	int* Tab;
	printf("test1");

	srand(time(0));	//initialisation du generateur de donnees

	for(i=0;i<=9;i++){
		nb = M[i]*1000;

		for(j=0;j<=3;j++){

			rang = R[j];

			for(k=0;k<=4;k++){

				desordre = D[k];

				for(x=0;x<=9;x++){
					Tab = generer_donnees(nb, rang, desordre);
					tBefore = clock();
					algo1(&Tab,nb);
					*tDiff[x] = clock() - tBefore;
				}
				sauvegarder(nb, rang, desordre, tDiff, 10, "donnees_Partie1.txt");
			}
		}

	}

}
