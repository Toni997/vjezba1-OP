#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	vector<int> vector1;
	vector<int> vector2;
	char mode{};

	cout << "Enter 1 for elementsCount mode or 2 for min-max mode of input:" << endl;
	cin >> mode;
	if (mode != '1' && mode != '2') return 1;

	if (mode == '1')
	{
		size_t elementsCount{};
		cout << "How many elements you want to enter:" << endl;
		cin >> elementsCount;
		InputVector(vector1, elementsCount);
		cout << endl << "Enter 2. vector below:" << endl << endl;
		InputVector(vector2, elementsCount);
	}
	else
	{
		int min{}, max{};
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		InputVector(vector1, min, max);
		cout << endl << "Enter 2. vector below:" << endl << endl;
		InputVector(vector2, min, max);
	}

	auto* vector3 = Intersection(vector1, vector2);
	
	cout << endl;
	PrintVector(vector1);
	cout << endl;
	PrintVector(vector2);
	cout << endl;
	PrintVector(*vector3);
	
	delete vector3;
	return 0;
}
