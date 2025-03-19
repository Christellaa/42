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

int main()
{
	int array1[] = { 3, 4, 8, 11, 21, 2, 5 };
	char array2[] = { 'h', 'e', 'l', 'l', 'o' };
	std::string array3[] = { "hello", "no", "goodbye" };
	::iter(array1, 7, print);
	::iter(array2, 7, print);
	::iter(array3, 7, print);
}
