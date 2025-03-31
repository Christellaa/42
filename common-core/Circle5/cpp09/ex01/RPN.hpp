#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <exception>
#include <stack>

class RPN
{
  public:
    RPN();
    RPN(RPN const& copy);
    ~RPN();

    RPN& operator=(RPN const& rhs);

    std::stack<double>& getStack();

    class UsageException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class TooMuchOperatorsException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class UnrecognizedTokenException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class DivisionByZeroException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class ResultException : public std::exception
    {
      public:
        const char* what() const throw();
    };

  private:
    std::stack<double> _stack;
};

#endif
