#include <fstream>
#include <iostream>
#include "Numbers.h"

int main()
{
	try
	{
		Numbers numbers("numbers.txt");
		numbers.Fill();
		std::cout << "Numbers higher than 500: " << numbers.CountHigherThan(500) << std::endl;
		std::cout << "Min number: " << numbers.GetMin() << std::endl;
		std::cout << "Max number: " << numbers.GetMax() << std::endl;
		numbers.RemoveLowerThan(300);
		numbers.SortDescendingOrder();
		numbers.PrintVector();
	}
	catch (const std::ifstream::failure& e)
	{
		std::cout << e.what();
	}
}