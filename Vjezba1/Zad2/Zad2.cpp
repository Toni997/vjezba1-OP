#include "pch.h"

#include <iostream>
#include <ctime>

#include "Matrix.h"

using namespace std;

int main()  // NOLINT(bugprone-exception-escape)
{
	srand(time(nullptr));

	Matrix matrix({ {1,2}, {3,4}, {5,6} });

	cout << endl;
	cout << "After initialization:";
	matrix.Print();

	try
	{
		matrix.AddOrSubtractByMatrix(Operations::Addition, { {1,1}, {1,1}, {1,1} });
		cout << "After calculation:";
		matrix.Print();

	} catch(MatricesDoNotAgree& e)
	{
		cout << e.what() << endl;
	}
	
	
	matrix.Transpose();
	cout << "Transposed:";
	matrix.Print();

	matrix.MultiplyByMatrix({ {1,2}, {3,4}, {5,6} });
	cout << "Multiplied with matrix { {1,2}, {3,4}, {5,6} }:";
	matrix.Print();

	return EXIT_SUCCESS;
}

