#include "pch.h"
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(
	vector<vector<float>> matrix
) : matrix(move(matrix))
{
}

Matrix::Matrix(
	int numberOfRows = NULL,
	int numberOfColumns = NULL,
	const bool shouldAutoFill = false
)
{
	if (numberOfRows == NULL || numberOfColumns == NULL)
	{
		cout << "Enter number of rows" << endl;
		cin >> numberOfRows;
		cout << "Enter number of columns" << endl;
		cin >> numberOfColumns;

		cout << endl;
	}

	auto cnt = 1;
	float entry = NULL;

	matrix.reserve(numberOfRows);
	for (auto i = 0; i < numberOfRows; i++)
	{
		matrix.emplace_back();
		for (auto j = 0; j < numberOfColumns; j++)
		{
			if (shouldAutoFill)
			{
				matrix[i].emplace_back(static_cast<float>(cnt++));
			}
			else
			{
				cout << "Enter " << j + 1 << ". number in row " << i + 1 << endl;
				cin >> entry;
				matrix[i].emplace_back(static_cast<float>(entry));
			}
		}
	}
}

Matrix::Matrix(
	const int numberOfRows,
	const int numberOfColumns,
	float(&span)[2]
)
{
	matrix.reserve(numberOfRows);
	for (auto i = 0; i < numberOfRows; i++)
	{
		matrix.emplace_back();
		for (auto j = 0; j < numberOfColumns; j++)
		{
			const auto number = span[0]
				+ static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (span[1] - span[0]));
			matrix[i].emplace_back(number);
		}
	}
}

void Matrix::Print() const
{
	cout << endl;

	for (const auto& i : matrix)
	{
		for (auto j : i)
		{
			cout << setprecision(4) << right << j << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::Calculate(const Operations operation, float value)
{
	if (value == NULL)
	{
		cout << "Enter the number:" << endl;
		cin >> value;
	}

	for (auto& i : matrix)
	{
		for (auto& j : i)
		{
			switch (operation)
			{
			case Operations::Addition:
				j += value;
				break;
			case Operations::Subtraction:
				j -= value;
				break;
			case Operations::ScalarMultiplication:
				j *= value;
				break;
			default:
				j += value;
			}
		}
	}
}

void Matrix::Transpose()
{
	vector<vector<float>> newMatrix;

	newMatrix.reserve(matrix[0].size());
	auto shouldEmplace = true;
	for (auto& i : matrix)
	{
		for (size_t j = 0; j < i.size(); j++)
		{
			if(shouldEmplace) newMatrix.emplace_back();
			newMatrix[j].emplace_back(i[j]);
		}
		shouldEmplace = false;
	}

	matrix = newMatrix;
}

void Matrix::MultiplyWithMatrix(const std::vector<std::vector<float>> otherMatrix)
{
	if (matrix[0].size() != otherMatrix.size()) return;
	
	vector<vector<float>> newMatrix;
	
	// reserve rows
	newMatrix.reserve(matrix.size());

	for (size_t i = 0; i < newMatrix.capacity(); i++)
	{
		newMatrix.emplace_back();
		
		// reserve columns
		for (auto& row : newMatrix)
			row.reserve(otherMatrix[0].size());
		
		for (size_t j = 0; j < newMatrix[0].capacity(); j++)
		{
			newMatrix[i].emplace_back();
			
			float value = 0;

			for(size_t k = 0; k < matrix[0].size(); k++)
				value += matrix[i][k] * otherMatrix[k][j];
			
			newMatrix[i][j] = value;
		}
	}

	matrix = newMatrix;
}

