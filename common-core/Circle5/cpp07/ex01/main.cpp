#include "iter.hpp"
#include <iostream>

void print(char c)
{
	std::cout << c << std::endl;
}

void print(int number)
{
	std::cout << number << std::endl;
}

void print(std::string str)
{
	std::cout << str << std::endl;
}

// void print(const int& number)
// {
// 	std::cout << number << std::endl;
// }

int square(int& n)
{
	return n * n;
}

int main()
{
	int array1[] = { 3, 4, 8, 11, 21, 2, 5 };
	char array2[] = { 'h', 'e', 'l', 'l', 'o' };
	std::string array3[] = { "hello", "no", "goodbye" };
	int array4[] = { 1, 2, 4, 3 };

	::iter(array1, 7, square);
	for (int i = 0; array1[i]; ++i)
		std::cout << array1[i] << std::endl;
	::iter(array2, 7, print);
	::iter(array3, 7, print);
	::iter(array4, 7, swap);
	for (int i = 0; array4[i]; ++i)
		std::cout << array4[i] << std::endl;
}
