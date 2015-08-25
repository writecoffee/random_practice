/////////////////////////////////////////////////////////////////////
// detect first and put flags into two arrays
// manipulate the origin matrix while referring to my "flags"
// O(mn) time and O(max(m,n)) space
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void set_zeros(int **matrix, int m, int n) {
	bool *m_z_row = new bool[m];
	bool *m_z_col = new bool[n];
	memset(m_z_col, 0, sizeof(m_z_col));
	memset(m_z_row, 0, sizeof(m_z_row));

	// "detect" zero-columns and rows
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j)
			if (matrix[i][j] == 0)
				m_z_row[i] = m_z_col[j] = true;

	// reiterate the matrix then set zeros
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (m_z_col[j] || m_z_row[i])
				matrix[i][j] = 0;
}

void print_matrix(int **matrix, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << matrix[i][j] << "\t";

		cout << endl;
	}

	cout << endl;
}

int main() {
	const int m = 5;
	const int n = 5;
	int *matrix[m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j) 
			matrix[i][j] = rand() % 10;
	}

	print_matrix(matrix, m, n);
	set_zeros(matrix, m, n);
	print_matrix(matrix, m, n);
	
	return 0;
}
