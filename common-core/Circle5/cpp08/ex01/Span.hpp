#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <exception>
#include <vector>

class Span
{
  public:
    Span(unsigned int max);
    Span(const Span& copy);
    ~Span();

    Span& operator=(const Span& rhs);

    class MaxExceededException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class NotEnoughForSpanException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void showNumbers();
    int  shortestSpan();
    int  longestSpan();

  private:
    unsigned int     _max;
    std::vector<int> _span;
    Span();
};

#endif
