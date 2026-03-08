#include "Array.h"
template<typename T>
inline Array<T>::Array()
{
	size = 10;
	T* array = new T[size];
	for (int i = 0; i < size; i++)
		array[i] = -50 + rand() % 61 * 1.2;
}

template<typename T>
Array<T>::Array(int size)
{
	T* array = new T[size];
	for (int i = 0; i < size; i++)
		array[i] = -50 + rand() % 61 * 1.2;
}

template<typename T>
Array<T>::Array(const Array& arr)
{
	for (int i = 0; i < size; i++)
		array[i] = arr[i];
}

template<typename T>
Array<T>::Array(Array&& arr)
{
	array = arr.array;
	size = arr.size;

	arr.array = nullptr;
	arr.size = nullptr;
}

template<typename T>
Array<T>::~Array()
{
	for (int i = 0; i < size; i++)
		delete array[i];
	delete[] array;
}

template<typename T>
Array& Array<T>::operator=(const Array& obj)
{
	// TODO: insert return statement here
}

ostream& operator<<(ostream& os, const Array& obj)
{
	
}
