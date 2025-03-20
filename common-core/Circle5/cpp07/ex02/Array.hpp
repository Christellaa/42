#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

template <class T>
class Array
{
	public:
		Array(); // creates empty array
		Array(unsigned int n); // creates array of n elem init by default
		Array(Array& copy); // modifying either the ori or its copy mustn't affect the other array

		Array<T>& operator=(const Array<T>& rhs); // modifying either the ori or its copy mustn't affect the other array
		T& operator[](int idx); // to access elem

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw(); // throw exception when accessing an elem with [] and idx is ofb
		};

		int size(); //mustn't modify the current instance

	private:
		T** _array;
		int _size;
};

#endif
