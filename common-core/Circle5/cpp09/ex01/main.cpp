// use std::stack
#include "RPN.hpp"
#include <iostream>

bool parseExpression(std::string expression)
{
    int nbOperator = 0;
    int nbOperand  = 0;
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
            continue;
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
                 expression[i] == '/')
        {
            nbOperator++;
            if (nbOperator >= nbOperand)
            {
                std::cerr << "Error: too much operators in the expression" << std::endl;
                return false;
            }
        }
        else if (isdigit(expression[i]))
            nbOperand++;
        else
        {
            std::cerr
                << "Error: token not recognized. Only digits and operators [+ - * /] are accepted"
                << std::endl;
            return false;
        }
    }
    return true;
}

void executeOperation(RPN& stack, char operation)
{
    double second = stack.getStack().top();
    stack.getStack().pop();
    double first = stack.getStack().top();
    stack.getStack().pop();
    double res;
    if (operation == '+')
        res = first + second;
    else if (operation == '-')
        res = first - second;
    else if (operation == '*')
        res = first * second;
    else if (operation == '/')
    {
        if (second == 0)
        {
            std::cerr << "exception to do" << std::endl;
            return;
        }
        res = first / second;
    }
    stack.getStack().push(res);
}

void executeExpression(std::string expression, RPN& stack)
{
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
            continue;
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
                 expression[i] == '/')
            executeOperation(stack, expression[i]);
        else
        {
            double number = expression[i] - '0';
            stack.getStack().push(number);
        }
    }
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " [inverted polish mathematical expression in quotes]"
                  << std::endl;
        return 1;
    }
    if (!parseExpression(av[1]))
        return 1;
    RPN stack;
    executeExpression(av[1], stack);
    if (stack.getStack().size() != 1)
    {
        std::cerr << "Error: result should be a single number" << std::endl;
        return 1;
    }
    std::cout << stack.getStack().top() << std::endl;
}

/*
TODO:
- use exceptions
- use function ptr for operations to avoid if/elses
*/
