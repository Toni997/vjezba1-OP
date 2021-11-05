#pragma once
#include <vector>

void InputVector(std::vector<int>& vector, size_t elementsCount);
void InputVector(std::vector<int>& vector, int min, int max);
void PrintVector(std::vector<int>& vector);
std::vector<int>* Intersection(
	std::vector<int>& v1,
	std::vector<int>& v2);