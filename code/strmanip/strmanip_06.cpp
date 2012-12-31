//////////////////////////////////////////////////////////////////////////////////////
// bear in mind i's and j's rotating direction 
// e.g. the iterator of array[(i, j), ..., (n - 2i)(j)] is from left to right 
//      so array[(n - j, i), ..., (i + 1, i)] is from bottom to top, where i denotes
//      the matrix level and j denotes the iterator position. 
//////////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
using namespace std;

void rotate(int **matrix, int n) {
	int lt;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = i; j < n - 2 * i - 1; ++j) {
			lt 				= matrix[i][j];
			matrix[i][j]			= matrix[j][n - 1 - i];
			matrix[j][n - 1 - i]		= matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] 	= matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] 		= lt;
		}
	}	
}

void print_matrix(int **matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cout << matrix[i][j] << "\t"; 

		cout << endl;
	}

	cout << endl;
}

int main() {
	const int n = 5;
	int *matrix[n];	
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];

		for (int j = 0; j < n; ++j) 
			matrix[i][j] = rand() % (n * n);
	}
		
	print_matrix(matrix, n);
	rotate(matrix, n);
	print_matrix(matrix, n);

	return 0;
}
