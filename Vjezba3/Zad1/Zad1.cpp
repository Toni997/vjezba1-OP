#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	char mode{};
	vector<int> vector;

	cout << "Enter 1 for elementsCount mode or 2 for min-max mode of input:" << endl;
	cin >> mode;
	if (mode != '1' && mode != '2') return 1;

	if (mode == '1')
	{
		size_t elementsCount{};
		cout << "How many elements you want to enter:" << endl;
		cin >> elementsCount;
		InputVector(vector, elementsCount);
	}
	else
	{
		int min{}, max{};
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		InputVector(vector, min, max);
	}

	cout << endl;
	PrintVector(vector);

	return 0;
}
