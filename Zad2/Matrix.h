#pragma once

#include <vector>

enum class Operations { Addition, Subtraction, Multiplication };

struct Matrix {
	Matrix(
		std::vector<std::vector<float>> matrix
	);

	Matrix(
		const int numberOfRows = NULL,
		const int numberOfColumns = NULL,
		const bool shouldAutoFill = false
	);

	Matrix(
		const int numberOfRows,
		const int numberOfColumns,
		float(&span)[2]
	);

	void Print() const;
	void Calculate(const Operations operation, float value = NULL);
	void Transpose();

private:
	std::vector<std::vector<float>> matrix;
};