#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

size_t SubstringCount(const string& str, const string& substr, const size_t off = 0)
{
	const auto pos = str.find(substr, off);
	if (pos != string::npos) return 1 + SubstringCount(str, substr, pos + 1);
	return 0;
}

int main()
{
	string str{};
	string substr{};

	cout << "Enter string: " << endl;
	getline(cin, str);
	
	cout << "Enter substring: " << endl;
	getline(cin, substr);
	
	const auto cnt = SubstringCount(str, substr);
	cout << "Count: " << cnt << endl;
}