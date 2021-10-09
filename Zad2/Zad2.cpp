#include "pch.h"
#include <iomanip>
#include <iostream>

using namespace std;

enum class operations { addition, subtraction, multiplication };

struct matrix {

	matrix()
	{
		cout << "Enter number of rows" << endl;
		cin >> number_of_rows_;
		cout << "Enter number of columns" << endl;
		cin >> number_of_columns_;

		cout << endl;

		for (size_t i = 0; i < number_of_rows_; i++)
		{
			for (size_t j = 0; j < number_of_columns_; j++)
			{
				cout << "Enter " << j + 1 << ". number in row " << i + 1 << endl;
				cin >> matrix_array_[i][j];
			}
		}
	}

	void print()
	{
		cout << endl;

		for (size_t i = 0; i < number_of_rows_; i++)
		{
			for (size_t j = 0; j < number_of_columns_; j++)
			{
				cout << setprecision(4) << right << matrix_array_[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	void calculate(const operations operation, float value = NULL)
	{
		if(value == NULL)
		{
			cout << "Enter the number:" << endl;
			cin >> value;
		}

		for (size_t i = 0; i < number_of_rows_; i++)
		{
			for (size_t j = 0; j < number_of_columns_; j++)
			{
				switch(operation)
				{
					case operations::addition:
						matrix_array_[i][j] += value;
						break;
					case operations::subtraction:
						matrix_array_[i][j] -= value;
						break;
					case operations::multiplication:
						matrix_array_[i][j] *= value;
						break;
					default:
						matrix_array_[i][j] += value;
				}
			}
		}
	}

	void transpose()
	{
		float new_matrix[100][100];
		
		for (size_t i = 0; i < number_of_rows_; i++)
		{
			for (size_t j = 0; j < number_of_columns_; j++)
			{
				new_matrix[i][j] = matrix_array_[j][i];
			}
		}

		for (size_t i = 0; i < number_of_rows_; i++)
		{
			for (size_t j = 0; j < number_of_columns_; j++)
			{
				matrix_array_[i][j] = new_matrix[i][j];
			}
		}
	}

	private:
		float matrix_array_[100][100]{};
		size_t number_of_rows_{};
		size_t number_of_columns_{};
};

int main()
{
	auto *new_matrix = new matrix;

	cout << endl;
	cout << "After initialization:";
	new_matrix->print();
	
	new_matrix->calculate(operations::addition, 5);
	cout << "After calculation:";
	new_matrix->print();
	
	new_matrix->transpose();
	cout << "Transposed:";
	new_matrix->print();

	delete new_matrix;
	return EXIT_SUCCESS;
}

