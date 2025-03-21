#include "easyfind.hpp"
#include "easyfind.tpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main()
{
	/* for sequence containers */
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	try
	{
		easyfind(v, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(v, 'k');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(v, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<int>empty;
	try
	{
		easyfind(empty, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<char> vc;
	vc.push_back('a');
	vc.push_back('b');
	try
	{
		easyfind(vc, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	std::list<int> l;
	l.push_back(4);
	l.push_back(2);
	l.push_back(7);
	try
	{
		easyfind(l, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::deque<int> dq;
	dq.push_back(3);
	dq.push_back('a');
	try
	{
		easyfind(dq, 97);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	/* for associative containers */
	// std::set<int> s;
	// s.insert(5);
	// s.insert(8);
	// s.insert(3);
	// s.insert(2);
	// try
	// {
	// 	easyfind(s, 8);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }	
}
