#include <iostream>
#include <vector>

#include "Header.h"

using namespace std;

int main()
{
	const vector<float> array = { 8,1,5,7,10,3,5,4,9.3 };

	cout << "Max number (recursive) is: " << GetMaxNumberRecursive(array);
	cout << endl;
	cout << "Max number (better recursive) is: " << BetterGetMaxNumberRecursive(array);
	cout << endl;
	cout << "Min number (recursive) is: " << GetMinNumberRecursive(array);
}

