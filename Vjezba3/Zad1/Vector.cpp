#include <iostream>
#include "Vector.h"

using namespace std;

void InputVector(std::vector<int>& vector, const size_t elementsCount)
{
	int number{};
	for(size_t i = 0; i < elementsCount; i++)
	{
		cout << "Enter " << i + 1 << ". number:" << endl;
		cin >> number;
		vector.emplace_back(number);
	}
}

void InputVector(std::vector<int>& vector, const int min, const int max)
{
	int number{};
	auto i = 0;
	while (true)
	{
		cout << "Enter " << ++i << ". number:" << endl;
		cin >> number;
		
		if (number < min || number > max) break;
		vector.emplace_back(number);
	}
}

void PrintVector(const std::vector<int>& vector)
{
	for(const auto& number : vector)
		cout << number << endl;
}


