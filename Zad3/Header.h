#pragma once
#include <vector>

template <typename T>
T GetMaxNumberIterative(const std::vector<T>& array)
{
	auto maxNumber = array[0];

	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i] > maxNumber)
		{
			maxNumber = array[i];
		}

	}

	return maxNumber;
}

template <typename T>
T GetMinNumberIterative(const std::vector<T>& array)
{
	auto minNumber = array[0];

	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i] < minNumber)
		{
			minNumber = array[i];
		}

	}

	return minNumber;
}

