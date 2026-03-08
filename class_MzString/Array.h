#pragma once
#include<iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class Array
{
	unsigned int size;
	T* array = new T[size];
public:
	Array();
	Array(int size);

	Array(const Array& array);// copy construct
	Array(Array&& array);//move construct

	~Array();

	Array& operator=(const Array& obj);//operator=
	Array& operator=(Array&& obj);

	template <typename T>
	friend ostream& operator<<(ostream& os, const Array<T>& obj);
	template <typename T>
	friend istream& operator>>(istream& is, Array<T>& obj);
};

template<typename T>
inline Array<T>::Array()
{
	this->size = 0;
	this->array = nullptr;
}

template<typename T>
inline Array<T>::Array(int size)
{
	this->size = size;
	array = new T[this->size];
	for (int i = 0; i < this->size; i++)
		array[i] = -50 + rand() % 61 * 1.2;
}

template<typename T>
inline Array<T>::Array(const Array& arr)
{
	size = arr.size;
	array = new T[size];
	for (int i = 0; i < size; i++)
		array[i] = arr.array[i];
}

template<typename T>
inline Array<T>::Array(Array&& arr)
{
	array = arr.array;
	size = arr.size;

	arr.array = nullptr;
	arr.size = 0;
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] array;
}

template<typename T>
inline Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this == &obj)
		return *this;
	delete[]array;
	size = obj.size;
	array = new T[size];
	for (int i = 0; i < size; i++)
		array[i] = obj.array[i];
	return *this;
}

template<typename T>
inline Array<T>& Array<T>::operator=(Array<T>&& obj)
{
	if (this == &obj)
		return *this;
	delete[]array;
	array = obj.array;
	size = obj.size;

	obj.array = nullptr;
	obj.size = 0;
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, const Array<T>& obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.array[i] << " ";
	os << endl;
	return os;
}

template<typename T>
istream& operator>>(istream& is, Array<T>& obj)
{
	cout << "Input arrays size: ";
	unsigned int n;
	is >> n;

	delete[] obj.array;
	obj.size = n;
	obj.array = (obj.size ? new T[obj.size] : nullptr);

	for (unsigned int i = 0; i < obj.size; i++) {
		cout << "Input #" << i << ": ";
		is >> obj.array[i];
	}
	return is;
}

