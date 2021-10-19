#include <iostream>

int& GetElementAtIndex(int numbers[], const int index)
{
	return numbers[index];
}

int main()  // NOLINT(bugprone-exception-escape)
{
    int numbers[] { 1,5,10,13,17 };

	GetElementAtIndex(numbers, 0)++;

	std::cout << numbers[0];
}