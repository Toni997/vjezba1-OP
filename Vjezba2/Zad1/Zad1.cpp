#include <iostream>

using namespace std;

void GetMinAndMax(const int numbers[], const int length, int& min, int& max)
{
	min = numbers[0];
	max = numbers[0];

	for (auto i = 1; i < length; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
}

int main()  // NOLINT(bugprone-exception-escape)
{
	auto min = NULL;
	auto max = NULL;
	auto length = NULL;

	cout << "How many numbers will you enter?" << endl;
	cin >> length;

	auto* numbers = new int[length];
	
	for(auto i = 0; i < length; i++)
	{
		cout << "Enter " << i+1 << ". number:" << endl;
		cin >> numbers[i];
	}

	GetMinAndMax(numbers, length, min, max);
	
    std::cout << "max: " << max << " min: " << min;

	delete[] numbers;
}