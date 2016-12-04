#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	vector<vector<int>> matrix = {{4, 3, 2}, {3, 3, 2}, {1, 3, 2}};
	cout << "Matrix: " << endl;
	for (vector<int> row: matrix) {
		for (int el: row) 
			cout << el << "    ";
		cout << endl;
	}
	const int height = matrix.size();
	const int width = matrix[0].size();
	vector<vector<long>> matrix_col;
	long NaN = numeric_limits<long>::min();
	matrix_col.assign(width, vector<long>(height, NaN));
	int n_countries = 0;
	//int val = 0;
	for (int i = 0; i < height; i++) {
		//vector<int> stack;
		int n_el = 0; 
		for (int j = 0; j < width; j++) {
			n_el++;
			if (j+1 < width && matrix[i][j] != matrix[i][j+1] && n_el == 1) {
				matrix_col[j][i] = matrix[i][j];
				n_el = 0;
			} else if (j+1 < width-1 && matrix[i][j] != matrix[i][j+1] && n_el > 1) {
				n_countries++;
				n_el = 0;
			} 
			if (j+1 == width-1 && matrix[i][j] != matrix[i][j+1]) {
				if (n_el > 1)
					n_countries++;
				matrix_col[j+1][i] = matrix[i][j+1];
				n_el = 0;
			}
		}
		if (n_el > 1)
			n_countries++;
	}
	
	cout << "Number of countries row-wise: " <<  n_countries << endl;

	cout << "Matrix 2: " << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix_col[j][i] == NaN)
				cout << "NaN" << " ";
			else
			cout << matrix_col[j][i] << "   ";
		}
		cout << endl;
	}	

	for (int i = 0; i < width; i++) {
		int n_el = 0;
		for (int j = 0; j < height; j++) {
			if (matrix_col[i][j] != NaN )
				n_el++;
			if (j+1 < height && matrix_col[i][j] != matrix_col[i][j+1] && n_el > 1) {
				n_countries++;
				n_el = 0;
			}
			if (j+1 < height && matrix_col[i][j] != matrix_col[i][j+1] && n_el == 1)
				n_el = 0;
		}
		if (n_el > 1)
			n_countries++;
	}

	cout << "Number of countries column-wise: " <<  n_countries << endl;
	cout << 5%10 << endl;
	cout << 9%10 << endl;
	cout << 12%10 << endl;
	
	return 0;
}
