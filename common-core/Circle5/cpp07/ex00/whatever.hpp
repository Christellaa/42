#ifndef _WHATEVER_HPP_
#define _WHATEVER_HPP_

/*
template<typename T>:
template = keyword indicatin we're defining a function template
<typename T> = T is a placeholder type -> will be replaced with a specific type when the function is called (can be any data type or a custom class)

T swap(Tx, T y):
void = return type (can also be T)
swap = function's name
(T x, T y) = 2 params (x and y) of type T
*/

template <typename T>
void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T min(T& x, T& y)
{
	return (x < y) ? x : y;
}

template <typename T>
T max(T& x, T& y)
{
	return (x > y) ? x : y;
}

#endif
