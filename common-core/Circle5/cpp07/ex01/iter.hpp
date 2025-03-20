#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <cstdlib>
#include <iostream>

template <typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// test for each type beside void
template <typename T, size_t N>
void iter(T (&array)[N], size_t size, T (*function)(T&))
{
	for (size_t i = 0; i < ::min(N, size); ++i)
		function(array[i]);
}

// test for void
template <typename T, size_t N>
void iter(T (&array)[N], size_t size, void (*function)(T))
{
	for (size_t i = 0; i < ::min(N, size); ++i)
		function(array[i]);
}

// test for const
template <typename T, size_t N>
void iter(T (&array)[N], size_t size, void (*function)(const T&))
{
	for (size_t i = 0; i < ::min(N, size); ++i)
		function(array[i]);
}

// test for template1 having template2 as 3rd param
template <typename T, size_t N>
void iter(T (&array)[N], size_t size, void (*function)(T&, T&))
{
	for (size_t i = 0; i < ::min(N - 1, size - 1); ++i)
	{
		std::cout << "Comparing " << array[i] << " and " << array[i + 1] << std::endl;
		function(array[i], array[i + 1]);
	}
}

#endif
