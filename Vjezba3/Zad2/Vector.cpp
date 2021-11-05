#include <iostream>
#include "Vector.h"
#include <algorithm> //std::sort
#include <iostream> //std::cout
#include <string> //std::string
#include <vector> //std::vector

using namespace std;

void InputVector(std::vector<int>& vector, const size_t elementsCount)
{
	int number{};
	for (size_t i = 0; i < elementsCount; i++)
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
	for (const auto& number : vector)
		cout << number << endl;
}

std::vector<int>* Intersection(
	const vector<int>& v1,
	const vector<int>& v2)
{
	auto* v3 = new vector<int>;

	for(const auto& number : v1)
	{
		if (find(v2.begin(), v2.end(), number) == v2.end()) 
			v3->emplace_back(number);
	}

	return v3;
}