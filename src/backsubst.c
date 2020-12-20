#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int col = mat -> c;
	int row = mat -> r;
				
	for (int w = row - 1; w >= 0; w--) {
		int sum = 0;
		
		for (int k = w + 1; k < col; k++)
			sum += x -> data[k][0] * mat -> data[w][k]; //dla k = w + 1 nic się nie dzieje, następnym elementom przepisuje się suma iloczynów elementów x[3], x[2], ... oraz współczynniku wiersza w (gdzie teraz jesteśmy)  
		
		x -> data[w][0] = (b -> data[w][0] - sum) / mat -> data[w][w]; // mat -> dane[w][w] bo macierz jest kwadratowa
	}

	return 0;
}


