#include "algo1.h"

void algo1(int* Tab[], int N){
	int i;
	int temp;
	for(i=N/2;i>0;i--){
			algo2(Tab,N,i);
	}

	for(i=N;i>1;i--){
		temp = *Tab[1];
		*Tab[1] = *Tab[i];
		*Tab[i]= temp;
		algo2(Tab, i-1, 1);
	}
}


void algo2(int* Tab[], int N, int i){
	int k = i;
	int j;
	int temp;
	do{
		j=k;
		if ((2*j <= N)&&(*Tab[2*j]> *Tab[k]))
			k = 2*j;
		if((2*j<N)&&(*Tab[2*j+1]>*Tab[k]))
			k= 2*j+1;

		temp = *Tab[j];
		*Tab[j] = *Tab[k];
		*Tab[k]= temp;


	}while(j!=k);


}
