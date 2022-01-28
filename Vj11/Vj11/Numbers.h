#pragma once
#include <vector>
#include <string>

class Numbers
{
public:
	Numbers(std::string fileName);
	void Fill();
	int CountHigherThan(int limit);
	int GetMin();
	int GetMax();
	void RemoveLowerThan(int limit);
	void SortDescendingOrder();
	void PrintVector();

private:
	std::string m_fileName;
	std::vector<int> m_numbers;
};

