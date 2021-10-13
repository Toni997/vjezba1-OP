#include <iostream>
#include <vector>

#include "Header.h"

using namespace std;

int main()
{
	const vector<int> array = { 1,5,7,3,5,4 };

	cout << "Max number (recursive) is: " << GetMaxNumberRecursive(array);
	cout << endl;
	cout << "Max number (better recursive) is: " << BetterGetMaxNumberRecursive(array);
	cout << endl;
	cout << "Min number (iterative) is: " << GetMinNumberRecursive(array);
}

