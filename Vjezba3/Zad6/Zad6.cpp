#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void StringsToVectorThenReverseAndSort(vector<string>& v)
{
	string temp{};
	size_t n{};
	
	cout << "How much strings?" << endl;
	cin >> n;
	cout << endl;

	v.resize(n);
	for(auto& str : v)
	{
		cout << "Enter the next string:" << endl;
		cin.ignore();
		getline(cin, str);
	}

	for (auto& str : v)
		reverse(str.begin(), str.end());

	sort(v.begin(), v.end());

}

int main()
{
	vector<string> v;

	StringsToVectorThenReverseAndSort(v);

	cout << endl;
	for (auto& str : v)
	{
		cout << str << endl;
	}
}