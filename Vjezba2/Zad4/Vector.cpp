#include "Vector.h"

void MyVector::vector_new(const size_t sz)
{
    arr = new int[sz];
    capacity = sz;
}

void MyVector::vector_delete()
{
    delete[] arr;
    size = 0;
    capacity = 0;
}

void MyVector::vector_push_back(int n)
{
    if (capacity == size)
    {
        auto* newArr = new int[capacity * 2];
    	
		for(size_t i = 0; i < size; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }

    arr[size] = n;
    size++;
}

void MyVector::vector_pop_back()
{
	if (size > 0)
	{
        arr[size - 1] = NULL;
        size--;
	}
    
}

int& MyVector::vector_front() const
{
	if(size > 0)
        return arr[0];
}

int& MyVector::vector_back() const
{
    if (size > 0)
	    return arr[size - 1];
}

size_t MyVector::vector_size() const
{
    return size;
}

size_t MyVector::vector_capacity() const
{
    return capacity;
}

const int& MyVector::operator[](const size_t index) const
{
    if (index <= size)
        return arr[index];
}

void MyVector::print_vector() const
{
    for (size_t i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}