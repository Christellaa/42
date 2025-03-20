#include "Array.hpp"

template <class T>
Array<T>::Array() : _array(nullptr), _size(0)
{}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for (int i = 0; i < _size; ++i)
		this._array[i] = T();
}

template <class T>
Array<T>::Array(Array& copy)
{
	new Array<t> array[];
	for (int i = 0; copy[i]; ++i)
		array[i] = copy[i];
	return array;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != rhs)
		this = rhs;
	return *this;
}

template <class T>
T& Array<T>::operator[](int idx)
{
	if (idx > this.size() || idx < 0)
		throw IndexOutOfBoundsException();
	return this[idx];
}

template <class T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds");
}

template <class T>
int Array<T>::size()
{
	return this._size;
}
