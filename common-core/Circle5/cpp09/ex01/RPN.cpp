#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& copy) : _stack(copy._stack) {}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& rhs)
{
    if (this != &rhs)
        this->_stack = rhs._stack;
    return *this;
}

std::stack<double>& RPN::getStack()
{
    return this->_stack;
}

const char* RPN::UsageException::what() const throw()
{
    return ("Usage: ./RPN [inverted polish mathematical expression in quotes]");
}

const char* RPN::TooMuchOperatorsException::what() const throw()
{
    return ("Error: too much operators in the expression");
}

const char* RPN::UnrecognizedTokenException::what() const throw()
{
    return ("Error: token not recognized. Only digits and operators [+ - * /] are accepted");
}

const char* RPN::DivisionByZeroException::what() const throw()
{
    return ("Error: Division by zero");
}

const char* RPN::ResultException::what() const throw()
{
    return ("Error: result should be a single number");
}
