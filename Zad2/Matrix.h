#pragma once

#include <vector>

enum class Operations { Addition, Subtraction, ScalarMultiplication };

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
	void MultiplyWithMatrix(const std::vector<std::vector<float>> otherMatrix);

private:
	std::vector<std::vector<float>> matrix;
};