#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : _max(0), _span() {}

Span::Span(unsigned int max) : _max(max), _span() {}

Span::Span(const Span& copy) : _max(copy._max), _span(copy._span) {}

Span::~Span() {}

Span& Span::operator=(const Span& rhs)
{
    if (this->_span != rhs._span)
    {
        this->_max  = rhs._max;
        this->_span = rhs._span;
    }
    return *this;
}

const char* Span::MaxExceededException::what() const throw()
{
    return ("Span is full");
}

const char* Span::NotEnoughForSpanException::what() const throw()
{
    return ("Not enough numbers to get the span");
}

void Span::addNumber(int number)
{
    if (this->_span.size() < this->_max)
        this->_span.push_back(number);
    else
        throw MaxExceededException();
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_span.size() + std::distance(begin, end) <= this->_max)
        this->_span.insert(this->_span.end(), begin, end);
    else
        throw MaxExceededException();
}

void Span::showNumbers()
{
    for (size_t i = 0; i < this->_span.size(); ++i)
        std::cout << this->_span[i] << std::endl;
}

int Span::shortestSpan()
{
    if (this->_span.size() < 2)
        throw NotEnoughForSpanException();
    std::vector<int> tmp = this->_span;
    std::sort(tmp.begin(), tmp.end());
    int shortestSpan = abs(tmp[0] - tmp[1]);
    for (size_t i = 0; i < tmp.size() - 1; ++i)
    {
        int span = abs(tmp[i] - tmp[i + 1]);
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if (this->_span.size() < 2)
        throw NotEnoughForSpanException();
    std::vector<int> tmp = this->_span;
    std::sort(tmp.begin(), tmp.end());
    int longestSpan = abs(tmp[0] - tmp[tmp.size() - 1]);
    return longestSpan;
}
