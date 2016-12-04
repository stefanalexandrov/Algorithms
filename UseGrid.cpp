#include "Grid.h"

int main() {
	Grid<int, 10, 10> matrix(33);
	matrix.print(); 
	std::cout << std::endl;
	Grid<int, 10, 10> matrix2 = matrix;
	matrix2.print();
	std::cout << std::endl;
	Grid<int, 15, 15> matrix3 = matrix2;
	matrix3.print();
	std::cout << std::endl;
	matrix3 = matrix;
	matrix3.print();

	return 0;
}
