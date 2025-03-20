#include "Array.hpp"

template <class T> Array<T>::Array() : _array(NULL), _size(0) {}

template <class T> Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    for (int i = 0; i < this->size(); ++i)
        this->_array[i] = T();
}

template <class T> Array<T>::Array(Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
    for (int i = 0; i < copy.size(); ++i)
        _array[i] = copy._array[i];
}

template <class T> Array<T>::~Array()
{
    delete[] this->_array;
}

template <class T> Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this != &rhs)
    {
        delete[] this->_array;
        this->_array(new T[rhs.size()]);
        this->_size = rhs.size();
        for (int i = 0; i < rhs._size(); ++i)
            this->_array[i] = rhs._array[i];
    }
    return *this;
}

template <class T> T& Array<T>::operator[](int idx)
{
    if (idx >= this->size() || idx < 0)
        throw IndexOutOfBoundsException();
    return this->_array[idx];
}

template <class T> const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Index is out of bounds");
}

template <class T> int Array<T>::size()
{
    return this->_size;
}
