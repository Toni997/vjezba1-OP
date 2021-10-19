#include <iostream>
#include "Vector.h"

int main()
{
    MyVector vector;
	
	vector.vector_new(2);
	vector.vector_push_back(1);
	vector.vector_push_back(2);
	vector.vector_pop_back();
	vector.vector_push_back(3);
	vector.vector_push_back(4);
	vector.vector_push_back(4);
	vector.vector_push_back(9);
	vector.vector_push_back(41);
	vector.vector_push_back(63);
	vector.vector_push_back(12);
	vector.vector_push_back(93);
	vector.vector_push_back(11);
	vector.vector_push_back(45);
	vector.vector_push_back(97);
	vector.vector_push_back(19);
	vector.vector_push_back(28);
	vector.vector_push_back(76);
	vector.vector_push_back(38);
	vector.vector_push_back(26);
	vector.vector_delete();
	vector.vector_new(2);
	vector.vector_push_back(1);
	vector.vector_push_back(2);
	vector.vector_pop_back();
	vector.vector_push_back(3);
	vector.vector_push_back(4);
	vector.vector_push_back(4);
	vector.vector_push_back(9);
	vector.vector_push_back(41);
	vector.vector_push_back(63);
	vector.vector_push_back(12);
	vector.vector_push_back(93);
	vector.vector_push_back(11);
	vector.vector_push_back(45);
	vector.vector_push_back(97);
	vector.vector_push_back(19);
	vector.vector_push_back(28);
	vector.vector_push_back(76);
	vector.vector_push_back(38);
	vector.vector_push_back(26);
	
    vector.print_vector();
    std::cout << std::endl << vector.vector_size() << " (size), " <<
		vector.vector_capacity() << " (capacity), first element: " << vector[0] << std::endl;
}
