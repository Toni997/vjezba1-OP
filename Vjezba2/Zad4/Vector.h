#pragma once

#include <cstddef>
#include <iostream>
struct MyVector
{
    // member functions
    void vector_new(size_t sz = 0);
    void vector_delete();
    void vector_push_back(int n);/* adds a new element at the end of the vector */
    void vector_pop_back();/* removes the last element in the vector */
    int& vector_front();/* returns a reference to the first element in the vector*/
    int& vector_back(); /* returns a reference to the last element in the vector */
    const int& operator[](size_t index) const;
    size_t vector_size(); /* returns the number of the elements in the vector */
    size_t vector_capacity();

    void print_vector();

	private:
	    int* arr = nullptr;
	    size_t size = 0, capacity = 0;
};
