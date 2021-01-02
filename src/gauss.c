#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - macierz jest nie kwadratowa
  */
int eliminate (Matrix *mat, Matrix *b) {
 	
	int row = mat -> r;
	int col  = mat -> c;
	if (row != col)
		return 2;
 	for (int k = 0; k < col - 1; k++) {
		int wmax = k;

		for (int i = k + 1; i < col; i++)
			if (mat -> data[k][i] >  mat -> data[k][k])
					wmax = i;
			
        
		if (mat -> data[k][wmax] == 0)
			return 1;
 
		if (wmax != k) {
			double  *rowtmp = mat -> data[k]; // zamieniamy miejscami wiersze z większymi w
			mat -> data[k] = mat -> data[wmax];
			mat -> data[wmax] = rowtmp;
			
			double btmp = b -> data[k][0];
			b -> data[k][0] = b -> data[wmax][0];
			b -> data[wmax][0] = btmp;
		}
	
		for ( int w = k +1 ; w < row; w++) {
			double wsp =  mat ->data[w][k]  /  mat -> data[k][k] ;
	
			for ( int j = k ; j < col; j++) 
				mat -> data[w][j] -= mat -> data[k][j]*wsp;
			
			//printf ("%lf ", mat -> data[w][k]);
	  
			b -> data[w][0] -=  b -> data[k][0] * wsp;
		}
		//printf("\n");
 	
	}

	return 0;
}

