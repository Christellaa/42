#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <cstdlib>

template <typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T, size_t N>
void iter(T (&array)[N], size_t size, void (*function)(T))
{
	for (size_t i = 0; i < ::min(N, size); ++i)
		function(array[i]);
}

#endif
