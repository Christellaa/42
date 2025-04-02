#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& copy) : _list(copy._list), _vector(copy._vector) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
    if (this != &rhs)
    {
        this->_list   = rhs._list;
        this->_vector = rhs._vector;
    }
    return *this;
}

const char* PmergeMe::UsageException::what() const throw()
{
    return ("Usage: ./PmergeMe [sequence of numbers]");
}

const char* PmergeMe::NotANumberException::what() const throw()
{
    return ("Error: not a valid number");
}

const char* PmergeMe::NegativeNumberException::what() const throw()
{
    return ("Error: negative number");
}

const char* PmergeMe::TooLargeNumberException::what() const throw()
{
    return ("Error: number larger than an int");
}

std::list<int>& PmergeMe::getList()
{
    return this->_list;
}

std::vector<int>& PmergeMe::getVector()
{
    return this->_vector;
}
