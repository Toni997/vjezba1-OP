#pragma once

#include <vector>

enum class Operations { Addition, Subtraction, Multiplication };

struct Matrix {
	explicit Matrix(
		std::vector<std::vector<float>> matrix
	);

	Matrix(
		int numberOfRows,
		int numberOfColumns,
		bool shouldAutoFill
	);

	Matrix(
		int numberOfRows,
		int numberOfColumns,
		float(&span)[2]
	);

	void Print() const;
	void Calculate(Operations operation, float value = NULL);
	void Transpose();

private:
	std::vector<std::vector<float>> matrix;
};