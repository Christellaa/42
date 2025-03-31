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

    std::stack<double>& getStack();

  private:
    std::stack<double> _stack;
};

#endif
