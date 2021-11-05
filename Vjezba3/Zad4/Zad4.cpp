#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	std::vector<int> v { 1,2,3,4,5 };

	v.erase(v.begin() + 3);

	for (auto& n : v)
		cout << n << endl;
}
