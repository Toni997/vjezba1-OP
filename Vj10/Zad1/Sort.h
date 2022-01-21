#pragma once

template <typename T>
void sort(T* arr, int n)
{
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			T tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

template<>
void sort<char>(char* arr, int n)
{
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 &&
			(arr[j - 1] < 97 ? arr[j - 1] + 32 : arr[j - 1]) >
			(arr[j] < 97 ? arr[j] + 32 : arr[j]))
		{
			char tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

template <typename T>
void printArr(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << (i < n-1 ? ", " : "");
	}
	std::cout << std::endl;
}