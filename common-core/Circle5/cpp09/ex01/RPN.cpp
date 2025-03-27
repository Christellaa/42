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

std::stack<float>& RPN::getStack()
{
	return this->_stack;
}
