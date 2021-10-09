#include "pch.h"
#include <iostream>

using namespace std;

struct Matrix {
	void Matrix()
	{
		cout << "Enter number of rows" << endl;
		cin >> numberOfRows;
		cout << "Enter number of columns" << endl;
		cin >> numberOfColumns;

		for (size_t i = 0; i < numberOfRows; i++)
		{
			for (size_t j = 0; j < numberOfColumns; j++)
			{
				cout << "Enter " << j + 1 << ". number in row " << i + 1 << endl;
				cin >> matrix[i][j];
			}
		}
	}

	void PrintMatrix()
	{
		cout << endl << endl;

		for (size_t i = 0; i < numberOfRows; i++)
		{
			for (size_t j = 0; j < numberOfColumns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	int GetNumberOfRows() return numberOfRows;
	int GetNumberOfColumns() return numberOfColumns;
		
	private:
		int matrix[100][100];
		int numberOfRows;
		int numberOfColumns;
};

int main()
{
	Matrix newMatrix;
	newMatrix.PrintMatrix();
}

