#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{
	const vector<float> array = { 1.2,5,7,3,5,4 };

	cout << "Max number (iterative) is: " << GetMaxNumberIterative(array);
	cout << endl;
	cout << "Min number (iterative) is: " << GetMinNumberIterative(array);
}

