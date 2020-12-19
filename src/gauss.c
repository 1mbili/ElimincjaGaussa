#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
 	int row = mat -> r;
	int col  = mat -> c;
	for (int k = 0; k < col -1; k++) {
	    for ( int w = k +1 ; w < row; w++) {
		double wsp =  mat ->data[w][k]  /  mat -> data[k][k] ;
		for ( int j = k ; j < col; j++) {
			mat -> data[w][j] -= mat -> data[k][j]*wsp;
				
	    }
		b -> data[w][0] -=  b -> data[k][0] * wsp;
		
		}
	}

   /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */

		return 0;
}

