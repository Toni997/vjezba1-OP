#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

int main()  // NOLINT(bugprone-exception-escape)
{
	vector<float> array;

	string entry;
	while (true) {
		cout << "Enter a number: (type . to finish with entering numbers)" << endl;

		cin >> entry;
		if (entry != ".")
		{
			try
			{
				array.emplace_back(stof(entry));
				cout << endl << "Added!" << endl;
			}
			catch (invalid_argument&)
			{
				cout << endl << "Not a number. Try again!" << endl;
			}
		}
		else break;
	}

	cout << "Max number (recursive) is: " << GetMaxNumberRecursive(array);
	cout << endl;
	cout << "Max number (better recursive) is: " << BetterGetMaxNumberRecursive(array);
	cout << endl;
	cout << "Min number (recursive) is: " << GetMinNumberRecursive(array);
}

