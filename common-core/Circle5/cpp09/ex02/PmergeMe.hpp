#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <exception>
#include <list>
#include <vector>

class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    ~PmergeMe();

    PmergeMe& operator=(PmergeMe const& rhs);
    class UsageException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class NegativeNumberException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class NotANumberException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class TooLargeNumberException : public std::exception
    {
      public:
        const char* what() const throw();
    };

  private:
    std::list<int>   _list;
    std::vector<int> _vector;
};

#endif
