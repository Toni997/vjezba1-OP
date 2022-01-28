#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "HigherThan.h"
#include "LowerThan.h"
#include "Numbers.h"

Numbers::Numbers(std::string fileName) : m_fileName(std::move(fileName))
{
	std::ifstream file(m_fileName);

	if (!file.is_open())
	{
		throw std::ifstream::failure("Error opening the file");
	}
}

void Numbers::Fill()
{
	std::ifstream file(m_fileName);

	std::istream_iterator<int> it(file);
	std::istream_iterator<int> endOfStream;

	std::copy(it, endOfStream, std::back_inserter(m_numbers));
}

int Numbers::CountHigherThan(int limit)
{
	return std::count_if(m_numbers.begin(), m_numbers.end(), HigherThan(limit));
}

int Numbers::GetMin()
{
	return *std::min_element(m_numbers.begin(), m_numbers.end());
}

int Numbers::GetMax()
{
	return *std::max_element(m_numbers.begin(), m_numbers.end());
}

void Numbers::RemoveLowerThan(int limit)
{
	m_numbers.erase(std::remove_if(m_numbers.begin(), m_numbers.end(), LowerThan(limit)), m_numbers.end());
}

void Numbers::SortDescendingOrder()
{
	std::sort(m_numbers.rbegin(), m_numbers.rend());
}

void Numbers::PrintVector()
{
	std::ostream_iterator<int> it(std::cout, "\n");
	std::copy(m_numbers.begin(), m_numbers.end(), it);
}
