#include "RPN.hpp"
#include <algorithm>
#include <iostream>

void parseExpression(std::string expression)
{
    int nbOperator = 0;
    int nbOperand  = 0;
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
            expression[i] == '/')
        {
            nbOperator++;
            if (nbOperator >= nbOperand)
                throw RPN::TooMuchOperatorsException();
        }
        else if (isdigit(expression[i]))
            nbOperand++;
        else
            throw RPN::UnrecognizedTokenException();
    }
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
            throw RPN::DivisionByZeroException();
        res = first / second;
    }
    stack.getStack().push(res);
}

void executeExpression(std::string expression, RPN& stack)
{
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
            expression[i] == '/')
            executeOperation(stack, expression[i]);
        else
        {
            double number = expression[i] - '0';
            stack.getStack().push(number);
        }
    }
}

std::string removeSpaces(std::string expression)
{
    std::string res = expression;
    res.erase(std::remove(res.begin(), res.end(), ' '), res.end());
    return res;
}

int main(int ac, char** av)
{
    try
    {
        std::string expression = removeSpaces(av[1]);
        if (ac != 2 || expression.empty())
            throw RPN::UsageException();
        parseExpression(expression);
        RPN stack;
        executeExpression(expression, stack);
        if (stack.getStack().size() != 1)
            throw RPN::ResultException();
        std::cout << stack.getStack().top() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
