#pragma once

template <typename T>
class Stack
{
public:
	Stack()
	{
		realloc(2);
	}

	~Stack()
	{
		for (int i = 0; i < m_size; i++)
			m_arr[i].~T();

		delete[] m_arr;
	}

	void push(const T& element)
	{
		if (m_capacity <= m_size)
			realloc(m_capacity * 2);

		m_arr[m_size] = element;
		m_size++;
	}

	void pop()
	{
		if (m_size <= 0) return;

		m_arr[m_size - 1].~T();
		m_size--;
	}

	bool is_empty()	const { return size <= 0; }
	int size() const { return m_size; }

private:
	void realloc(size_t newCapacity)
	{
		if (newCapacity <= m_capacity) return;

		T* newArr = new T[newCapacity];
		for (int i = 0; i < m_size; i++)
			newArr[i] = m_arr[i];

		delete[] m_arr;
		m_arr = newArr;
		m_capacity = newCapacity;
	}

private:
	T* m_arr = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;
};

