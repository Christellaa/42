#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <exception>
#include <algorithm>
#include <iostream>

class ContainerTypeException : public std::exception
{
	public:
		const char *what() const throw();
};

class OccurenceNotFoundException : public std::exception
{
	public:
		const char *what() const throw();
};

/* for sequence containers */
template <typename T>
void easyfind(T& container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it != container.end())
		std::cout << "Found " << *it << "!" << std::endl;
	else
		throw OccurenceNotFoundException();
}

/* for associative containers */
// template <typename T>
// void easyfind(T& container, int number)
// {
// 	typename T::iterator it = container.find(number);
// 	if (it != container.end())
// 		std::cout << "Found " << *it << "!" << std::endl;
// 	else
// 		throw OccurenceNotFoundException();	
// }

#endif

/*
sequence container:
	- elements are stored in insertion order
	- access elements with their position (= idx)
	- can store duplicate elements
	types: vector, list, deque, array
	eg:
		std::vector<int> v = { 5, 10, 15 };
		std::cout < v[0]; // access 5

associative container:
	- store key-value pair
	- sorts automatically the elements by keys
	- access elements with their key
	- only multimap and multiset can store duplicate keys
	types: map, set, multimap, multiset
	eg:
		std::map<int, std::string> m = { {1, "one"}, {2, "two"}, {3, "three"} };
		std::cout << m[2]; // access "two" using the key 2
*/
