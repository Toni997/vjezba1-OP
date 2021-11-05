#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	vector<int> v;
	size_t elementsCount{};

	cout << "How many elements?" << endl;
	cin >> elementsCount;
	
	v.resize(elementsCount);
	for (size_t i = 0; i < elementsCount; i++)
	{
		cout << "Enter " << i + 1 << ". number" << endl;
		cin >> v[i];
	}

	cout << endl;

	sort(v.begin(), v.end());
	
	v.insert(v.begin(), 0);
	
	auto sum = accumulate(v.begin(), v.end(), 0);
	v.emplace_back(sum);

	for (auto& n : v)
		cout << n << endl;
}
