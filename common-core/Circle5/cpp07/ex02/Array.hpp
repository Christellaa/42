#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <cstddef>
#include <exception>

template <class T> class Array
{
  public:
    Array();
    Array(unsigned int n);
    Array(Array& copy);
    ~Array();

    Array<T>& operator=(const Array<T>& rhs);
    T&        operator[](int idx);

    class IndexOutOfBoundsException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    int size();

  private:
    T*  _array;
    int _size;
};

#endif
