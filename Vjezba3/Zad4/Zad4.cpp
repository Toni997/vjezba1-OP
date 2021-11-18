#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void myErase(vector<int>& v, size_t index)
{
	try
	{
		v.at(i) = v.back();
		v.pop_back();
	}
	catch(const std::out_of_range& e)
	{
		cerr << "Out of range error: " << e.what() << endl;
	}
}

int main()
{
	std::vector<int> v { 1,2,3,4,5 };

	myErase(v, 2);

	for (auto& n : v)
		cout << n << endl;
}
