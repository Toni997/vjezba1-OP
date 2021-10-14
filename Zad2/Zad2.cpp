#include "pch.h"

#include <iostream>
#include <ctime>

#include "Matrix.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	// Matrix matrix(2, 4, true);
	Matrix matrix({ {1,2}, {3,4}, {5,6} });
	// float span[2] = { 1,5 };
	// Matrix matrix(4, 2, span);
	// Matrix matrix;

	cout << endl;
	cout << "After initialization:";
	matrix.Print();
	
	matrix.Calculate(Operations::ScalarMultiplication, 2);
	cout << "After calculation:";
	matrix.Print();
	
	matrix.Transpose();
	cout << "Transposed:";
	matrix.Print();

	matrix.MultiplyWithMatrix({ {1,2}, {3,4}, {5,6} });
	cout << "Multiplied with matrix { {1,2}, {3,4}, {5,6} }:";
	matrix.Print();

	return EXIT_SUCCESS;
}

