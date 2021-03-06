#pragma once
#include <vector>

template<typename T>
T GetMaxNumberRecursive(const std::vector<T>& array, T maxNumber = NULL, const size_t index = 0)
{
	if (index == 0) maxNumber = array[0];
	maxNumber = array[index] > maxNumber ? array[index] : maxNumber;
	if (index == array.size() - 1) return maxNumber;
	return GetMaxNumberRecursive(array, maxNumber, index + 1);
}

template<typename T>
T BetterGetMaxNumberRecursive(const std::vector<T>& array, const size_t index = 0)
{
	if (index == array.size() - 1) return array[array.size() - 1];
	return (array[index] > BetterGetMaxNumberRecursive(array, index + 1)) ? array[index] : BetterGetMaxNumberRecursive(array, index + 1);
}

inline float GetMinNumberRecursive(const std::vector<float>& array, float minNumber = NULL, const size_t index = 0)
{
	if (index == 0) minNumber = array[0];
	minNumber = array[index] < minNumber ? array[index] : minNumber;
	if (index == array.size() - 1) return minNumber;
	return GetMinNumberRecursive(array, minNumber, index + 1);
}