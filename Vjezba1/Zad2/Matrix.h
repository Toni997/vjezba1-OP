#pragma once

#include <vector>

enum class Operations { Addition, Subtraction, Multiplication };

struct MatricesDoNotAgree : std::exception
{
	const char* what() const noexcept override
	{
		return "ERROR: Matrices do not agree.";
	}
};

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
	void AddOrSubtractByMatrix(Operations operation, const std::vector<std::vector<float>>& otherMatrix);
	void Transpose();
	void MultiplyByMatrix(const std::vector<std::vector<float>>& otherMatrix);

private:
	std::vector<std::vector<float>> matrix;
};