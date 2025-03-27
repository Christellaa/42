#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <stack>

class RPN
{
	public:
		RPN();
		RPN(RPN const& copy);
		~RPN();

		RPN& operator=(RPN const& rhs);

		std::stack<float>& getStack();

	private:
		std::stack<float> _stack;
};

#endif
